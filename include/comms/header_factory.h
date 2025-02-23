#pragma once

#include "header.pb.h"
#include "socket_common.h"
#include <string>

class HeaderFactory {
  public:
  template<typename T>
  static Header createHeader(T obj) {
    Header header;
    std::string serialized;
    obj.SerializeToString(&serialized);
    header.set_type(common::getClassName(obj));
    header.set_data(serialized);
    return header;
  }

  private:
  HeaderFactory(){}
};