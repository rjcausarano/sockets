#pragma once

#include "container.h"
#include <memory>

class FileChangeEvent {
  public:
  enum class Type {
    NAME,
    SIZE,
    PERMISSIONS
  };
  
  template<typename T>
  FileChangeEvent(Type type, T& old_value, T& new_value);

  Type getType();

  template<typename T>
  T getNewValue();

  template<typename T>
  T getOldValue();

  private:
  Type type_;
  std::unique_ptr<ContainerBase> new_value_;
  std::unique_ptr<ContainerBase> old_value_;
};

#include "file_change_event.ipp"
