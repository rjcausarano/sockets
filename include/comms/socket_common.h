#pragma once

#include <string>
#include <typeinfo>
#include <cxxabi.h>

#define PROTOCOL 0
#define PORT 54321
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

namespace common {
  template<typename T>
  std::string getClassName(){
    int status;
    return std::string(abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, &status));
  }

  template<typename T>
  std::string getClassName(T obj){
    return getClassName<T>();
  }
};