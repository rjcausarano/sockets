#pragma once

#include "header.pb.h"
#include <string>

class HeaderProcessor {
  public:
    virtual Header process(std::string type, std::string data) const = 0;
};