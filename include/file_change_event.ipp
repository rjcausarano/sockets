#pragma once

template<typename T>
FileChangeEvent::FileChangeEvent(Type type, T& old_value, T& new_value) : type_{type} {
  new_value_ = std::make_unique<Container<T>>(new_value);
  old_value_ = std::make_unique<Container<T>>(old_value);
}

template<typename T>
T FileChangeEvent::getNewValue(){
  std::unique_ptr<Container<T>> new_value_ptr(static_cast<Container<T>*>(new_value_.release()));
  return (*new_value_ptr).get();
}

template<typename T>
T FileChangeEvent::getOldValue(){
  std::unique_ptr<Container<T>> old_value_ptr(static_cast<Container<T>*>(old_value_.release()));
  return (*old_value_ptr).get();
}
