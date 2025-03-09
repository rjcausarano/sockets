#pragma once

class ContainerBase {

};

template <class T>
class Container : public ContainerBase {
  public:
  Container(T value);
  T get();
  void set(T value);
  private:
  T value_;
};

#include "container.ipp"
