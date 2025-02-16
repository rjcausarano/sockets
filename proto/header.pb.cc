// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: header.proto
// Protobuf C++ Version: 5.29.3

#include "header.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;

inline constexpr Header::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : data_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        type_{static_cast< ::Header_Type >(0)},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Header::Header(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct HeaderDefaultTypeInternal {
  PROTOBUF_CONSTEXPR HeaderDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~HeaderDefaultTypeInternal() {}
  union {
    Header _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 HeaderDefaultTypeInternal _Header_default_instance_;
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_header_2eproto[2];
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_header_2eproto = nullptr;
const ::uint32_t
    TableStruct_header_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::Header, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Header, _impl_.type_),
        PROTOBUF_FIELD_OFFSET(::Header, _impl_.data_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::Header)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_Header_default_instance_._instance,
};
const char descriptor_table_protodef_header_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\014header.proto\"\206\001\n\006Header\022\032\n\004type\030\001 \001(\0162"
    "\014.Header.Type\022\014\n\004data\030\002 \001(\t\".\n\004Type\022\013\n\007C"
    "OMMAND\020\000\022\013\n\007REQUEST\020\001\022\014\n\010RESPONSE\020\002\"\"\n\010D"
    "ataType\022\n\n\006STRING\020\000\022\n\n\006ENTITY\020\001b\006proto3"
};
static ::absl::once_flag descriptor_table_header_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_header_2eproto = {
    false,
    false,
    159,
    descriptor_table_protodef_header_2eproto,
    "header.proto",
    &descriptor_table_header_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_header_2eproto::offsets,
    file_level_enum_descriptors_header_2eproto,
    file_level_service_descriptors_header_2eproto,
};
const ::google::protobuf::EnumDescriptor* Header_Type_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_header_2eproto);
  return file_level_enum_descriptors_header_2eproto[0];
}
PROTOBUF_CONSTINIT const uint32_t Header_Type_internal_data_[] = {
    196608u, 0u, };
bool Header_Type_IsValid(int value) {
  return 0 <= value && value <= 2;
}
#if (__cplusplus < 201703) && \
  (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

constexpr Header_Type Header::COMMAND;
constexpr Header_Type Header::REQUEST;
constexpr Header_Type Header::RESPONSE;
constexpr Header_Type Header::Type_MIN;
constexpr Header_Type Header::Type_MAX;
constexpr int Header::Type_ARRAYSIZE;

#endif  // (__cplusplus < 201703) &&
        // (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
const ::google::protobuf::EnumDescriptor* Header_DataType_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_header_2eproto);
  return file_level_enum_descriptors_header_2eproto[1];
}
PROTOBUF_CONSTINIT const uint32_t Header_DataType_internal_data_[] = {
    131072u, 0u, };
bool Header_DataType_IsValid(int value) {
  return 0 <= value && value <= 1;
}
#if (__cplusplus < 201703) && \
  (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

constexpr Header_DataType Header::STRING;
constexpr Header_DataType Header::ENTITY;
constexpr Header_DataType Header::DataType_MIN;
constexpr Header_DataType Header::DataType_MAX;
constexpr int Header::DataType_ARRAYSIZE;

#endif  // (__cplusplus < 201703) &&
        // (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
// ===================================================================

class Header::_Internal {
 public:
};

Header::Header(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Header)
}
inline PROTOBUF_NDEBUG_INLINE Header::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::Header& from_msg)
      : data_(arena, from.data_),
        _cached_size_{0} {}

Header::Header(
    ::google::protobuf::Arena* arena,
    const Header& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  Header* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  _impl_.type_ = from._impl_.type_;

  // @@protoc_insertion_point(copy_constructor:Header)
}
inline PROTOBUF_NDEBUG_INLINE Header::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : data_(arena),
        _cached_size_{0} {}

inline void Header::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.type_ = {};
}
Header::~Header() {
  // @@protoc_insertion_point(destructor:Header)
  SharedDtor(*this);
}
inline void Header::SharedDtor(MessageLite& self) {
  Header& this_ = static_cast<Header&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.data_.Destroy();
  this_._impl_.~Impl_();
}

inline void* Header::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) Header(arena);
}
constexpr auto Header::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(Header),
                                            alignof(Header));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull Header::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_Header_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &Header::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<Header>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &Header::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<Header>(), &Header::ByteSizeLong,
            &Header::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(Header, _impl_._cached_size_),
        false,
    },
    &Header::kDescriptorMethods,
    &descriptor_table_header_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* Header::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 19, 2> Header::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Header>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string data = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(Header, _impl_.data_)}},
    // .Header.Type type = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Header, _impl_.type_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(Header, _impl_.type_)}},
  }}, {{
    65535, 65535
  }}, {{
    // .Header.Type type = 1;
    {PROTOBUF_FIELD_OFFSET(Header, _impl_.type_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kOpenEnum)},
    // string data = 2;
    {PROTOBUF_FIELD_OFFSET(Header, _impl_.data_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\6\0\4\0\0\0\0\0"
    "Header"
    "data"
  }},
};

PROTOBUF_NOINLINE void Header::Clear() {
// @@protoc_insertion_point(message_clear_start:Header)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.data_.ClearToEmpty();
  _impl_.type_ = 0;
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* Header::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const Header& this_ = static_cast<const Header&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* Header::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const Header& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:Header)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // .Header.Type type = 1;
          if (this_._internal_type() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteEnumToArray(
                1, this_._internal_type(), target);
          }

          // string data = 2;
          if (!this_._internal_data().empty()) {
            const std::string& _s = this_._internal_data();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Header.data");
            target = stream->WriteStringMaybeAliased(2, _s, target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:Header)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t Header::ByteSizeLong(const MessageLite& base) {
          const Header& this_ = static_cast<const Header&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t Header::ByteSizeLong() const {
          const Header& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:Header)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // string data = 2;
            if (!this_._internal_data().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_data());
            }
            // .Header.Type type = 1;
            if (this_._internal_type() != 0) {
              total_size += 1 +
                            ::_pbi::WireFormatLite::EnumSize(this_._internal_type());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void Header::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Header*>(&to_msg);
  auto& from = static_cast<const Header&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Header)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_data().empty()) {
    _this->_internal_set_data(from._internal_data());
  }
  if (from._internal_type() != 0) {
    _this->_impl_.type_ = from._impl_.type_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Header::CopyFrom(const Header& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Header)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Header::InternalSwap(Header* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.data_, &other->_impl_.data_, arena);
  swap(_impl_.type_, other->_impl_.type_);
}

::google::protobuf::Metadata Header::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_header_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
