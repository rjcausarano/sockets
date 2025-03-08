
template<typename T>
FileChangeEvent::FileChangeEvent(Type type, T* value) : type_{type} {
  new_value_ = static_cast<void*>(value);
}

template<typename T>
T& FileChangeEvent::getValue(){
  return *static_cast<T*>(new_value_);
}
