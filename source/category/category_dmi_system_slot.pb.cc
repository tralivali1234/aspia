// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: category_dmi_system_slot.proto

#include "category_dmi_system_slot.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace aspia {
namespace proto {
class DmiSystemSlot_ItemDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<DmiSystemSlot_Item>
      _instance;
} _DmiSystemSlot_Item_default_instance_;
class DmiSystemSlotDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<DmiSystemSlot>
      _instance;
} _DmiSystemSlot_default_instance_;
}  // namespace proto
}  // namespace aspia
namespace protobuf_category_5fdmi_5fsystem_5fslot_2eproto {
void InitDefaultsDmiSystemSlot_ItemImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::aspia::proto::_DmiSystemSlot_Item_default_instance_;
    new (ptr) ::aspia::proto::DmiSystemSlot_Item();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::aspia::proto::DmiSystemSlot_Item::InitAsDefaultInstance();
}

void InitDefaultsDmiSystemSlot_Item() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsDmiSystemSlot_ItemImpl);
}

void InitDefaultsDmiSystemSlotImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_category_5fdmi_5fsystem_5fslot_2eproto::InitDefaultsDmiSystemSlot_Item();
  {
    void* ptr = &::aspia::proto::_DmiSystemSlot_default_instance_;
    new (ptr) ::aspia::proto::DmiSystemSlot();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::aspia::proto::DmiSystemSlot::InitAsDefaultInstance();
}

void InitDefaultsDmiSystemSlot() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsDmiSystemSlotImpl);
}

}  // namespace protobuf_category_5fdmi_5fsystem_5fslot_2eproto
namespace aspia {
namespace proto {
bool DmiSystemSlot_Type_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const DmiSystemSlot_Type DmiSystemSlot::TYPE_UNKNOWN;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_OTHER;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_ISA;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_MCA;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_EISA;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PC_CARD;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_VLB;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PROPRIETARY;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PROCESSOR_CARD;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PROPRIETARY_MEMORY_CARD;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_IO_RISER_CARD;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_NUBUS;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_66;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_AGP;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_AGP_2X;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_AGP_4X;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_X;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_AGP_8X;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_M2_SOCKET_1DP;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_M2_SOCKET_1SD;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_M2_SOCKET_2;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_M2_SOCKET_3;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_MXM_TYPE_I;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_MXM_TYPE_II;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_MXM_TYPE_III;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_MXM_TYPE_III_HE;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_MXM_TYPE_IV;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_MXM_30_TYPE_A;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_MXM_30_TYPE_B;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_2_SFF_8639;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_3_SFF_8639;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_MINI_52PIN_WITH_BOTTOM_SIDE;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_MINI_52PIN;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_MINI_76PIN;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PC98_C20;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PC98_C24;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PC98_E;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PC98_LOCAL_BUS;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PC98_CARD;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_X1;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_X2;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_X4;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_X8;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_X16;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_2;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_2_X1;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_2_X2;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_2_X4;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_2_X8;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_2_X16;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_3;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_3_X1;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_3_X2;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_3_X4;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_3_X8;
const DmiSystemSlot_Type DmiSystemSlot::TYPE_PCI_EXPRESS_3_X16;
const DmiSystemSlot_Type DmiSystemSlot::Type_MIN;
const DmiSystemSlot_Type DmiSystemSlot::Type_MAX;
const int DmiSystemSlot::Type_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900
bool DmiSystemSlot_Usage_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const DmiSystemSlot_Usage DmiSystemSlot::USAGE_UNKNOWN;
const DmiSystemSlot_Usage DmiSystemSlot::USAGE_OTHER;
const DmiSystemSlot_Usage DmiSystemSlot::USAGE_AVAILABLE;
const DmiSystemSlot_Usage DmiSystemSlot::USAGE_IN_USE;
const DmiSystemSlot_Usage DmiSystemSlot::Usage_MIN;
const DmiSystemSlot_Usage DmiSystemSlot::Usage_MAX;
const int DmiSystemSlot::Usage_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900
bool DmiSystemSlot_BusWidth_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_UNKNOWN;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_OTHER;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_8_BIT;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_16_BIT;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_32_BIT;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_64_BIT;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_128_BIT;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_X1;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_X2;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_X4;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_X8;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_X12;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_X16;
const DmiSystemSlot_BusWidth DmiSystemSlot::BUS_WIDTH_X32;
const DmiSystemSlot_BusWidth DmiSystemSlot::BusWidth_MIN;
const DmiSystemSlot_BusWidth DmiSystemSlot::BusWidth_MAX;
const int DmiSystemSlot::BusWidth_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900
bool DmiSystemSlot_Length_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const DmiSystemSlot_Length DmiSystemSlot::LENGTH_UNKNOWN;
const DmiSystemSlot_Length DmiSystemSlot::LENGTH_OTHER;
const DmiSystemSlot_Length DmiSystemSlot::LENGTH_SHORT;
const DmiSystemSlot_Length DmiSystemSlot::LENGTH_LONG;
const DmiSystemSlot_Length DmiSystemSlot::Length_MIN;
const DmiSystemSlot_Length DmiSystemSlot::Length_MAX;
const int DmiSystemSlot::Length_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

// ===================================================================

void DmiSystemSlot_Item::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int DmiSystemSlot_Item::kSlotDesignationFieldNumber;
const int DmiSystemSlot_Item::kTypeFieldNumber;
const int DmiSystemSlot_Item::kUsageFieldNumber;
const int DmiSystemSlot_Item::kBusWidthFieldNumber;
const int DmiSystemSlot_Item::kLengthFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

DmiSystemSlot_Item::DmiSystemSlot_Item()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_category_5fdmi_5fsystem_5fslot_2eproto::InitDefaultsDmiSystemSlot_Item();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:aspia.proto.DmiSystemSlot.Item)
}
DmiSystemSlot_Item::DmiSystemSlot_Item(const DmiSystemSlot_Item& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  slot_designation_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.slot_designation().size() > 0) {
    slot_designation_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.slot_designation_);
  }
  ::memcpy(&type_, &from.type_,
    static_cast<size_t>(reinterpret_cast<char*>(&length_) -
    reinterpret_cast<char*>(&type_)) + sizeof(length_));
  // @@protoc_insertion_point(copy_constructor:aspia.proto.DmiSystemSlot.Item)
}

void DmiSystemSlot_Item::SharedCtor() {
  slot_designation_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&type_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&length_) -
      reinterpret_cast<char*>(&type_)) + sizeof(length_));
  _cached_size_ = 0;
}

DmiSystemSlot_Item::~DmiSystemSlot_Item() {
  // @@protoc_insertion_point(destructor:aspia.proto.DmiSystemSlot.Item)
  SharedDtor();
}

void DmiSystemSlot_Item::SharedDtor() {
  slot_designation_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void DmiSystemSlot_Item::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const DmiSystemSlot_Item& DmiSystemSlot_Item::default_instance() {
  ::protobuf_category_5fdmi_5fsystem_5fslot_2eproto::InitDefaultsDmiSystemSlot_Item();
  return *internal_default_instance();
}

DmiSystemSlot_Item* DmiSystemSlot_Item::New(::google::protobuf::Arena* arena) const {
  DmiSystemSlot_Item* n = new DmiSystemSlot_Item;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void DmiSystemSlot_Item::Clear() {
// @@protoc_insertion_point(message_clear_start:aspia.proto.DmiSystemSlot.Item)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  slot_designation_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&type_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&length_) -
      reinterpret_cast<char*>(&type_)) + sizeof(length_));
  _internal_metadata_.Clear();
}

bool DmiSystemSlot_Item::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:aspia.proto.DmiSystemSlot.Item)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string slot_designation = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_slot_designation()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->slot_designation().data(), static_cast<int>(this->slot_designation().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "aspia.proto.DmiSystemSlot.Item.slot_designation"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .aspia.proto.DmiSystemSlot.Type type = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_type(static_cast< ::aspia::proto::DmiSystemSlot_Type >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .aspia.proto.DmiSystemSlot.Usage usage = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_usage(static_cast< ::aspia::proto::DmiSystemSlot_Usage >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .aspia.proto.DmiSystemSlot.BusWidth bus_width = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_bus_width(static_cast< ::aspia::proto::DmiSystemSlot_BusWidth >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .aspia.proto.DmiSystemSlot.Length length = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_length(static_cast< ::aspia::proto::DmiSystemSlot_Length >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:aspia.proto.DmiSystemSlot.Item)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:aspia.proto.DmiSystemSlot.Item)
  return false;
#undef DO_
}

void DmiSystemSlot_Item::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:aspia.proto.DmiSystemSlot.Item)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string slot_designation = 1;
  if (this->slot_designation().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->slot_designation().data(), static_cast<int>(this->slot_designation().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aspia.proto.DmiSystemSlot.Item.slot_designation");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->slot_designation(), output);
  }

  // .aspia.proto.DmiSystemSlot.Type type = 2;
  if (this->type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->type(), output);
  }

  // .aspia.proto.DmiSystemSlot.Usage usage = 3;
  if (this->usage() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->usage(), output);
  }

  // .aspia.proto.DmiSystemSlot.BusWidth bus_width = 4;
  if (this->bus_width() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      4, this->bus_width(), output);
  }

  // .aspia.proto.DmiSystemSlot.Length length = 5;
  if (this->length() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      5, this->length(), output);
  }

  output->WriteRaw((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).data(),
                   static_cast<int>((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size()));
  // @@protoc_insertion_point(serialize_end:aspia.proto.DmiSystemSlot.Item)
}

size_t DmiSystemSlot_Item::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:aspia.proto.DmiSystemSlot.Item)
  size_t total_size = 0;

  total_size += (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size();

  // string slot_designation = 1;
  if (this->slot_designation().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->slot_designation());
  }

  // .aspia.proto.DmiSystemSlot.Type type = 2;
  if (this->type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
  }

  // .aspia.proto.DmiSystemSlot.Usage usage = 3;
  if (this->usage() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->usage());
  }

  // .aspia.proto.DmiSystemSlot.BusWidth bus_width = 4;
  if (this->bus_width() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->bus_width());
  }

  // .aspia.proto.DmiSystemSlot.Length length = 5;
  if (this->length() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->length());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void DmiSystemSlot_Item::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const DmiSystemSlot_Item*>(&from));
}

void DmiSystemSlot_Item::MergeFrom(const DmiSystemSlot_Item& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:aspia.proto.DmiSystemSlot.Item)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.slot_designation().size() > 0) {

    slot_designation_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.slot_designation_);
  }
  if (from.type() != 0) {
    set_type(from.type());
  }
  if (from.usage() != 0) {
    set_usage(from.usage());
  }
  if (from.bus_width() != 0) {
    set_bus_width(from.bus_width());
  }
  if (from.length() != 0) {
    set_length(from.length());
  }
}

void DmiSystemSlot_Item::CopyFrom(const DmiSystemSlot_Item& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:aspia.proto.DmiSystemSlot.Item)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DmiSystemSlot_Item::IsInitialized() const {
  return true;
}

void DmiSystemSlot_Item::Swap(DmiSystemSlot_Item* other) {
  if (other == this) return;
  InternalSwap(other);
}
void DmiSystemSlot_Item::InternalSwap(DmiSystemSlot_Item* other) {
  using std::swap;
  slot_designation_.Swap(&other->slot_designation_);
  swap(type_, other->type_);
  swap(usage_, other->usage_);
  swap(bus_width_, other->bus_width_);
  swap(length_, other->length_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string DmiSystemSlot_Item::GetTypeName() const {
  return "aspia.proto.DmiSystemSlot.Item";
}


// ===================================================================

void DmiSystemSlot::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int DmiSystemSlot::kItemFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

DmiSystemSlot::DmiSystemSlot()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_category_5fdmi_5fsystem_5fslot_2eproto::InitDefaultsDmiSystemSlot();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:aspia.proto.DmiSystemSlot)
}
DmiSystemSlot::DmiSystemSlot(const DmiSystemSlot& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      item_(from.item_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:aspia.proto.DmiSystemSlot)
}

void DmiSystemSlot::SharedCtor() {
  _cached_size_ = 0;
}

DmiSystemSlot::~DmiSystemSlot() {
  // @@protoc_insertion_point(destructor:aspia.proto.DmiSystemSlot)
  SharedDtor();
}

void DmiSystemSlot::SharedDtor() {
}

void DmiSystemSlot::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const DmiSystemSlot& DmiSystemSlot::default_instance() {
  ::protobuf_category_5fdmi_5fsystem_5fslot_2eproto::InitDefaultsDmiSystemSlot();
  return *internal_default_instance();
}

DmiSystemSlot* DmiSystemSlot::New(::google::protobuf::Arena* arena) const {
  DmiSystemSlot* n = new DmiSystemSlot;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void DmiSystemSlot::Clear() {
// @@protoc_insertion_point(message_clear_start:aspia.proto.DmiSystemSlot)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  item_.Clear();
  _internal_metadata_.Clear();
}

bool DmiSystemSlot::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:aspia.proto.DmiSystemSlot)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .aspia.proto.DmiSystemSlot.Item item = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_item()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:aspia.proto.DmiSystemSlot)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:aspia.proto.DmiSystemSlot)
  return false;
#undef DO_
}

void DmiSystemSlot::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:aspia.proto.DmiSystemSlot)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .aspia.proto.DmiSystemSlot.Item item = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->item_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, this->item(static_cast<int>(i)), output);
  }

  output->WriteRaw((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).data(),
                   static_cast<int>((::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size()));
  // @@protoc_insertion_point(serialize_end:aspia.proto.DmiSystemSlot)
}

size_t DmiSystemSlot::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:aspia.proto.DmiSystemSlot)
  size_t total_size = 0;

  total_size += (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()).size();

  // repeated .aspia.proto.DmiSystemSlot.Item item = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->item_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->item(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void DmiSystemSlot::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const DmiSystemSlot*>(&from));
}

void DmiSystemSlot::MergeFrom(const DmiSystemSlot& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:aspia.proto.DmiSystemSlot)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  item_.MergeFrom(from.item_);
}

void DmiSystemSlot::CopyFrom(const DmiSystemSlot& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:aspia.proto.DmiSystemSlot)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DmiSystemSlot::IsInitialized() const {
  return true;
}

void DmiSystemSlot::Swap(DmiSystemSlot* other) {
  if (other == this) return;
  InternalSwap(other);
}
void DmiSystemSlot::InternalSwap(DmiSystemSlot* other) {
  using std::swap;
  item_.InternalSwap(&other->item_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string DmiSystemSlot::GetTypeName() const {
  return "aspia.proto.DmiSystemSlot";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace aspia

// @@protoc_insertion_point(global_scope)