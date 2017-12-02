//
// PROJECT:         Aspia Remote Desktop
// FILE:            ui/system_info/document_creater.cc
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "base/logging.h"
#include "ui/system_info/document_creater.h"
#include "ui/system_info/document_creater_proxy.h"

namespace aspia {

DocumentCreater::DocumentCreater(CategoryList* list,
                                 Output* output,
                                 Delegate* delegate)
    : delegate_(delegate),
      list_(list),
      output_(output)
{
    DCHECK(delegate_);
    DCHECK(list_);
    DCHECK(output_);

    proxy_.reset(new DocumentCreaterProxy(this));
}

DocumentCreater::~DocumentCreater()
{
    proxy_->WillDestroyCurrentDocumentCreater();
    proxy_ = nullptr;
}

void DocumentCreater::Start(StateChangeCallback state_change_callback,
                            TerminateCallback terminate_callback)
{
    state_change_callback_ = std::move(state_change_callback);
    terminate_callback_ = std::move(terminate_callback);
    ProcessNextItem();
}

void DocumentCreater::ProcessNextItem()
{
    if (iterator_stack_.empty())
    {
        output_->StartDocument();
        iterator_stack_.emplace(list_, list_->begin());
    }

    CategoryList* list = iterator_stack_.top().first;
    CategoryList::iterator& iterator = iterator_stack_.top().second;

    if (iterator == list->end())
    {
        iterator_stack_.pop();

        if (iterator_stack_.empty())
        {
            output_->EndDocument();
            terminate_callback_();
            return;
        }

        output_->EndTableGroup();
    }
    else
    {
        Category* category = iterator->get();
        DCHECK(category);

        if (category->type() == Category::Type::INFO)
        {
            CategoryInfo* category_info = category->category_info();

            if (category_info->IsChecked())
            {
                state_change_callback_(category_info->Name(), State::REQUEST);
                delegate_->OnRequest(category_info->Guid(), proxy_);
                return;
            }
        }
        else
        {
            DCHECK(category->type() == Category::Type::GROUP);

            CategoryGroup* category_group = category->category_group();

            if (HasCheckedItems(category_group))
            {
                output_->StartTableGroup(category_group->Name());

                iterator_stack_.emplace(category_group->mutable_child_list(),
                                        category_group->mutable_child_list()->begin());
            }
        }

        ++iterator;
    }

    ProcessNextItem();
}

// static
bool DocumentCreater::HasCheckedItems(CategoryGroup* parent_group)
{
    const CategoryList& child_list = parent_group->child_list();

    for (CategoryList::const_iterator iter = child_list.cbegin();
         iter != child_list.end();
         ++iter)
    {
        Category* category = iter->get();

        if (category->type() == Category::Type::INFO)
        {
            if (category->category_info()->IsChecked())
                return true;
        }
        else
        {
            DCHECK(category->type() == Category::Type::GROUP);

            if (HasCheckedItems(category->category_group()))
                return true;
        }
    }

    return false;
}

void DocumentCreater::Parse(std::shared_ptr<std::string> data)
{
    CategoryList::iterator& iterator = iterator_stack_.top().second;

    Category* category = iterator->get();
    DCHECK(category);
    DCHECK(category->type() == Category::Type::INFO);

    state_change_callback_(category->category_info()->Name(), State::OUTPUT);

    category->category_info()->Parse(output_, *data);
    category->category_info()->SetChecked(false);

    ++iterator;

    ProcessNextItem();
}

} // namespace aspia
