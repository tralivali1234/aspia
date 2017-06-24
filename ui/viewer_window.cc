//
// PROJECT:         Aspia Remote Desktop
// FILE:            ui/viewer_window.cc
// LICENSE:         See top-level directory
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "ui/viewer_window.h"
#include "ui/power_manage_dialog.h"
#include "ui/resource.h"
#include "ui/base/module.h"
#include "base/strings/unicode.h"
#include "desktop_capture/cursor.h"
#include "proto/desktop_session_message.pb.h"

namespace aspia {

static const DWORD kKeyUpFlag = 0x80000000;
static const DWORD kKeyExtendedFlag = 0x1000000;
static const UINT kResizeFrameMessage = WM_APP + 1;

static const DesktopSize kVideoWindowSize(400, 280);

UiViewerWindow::UiViewerWindow(ClientConfig* config, Delegate* delegate) :
    config_(config),
    delegate_(delegate),
    video_window_(this)
{
    DCHECK(config_);
    DCHECK(delegate_);

    ui_thread_.Start(MessageLoop::TYPE_UI, this);
}

UiViewerWindow::~UiViewerWindow()
{
    ui_thread_.Stop();
}

void UiViewerWindow::OnBeforeThreadRunning()
{
    runner_ = ui_thread_.message_loop_proxy();
    DCHECK(runner_);

    const DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU |
        WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

    if (!Create(nullptr, style))
    {
        LOG(ERROR) << "Viewer window not created";
        runner_->PostQuit();
    }
    else
    {
        ScopedHICON icon(UiModule::Current().small_icon(IDI_MAIN));
        SetIcon(icon);
        SetCursor(LoadCursorW(nullptr, IDC_ARROW));
    }
}

void UiViewerWindow::OnAfterThreadRunning()
{
    DestroyWindow();
}

DesktopFrame* UiViewerWindow::Frame()
{
    return video_window_.Frame();
}

void UiViewerWindow::DrawFrame()
{
    video_window_.DrawFrame();
}

void UiViewerWindow::OnVideoFrameResize(WPARAM wparam, LPARAM lparam)
{
    const DesktopSize* size = reinterpret_cast<DesktopSize*>(wparam);
    const PixelFormat* format = reinterpret_cast<PixelFormat*>(lparam);

    int show_scroll_bars = -1;

    if (!size->IsEqual(video_window_.FrameSize()))
    {
        ShowScrollBar(video_window_, SB_BOTH, FALSE);
        show_scroll_bars = DoAutoSize(*size);
    }

    video_window_.ResizeFrame(*size, *format);

    if (show_scroll_bars != -1)
        ShowScrollBar(video_window_, show_scroll_bars, FALSE);
}

void UiViewerWindow::ResizeFrame(const DesktopSize& size, const PixelFormat& format)
{
    // ResizeFrame method is called from another thread.
    // We need to move the action to UI thread.
    SendMessageW(hwnd(),
                 kResizeFrameMessage,
                 reinterpret_cast<WPARAM>(&size),
                 reinterpret_cast<LPARAM>(&format));
}

void UiViewerWindow::InjectMouseCursor(std::shared_ptr<MouseCursor> mouse_cursor)
{
    if (!runner_->BelongsToCurrentThread())
    {
        runner_->PostTask(std::bind(&UiViewerWindow::InjectMouseCursor, this, mouse_cursor));
        return;
    }

    ScopedGetDC desktop_dc(nullptr);

    ScopedHCURSOR cursor(CreateHCursorFromMouseCursor(desktop_dc, *mouse_cursor));

    // If we can not get a remote cursor, then we use the default cursor.
    if (!cursor.IsValid())
    {
        SetCursor(LoadCursorW(nullptr, IDC_ARROW));
    }
    else
    {
        SetCursor(cursor);
    }
}

void UiViewerWindow::InjectClipboardEvent(std::shared_ptr<proto::ClipboardEvent> clipboard_event)
{
    if (!runner_->BelongsToCurrentThread())
    {
        runner_->PostTask(std::bind(&UiViewerWindow::InjectClipboardEvent, this, clipboard_event));
        return;
    }

    clipboard_.InjectClipboardEvent(clipboard_event);
}

void UiViewerWindow::CreateToolBar()
{
    const UiModule& module = UiModule().Current();

    toolbar_.Create(hwnd(),
                    TBSTYLE_FLAT | TBSTYLE_LIST | TBSTYLE_TOOLTIPS,
                    module.Handle());

    toolbar_.ModifyExtendedStyle(0, TBSTYLE_EX_DRAWDDARROWS |
                                    TBSTYLE_EX_MIXEDBUTTONS |
                                    TBSTYLE_EX_DOUBLEBUFFER);

    TBBUTTON kButtons[] =
    {
        // iBitmap, idCommand, fsState, fsStyle, bReserved[2], dwData, iString
        {  0, ID_POWER,      TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE,                { 0 }, 0, -1 },
        { -1, 0,             TBSTATE_ENABLED, BTNS_SEP,                                   { 0 }, 0, -1 },
        {  1, ID_CAD,        TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE,                { 0 }, 0, -1 },
        {  2, ID_SHORTCUTS,  TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE | BTNS_DROPDOWN,{ 0 }, 0, -1 },
        { -1, 0,             TBSTATE_ENABLED, BTNS_SEP,                                   { 0 }, 0, -1 },
        {  3, ID_AUTO_SIZE,  TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE,                { 0 }, 0, -1 },
        {  4, ID_FULLSCREEN, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE | BTNS_CHECK,   { 0 }, 0, -1 },
        { -1, 0,             TBSTATE_ENABLED, BTNS_SEP,                                   { 0 }, 0, -1 },
        {  5, ID_SETTINGS,   TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE,                { 0 }, 0, -1 },
        { -1, 0,             TBSTATE_ENABLED, BTNS_SEP,                                   { 0 }, 0, -1 },
        {  6, ID_ABOUT,      TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE,                { 0 }, 0, -1 },
        {  7, ID_EXIT,       TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE,                { 0 }, 0, -1 }
    };

    toolbar_.ButtonStructSize(sizeof(kButtons[0]));
    toolbar_.AddButtons(_countof(kButtons), kButtons);

    if (toolbar_imagelist_.CreateSmall())
    {
        toolbar_imagelist_.AddIcon(module, IDI_POWER);
        toolbar_imagelist_.AddIcon(module, IDI_CAD);
        toolbar_imagelist_.AddIcon(module, IDI_KEYS);
        toolbar_imagelist_.AddIcon(module, IDI_AUTOSIZE);
        toolbar_imagelist_.AddIcon(module, IDI_FULLSCREEN);
        toolbar_imagelist_.AddIcon(module, IDI_SETTINGS);
        toolbar_imagelist_.AddIcon(module, IDI_ABOUT);
        toolbar_imagelist_.AddIcon(module, IDI_EXIT);

        toolbar_.SetImageList(toolbar_imagelist_);
    }

    if (config_->session_type() == proto::SessionType::SESSION_TYPE_DESKTOP_VIEW)
    {
        toolbar_.SetButtonState(ID_POWER, 0);
        toolbar_.SetButtonState(ID_CAD, 0);
        toolbar_.SetButtonState(ID_SHORTCUTS, 0);
    }
}

void UiViewerWindow::OnCreate()
{
    std::wstring title(config_->address());

    title.append(L" - ");
    title.append(UiModule().Current().string(IDS_APPLICATION_NAME));

    SetWindowTextW(hwnd(), title.c_str());

    CreateToolBar();
    video_window_.Create(hwnd(), WS_CHILD);

    DoAutoSize(kVideoWindowSize);

    ApplyConfig(config_->desktop_session_config());
}

void UiViewerWindow::OnClose()
{
    delegate_->OnWindowClose();
}

void UiViewerWindow::OnSize()
{
    toolbar_.AutoSize();

    int toolbar_height = toolbar_.Height();

    DesktopSize size = ClientSize();

    MoveWindow(video_window_,
               0,
               toolbar_height,
               size.Width(),
               size.Height() - toolbar_height,
               TRUE);
}

void UiViewerWindow::OnGetMinMaxInfo(LPMINMAXINFO mmi)
{
    mmi->ptMinTrackSize.x = kVideoWindowSize.Width();
    mmi->ptMinTrackSize.y = kVideoWindowSize.Height();
}

static LRESULT CALLBACK KeyboardHookProc(INT code, WPARAM wParam, LPARAM lParam)
{
    if (code == HC_ACTION)
    {
        GUITHREADINFO gui_info = { 0 };

        gui_info.cbSize = sizeof(gui_info);

        if (GetGUIThreadInfo(0, &gui_info) && gui_info.hwndFocus)
        {
            PKBDLLHOOKSTRUCT hook_struct = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);

            switch (hook_struct->vkCode)
            {
                case VK_RETURN:
                case VK_TAB:
                case VK_LWIN:
                case VK_RWIN:
                {
                    // If the TAB key is pressed and ALT is not pressed.
                    if (hook_struct->vkCode == VK_TAB && !(hook_struct->flags & LLKHF_ALTDOWN))
                        break;

                    DWORD flags = 0;

                    if (hook_struct->flags & LLKHF_EXTENDED)
                    {
                        // Bit 24 set to 1 means that it's an extended key code.
                        flags |= kKeyExtendedFlag;
                    }

                    if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                    {
                        // Bit 31 set to 1 means that the key is not pressed.
                        flags |= kKeyUpFlag;
                    }

                    // Send the message to the window that is in focus.
                    SendMessageW(gui_info.hwndFocus,
                                 static_cast<UINT>(wParam),
                                 hook_struct->vkCode,
                                 flags);

                    return TRUE;
                }
                break;
            }
        }
    }

    return CallNextHookEx(nullptr, code, wParam, lParam);
}

void UiViewerWindow::OnActivate(UINT state)
{
    if (state == WA_ACTIVE || state == WA_CLICKACTIVE)
    {
        // To properly handle some key combinations, we need to set a hook
        // that will prevent the system processing these presses.
        // These combinations include Left Win, Right Win, Alt + Tab.
        keyboard_hook_.Reset(SetWindowsHookExW(WH_KEYBOARD_LL,
                                               KeyboardHookProc,
                                               GetModuleHandleW(nullptr),
                                               0));
        video_window_.HasFocus(true);
    }
    else if (state == WA_INACTIVE)
    {
        keyboard_hook_.Reset();
        video_window_.HasFocus(false);
    }
}

void UiViewerWindow::OnKeyboard(WPARAM wParam, LPARAM lParam)
{
    uint8_t key_code = static_cast<uint8_t>(static_cast<uint32_t>(wParam) & 255);

    // We do not pass CapsLock and NoLock directly. Instead, when sending each
    // keystroke event, a flag is set that indicates the status of these keys.
    if (key_code != VK_CAPITAL && key_code != VK_NUMLOCK)
    {
        uint32_t key_data = static_cast<uint32_t>(lParam);

        uint32_t flags = 0;

        flags |= ((key_data & kKeyUpFlag) == 0) ? proto::KeyEvent::PRESSED : 0;
        flags |= ((key_data & kKeyExtendedFlag) != 0) ? proto::KeyEvent::EXTENDED : 0;
        flags |= (GetKeyState(VK_CAPITAL) != 0) ? proto::KeyEvent::CAPSLOCK : 0;
        flags |= (GetKeyState(VK_NUMLOCK) != 0) ? proto::KeyEvent::NUMLOCK : 0;

        delegate_->OnKeyEvent(key_code, flags);
    }
}

void UiViewerWindow::OnSetFocus()
{
    video_window_.HasFocus(true);
}

void UiViewerWindow::OnKillFocus()
{
    video_window_.HasFocus(false);
}

void UiViewerWindow::ApplyConfig(const proto::DesktopSessionConfig& config)
{
    if (!(config.flags() & proto::DesktopSessionConfig::ENABLE_CURSOR_SHAPE))
    {
        SetCursor(LoadCursorW(nullptr, IDC_ARROW));
    }

    if (config.flags() & proto::DesktopSessionConfig::ENABLE_CLIPBOARD)
    {
        clipboard_.Start(std::bind(&UiViewerWindow::Delegate::OnClipboardEvent,
                                   delegate_,
                                   std::placeholders::_1));
    }
    else
    {
        clipboard_.Stop();
    }
}

void UiViewerWindow::OnSettingsButton()
{
    UiSettingsDialog dialog;

    if (dialog.DoModal(hwnd(),
                       config_->session_type(),
                       config_->desktop_session_config()) == IDOK)
    {
        config_->mutable_desktop_session_config()->CopyFrom(dialog.Config());

        ApplyConfig(config_->desktop_session_config());
        delegate_->OnConfigChange(config_->desktop_session_config());
    }
}

void UiViewerWindow::OnAboutButton()
{
    UiAboutDialog dialog;
    dialog.DoModal(hwnd());
}

void UiViewerWindow::OnExitButton()
{
    PostMessageW(hwnd(), WM_CLOSE, 0, 0);
}

int UiViewerWindow::DoAutoSize(const DesktopSize &video_frame_size)
{
    if (toolbar_.IsButtonChecked(ID_FULLSCREEN))
        DoFullScreen(false);

    RECT screen_rect = { 0 };

    HMONITOR monitor = MonitorFromWindow(hwnd(), MONITOR_DEFAULTTONEAREST);

    MONITORINFO info;
    info.cbSize = sizeof(info);

    if (GetMonitorInfoW(monitor, &info))
    {
        screen_rect = info.rcWork;
    }
    else
    {
        if (!SystemParametersInfoW(SPI_GETWORKAREA, 0, &screen_rect, 0))
        {
            if (!::GetClientRect(GetDesktopWindow(), &screen_rect))
                return -1;
        }
    }

    WINDOWPLACEMENT wp = { 0 };

    wp.length = sizeof(wp);

    if (!GetWindowPlacement(hwnd(), &wp))
        return -1;

    DesktopSize full_size = Size();
    DesktopSize client_size = ClientSize();
    DesktopSize toolbar_size = toolbar_.Size();

    int client_area_width = video_frame_size.Width() +
        full_size.Width() - client_size.Width();

    int client_area_height = video_frame_size.Height() +
        full_size.Height() - client_size.Height() +
        toolbar_size.Height();

    int screen_width = screen_rect.right - screen_rect.left;
    int screen_height = screen_rect.bottom - screen_rect.top;

    if (client_area_width < screen_width && client_area_height < screen_height)
    {
        if (wp.showCmd != SW_MAXIMIZE)
        {
            SetWindowPos(hwnd(),
                         nullptr,
                         (screen_width - client_area_width) / 2,
                         (screen_height - client_area_height) / 2,
                         client_area_width,
                         client_area_height,
                         SWP_NOZORDER | SWP_NOACTIVATE);
        }

        return SB_BOTH;
    }
    else
    {
        if (wp.showCmd != SW_MAXIMIZE)
            ShowWindow(hwnd(), SW_MAXIMIZE);

        if (client_area_width < screen_width)
            return SB_HORZ;
        else if (client_area_height < screen_height)
            return SB_VERT;
    }

    return -1;
}

void UiViewerWindow::OnAutoSizeButton()
{
    DesktopSize video_frame_size = video_window_.FrameSize();

    if (!video_frame_size.IsEmpty())
    {
        if (DoAutoSize(video_frame_size) != -1)
            ShowScrollBar(video_window_, SB_BOTH, FALSE);
    }
}

void UiViewerWindow::DoFullScreen(bool fullscreen)
{
    toolbar_.CheckButton(ID_FULLSCREEN, fullscreen);

    if (fullscreen)
    {
        if (GetWindowPlacement(hwnd(), &window_pos_))
        {
            RECT screen_rect = { 0 };

            HMONITOR monitor = MonitorFromWindow(hwnd(), MONITOR_DEFAULTTONEAREST);

            MONITORINFO info;
            info.cbSize = sizeof(info);

            if (GetMonitorInfoW(monitor, &info))
            {
                screen_rect = info.rcMonitor;
            }
            else
            {
                if (!GetWindowRect(GetDesktopWindow(), &screen_rect))
                    return;
            }

            ModifyStyle(WS_CAPTION | WS_BORDER | WS_THICKFRAME | WS_MAXIMIZEBOX, WS_MAXIMIZE);
            ModifyStyleEx(0, WS_EX_TOPMOST);

            SetWindowPos(hwnd(),
                         nullptr,
                         screen_rect.left,
                         screen_rect.top,
                         screen_rect.right - screen_rect.left,
                         screen_rect.bottom - screen_rect.top,
                         SWP_SHOWWINDOW);
        }
    }
    else
    {
        ModifyStyle(WS_MAXIMIZE, WS_CAPTION | WS_BORDER | WS_THICKFRAME | WS_MAXIMIZEBOX);
        ModifyStyleEx(WS_EX_TOPMOST, 0);

        SetWindowPlacement(hwnd(), &window_pos_);
    }
}

void UiViewerWindow::OnFullScreenButton()
{
    DoFullScreen(toolbar_.IsButtonChecked(ID_FULLSCREEN));
}

void UiViewerWindow::OnDropDownButton(WORD ctrl_id)
{
    RECT rc = { 0 };
    toolbar_.GetRect(ctrl_id, rc);
    ShowDropDownMenu(ctrl_id, &rc);
}

void UiViewerWindow::OnPowerButton()
{
    UiPowerManageDialog dialog;

    proto::PowerEvent::Action action =
        static_cast<proto::PowerEvent::Action>(dialog.DoModal(hwnd()));

    if (action != proto::PowerEvent::UNKNOWN)
        delegate_->OnPowerEvent(action);
}

void UiViewerWindow::OnCADButton()
{
    delegate_->OnKeyEvent(VK_CONTROL, proto::KeyEvent::PRESSED);
    delegate_->OnKeyEvent(VK_MENU, proto::KeyEvent::PRESSED);
    delegate_->OnKeyEvent(VK_DELETE, proto::KeyEvent::EXTENDED | proto::KeyEvent::PRESSED);

    delegate_->OnKeyEvent(VK_CONTROL, 0);
    delegate_->OnKeyEvent(VK_MENU, 0);
    delegate_->OnKeyEvent(VK_DELETE, proto::KeyEvent::EXTENDED);
}

void UiViewerWindow::OnKeyButton(WORD ctrl_id)
{
    switch (ctrl_id)
    {
        case ID_KEY_CTRL_ESC:
        {
            delegate_->OnKeyEvent(VK_CONTROL, proto::KeyEvent::PRESSED);
            delegate_->OnKeyEvent(VK_ESCAPE, proto::KeyEvent::PRESSED);

            delegate_->OnKeyEvent(VK_CONTROL, 0);
            delegate_->OnKeyEvent(VK_ESCAPE, 0);
        }
        break;

        case ID_KEY_ALT_TAB:
        {
            delegate_->OnKeyEvent(VK_MENU, proto::KeyEvent::PRESSED);
            delegate_->OnKeyEvent(VK_TAB, proto::KeyEvent::PRESSED);

            delegate_->OnKeyEvent(VK_TAB, 0);
            delegate_->OnKeyEvent(VK_MENU, 0);
        }
        break;

        case ID_KEY_ALT_SHIFT_TAB:
        {
            delegate_->OnKeyEvent(VK_MENU, proto::KeyEvent::PRESSED);
            delegate_->OnKeyEvent(VK_SHIFT, proto::KeyEvent::PRESSED);
            delegate_->OnKeyEvent(VK_TAB, proto::KeyEvent::PRESSED);

            delegate_->OnKeyEvent(VK_TAB, 0);
            delegate_->OnKeyEvent(VK_SHIFT, 0);
            delegate_->OnKeyEvent(VK_MENU, 0);
        }
        break;

        case ID_KEY_PRINTSCREEN:
        {
            delegate_->OnKeyEvent(VK_SNAPSHOT, proto::KeyEvent::PRESSED);
            delegate_->OnKeyEvent(VK_SNAPSHOT, 0);
        }
        break;

        case ID_KEY_ALT_PRINTSCREEN:
        {
            delegate_->OnKeyEvent(VK_MENU, proto::KeyEvent::PRESSED);
            delegate_->OnKeyEvent(VK_SNAPSHOT, proto::KeyEvent::PRESSED);

            delegate_->OnKeyEvent(VK_SNAPSHOT, 0);
            delegate_->OnKeyEvent(VK_MENU, 0);
        }
        break;

        case ID_KEY_CTRL_ALT_F12:
        {
            delegate_->OnKeyEvent(VK_CONTROL, proto::KeyEvent::PRESSED);
            delegate_->OnKeyEvent(VK_MENU, proto::KeyEvent::PRESSED);
            delegate_->OnKeyEvent(VK_F12, proto::KeyEvent::PRESSED);

            delegate_->OnKeyEvent(VK_F12, 0);
            delegate_->OnKeyEvent(VK_MENU, 0);
            delegate_->OnKeyEvent(VK_CONTROL, 0);
        }
        break;

        case ID_KEY_F12:
        {
            delegate_->OnKeyEvent(VK_F12, proto::KeyEvent::PRESSED);
            delegate_->OnKeyEvent(VK_F12, 0);
        }
        break;

        case ID_KEY_CTRL_F12:
        {
            delegate_->OnKeyEvent(VK_CONTROL, proto::KeyEvent::PRESSED);
            delegate_->OnKeyEvent(VK_F12, proto::KeyEvent::PRESSED);

            delegate_->OnKeyEvent(VK_F12, 0);
            delegate_->OnKeyEvent(VK_CONTROL, 0);
        }
        break;
    }
}

void UiViewerWindow::OnGetDispInfo(LPNMHDR phdr)
{
    LPTOOLTIPTEXTW header = reinterpret_cast<LPTOOLTIPTEXTW>(phdr);
    UINT string_id;

    switch (header->hdr.idFrom)
    {
        case ID_POWER:
            string_id = IDS_POWER;
            break;

        case ID_ABOUT:
            string_id = IDS_ABOUT;
            break;

        case ID_AUTO_SIZE:
            string_id = IDS_AUTO_SIZE;
            break;

        case ID_FULLSCREEN:
            string_id = IDS_FULLSCREEN;
            break;

        case ID_EXIT:
            string_id = IDS_EXIT;
            break;

        case ID_CAD:
            string_id = IDS_CAD;
            break;

        case ID_SHORTCUTS:
            string_id = IDS_SHORTCUTS;
            break;

        case ID_SETTINGS:
            string_id = IDS_SETTINGS;
            break;

        default:
            return;
    }

    LoadStringW(UiModule().Current().Handle(),
                string_id,
                header->szText,
                _countof(header->szText));
}

void UiViewerWindow::OnToolBarDropDown(LPNMHDR phdr)
{
    LPNMTOOLBARW header = reinterpret_cast<LPNMTOOLBARW>(phdr);
    ShowDropDownMenu(header->iItem, &header->rcButton);
}

void UiViewerWindow::ShowDropDownMenu(int button_id, RECT* button_rect)
{
    if (button_id != ID_SHORTCUTS)
        return;

    if (MapWindowPoints(toolbar_, HWND_DESKTOP, reinterpret_cast<LPPOINT>(button_rect), 2))
    {
        TPMPARAMS tpm;
        tpm.cbSize = sizeof(TPMPARAMS);
        tpm.rcExclude = *button_rect;

        ScopedHMENU menu(UiModule().Current().menu(IDR_SHORTCUTS));

        TrackPopupMenuEx(GetSubMenu(menu, 0),
                         TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_VERTICAL,
                         button_rect->left,
                         button_rect->bottom,
                         hwnd(),
                         &tpm);
    }
}

bool UiViewerWindow::OnMessage(UINT msg, WPARAM wparam, LPARAM lparam, LRESULT* result)
{
    switch (msg)
    {
        case WM_CREATE:
            OnCreate();
            break;

        case WM_KEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP:
            OnKeyboard(wparam, lparam);
            break;

        case WM_CHAR:
        case WM_SYSCHAR:
        case WM_DEADCHAR:
        case WM_SYSDEADCHAR:
            break;

        case WM_MOUSEWHEEL:
            video_window_.OnMouse(msg, wparam, lparam);
            break;

        case WM_SIZE:
            OnSize();
            break;

        case WM_GETMINMAXINFO:
            OnGetMinMaxInfo(reinterpret_cast<LPMINMAXINFO>(lparam));
            break;

        case WM_ACTIVATE:
            OnActivate(LOWORD(wparam));
            break;

        case WM_SETFOCUS:
            OnSetFocus();
            break;

        case WM_KILLFOCUS:
            OnKillFocus();
            break;

        case WM_NOTIFY:
        {
            LPNMHDR header = reinterpret_cast<LPNMHDR>(lparam);

            switch (header->code)
            {
                case TTN_GETDISPINFO:
                    OnGetDispInfo(header);
                    break;

                case TBN_DROPDOWN:
                    OnToolBarDropDown(header);
                    break;
            }
        }
        break;

        case WM_COMMAND:
        {
            switch (LOWORD(wparam))
            {
                case ID_SETTINGS:
                    OnSettingsButton();
                    break;

                case ID_ABOUT:
                    OnAboutButton();
                    break;

                case ID_EXIT:
                    OnExitButton();
                    break;

                case ID_AUTO_SIZE:
                    OnAutoSizeButton();
                    break;

                case ID_FULLSCREEN:
                    OnFullScreenButton();
                    break;

                case ID_SHORTCUTS:
                    OnDropDownButton(LOWORD(wparam));
                    break;

                case ID_CAD:
                    OnCADButton();
                    break;

                case ID_KEY_CTRL_ESC:
                case ID_KEY_ALT_TAB:
                case ID_KEY_ALT_SHIFT_TAB:
                case ID_KEY_PRINTSCREEN:
                case ID_KEY_ALT_PRINTSCREEN:
                case ID_KEY_CTRL_ALT_F12:
                case ID_KEY_F12:
                case ID_KEY_CTRL_F12:
                    OnKeyButton(LOWORD(wparam));
                    break;

                case ID_POWER:
                    OnPowerButton();
                    break;
            }
        }
        break;

        case WM_CLOSE:
            OnClose();
            break;

        case WM_DESTROY:
        {
            toolbar_.DestroyWindow();
            video_window_.DestroyWindow();
        }
        break;

        case kResizeFrameMessage:
            OnVideoFrameResize(wparam, lparam);
            break;

        default:
            return false;
    }

    *result = 0;
    return true;
}

void UiViewerWindow::OnPointerEvent(const DesktopPoint& pos, uint32_t mask)
{
    delegate_->OnPointerEvent(pos, mask);
}

} // namespace aspia
