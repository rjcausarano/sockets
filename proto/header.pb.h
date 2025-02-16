// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: header.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_header_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_header_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_header_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_header_2eproto {
  static const uint32_t offsets[];
};
class Header;
struct HeaderDefaultTypeInternal;
extern HeaderDefaultTypeInternal _Header_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Header* Arena::CreateMaybeMessage<::Header>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

enum Header_Type : int {
  Header_Type_NONE = 0,
  Header_Type_ENTITY = 1,
  Header_Type_Header_Type_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  Header_Type_Header_Type_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool Header_Type_IsValid(int value);
constexpr Header_Type Header_Type_Type_MIN = Header_Type_NONE;
constexpr Header_Type Header_Type_Type_MAX = Header_Type_ENTITY;
constexpr int Header_Type_Type_ARRAYSIZE = Header_Type_Type_MAX + 1;

const std::string& Header_Type_Name(Header_Type value);
template<typename T>
inline const std::string& Header_Type_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Header_Type>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Header_Type_Name.");
  return Header_Type_Name(static_cast<Header_Type>(enum_t_value));
}
bool Header_Type_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Header_Type* value);
// ===================================================================

class Header final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:Header) */ {
 public:
  inline Header() : Header(nullptr) {}
  ~Header() override;
  explicit PROTOBUF_CONSTEXPR Header(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Header(const Header& from);
  Header(Header&& from) noexcept
    : Header() {
    *this = ::std::move(from);
  }

  inline Header& operator=(const Header& from) {
    CopyFrom(from);
    return *this;
  }
  inline Header& operator=(Header&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const Header& default_instance() {
    return *internal_default_instance();
  }
  static inline const Header* internal_default_instance() {
    return reinterpret_cast<const Header*>(
               &_Header_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Header& a, Header& b) {
    a.Swap(&b);
  }
  inline void Swap(Header* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Header* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Header* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Header>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const Header& from);
  void MergeFrom(const Header& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Header* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Header";
  }
  protected:
  explicit Header(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  typedef Header_Type Type;
  static constexpr Type NONE =
    Header_Type_NONE;
  static constexpr Type ENTITY =
    Header_Type_ENTITY;
  static inline bool Type_IsValid(int value) {
    return Header_Type_IsValid(value);
  }
  static constexpr Type Type_MIN =
    Header_Type_Type_MIN;
  static constexpr Type Type_MAX =
    Header_Type_Type_MAX;
  static constexpr int Type_ARRAYSIZE =
    Header_Type_Type_ARRAYSIZE;
  template<typename T>
  static inline const std::string& Type_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Type>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Type_Name.");
    return Header_Type_Name(enum_t_value);
  }
  static inline bool Type_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      Type* value) {
    return Header_Type_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kDataFieldNumber = 2,
    kTypeFieldNumber = 1,
  };
  // string data = 2;
  void clear_data();
  const std::string& data() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_data(ArgT0&& arg0, ArgT... args);
  std::string* mutable_data();
  PROTOBUF_NODISCARD std::string* release_data();
  void set_allocated_data(std::string* data);
  private:
  const std::string& _internal_data() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_data(const std::string& value);
  std::string* _internal_mutable_data();
  public:

  // .Header.Type type = 1;
  void clear_type();
  ::Header_Type type() const;
  void set_type(::Header_Type value);
  private:
  ::Header_Type _internal_type() const;
  void _internal_set_type(::Header_Type value);
  public:

  // @@protoc_insertion_point(class_scope:Header)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data_;
    int type_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_header_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Header

// .Header.Type type = 1;
inline void Header::clear_type() {
  _impl_.type_ = 0;
}
inline ::Header_Type Header::_internal_type() const {
  return static_cast< ::Header_Type >(_impl_.type_);
}
inline ::Header_Type Header::type() const {
  // @@protoc_insertion_point(field_get:Header.type)
  return _internal_type();
}
inline void Header::_internal_set_type(::Header_Type value) {
  
  _impl_.type_ = value;
}
inline void Header::set_type(::Header_Type value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:Header.type)
}

// string data = 2;
inline void Header::clear_data() {
  _impl_.data_.ClearToEmpty();
}
inline const std::string& Header::data() const {
  // @@protoc_insertion_point(field_get:Header.data)
  return _internal_data();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Header::set_data(ArgT0&& arg0, ArgT... args) {
 
 _impl_.data_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Header.data)
}
inline std::string* Header::mutable_data() {
  std::string* _s = _internal_mutable_data();
  // @@protoc_insertion_point(field_mutable:Header.data)
  return _s;
}
inline const std::string& Header::_internal_data() const {
  return _impl_.data_.Get();
}
inline void Header::_internal_set_data(const std::string& value) {
  
  _impl_.data_.Set(value, GetArenaForAllocation());
}
inline std::string* Header::_internal_mutable_data() {
  
  return _impl_.data_.Mutable(GetArenaForAllocation());
}
inline std::string* Header::release_data() {
  // @@protoc_insertion_point(field_release:Header.data)
  return _impl_.data_.Release();
}
inline void Header::set_allocated_data(std::string* data) {
  if (data != nullptr) {
    
  } else {
    
  }
  _impl_.data_.SetAllocated(data, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.data_.IsDefault()) {
    _impl_.data_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Header.data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Header_Type> : ::std::true_type {};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_header_2eproto
