#pragma once 

template <class T>
Container<T>::Container(T value) : value_{value} {}

template <class T>
T Container<T>::get() {
  return value_;
}

template <class T>
void Container<T>::set(T value){
  value_ = value;
}
