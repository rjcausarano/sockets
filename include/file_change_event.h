#pragma once

class FileChangeEvent {
  public:
  enum class Type {
    NAME,
    SIZE,
    PERMISSIONS
  };
  
  template<typename T>
  FileChangeEvent(Type type, T* value);

  Type getType();

  template<typename T>
  T& getValue();

  private:
  Type type_;
  void* new_value_;
};

#include "file_change_event.ipp"
