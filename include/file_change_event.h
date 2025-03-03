#pragma once

class FileChangeEvent {
  public:
  enum class Type {
    NAME,
    SIZE,
    PERMISSIONS
  };

  template<typename T>
  FileChangeEvent(Type type, T* value) : type_{type} {
    new_value_ = static_cast<void*>(value);
  }

  Type getType() {
    return type_;
  }

  template<typename T>
  T& getValue(){
    return *static_cast<T*>(new_value_);
  }

  private:
  Type type_;
  void* new_value_;
};