#include <iostream>
#include "comms/entity.pb.h"
#include "comms/header.pb.h"
#include "comms/header_factory.h"
#include <string>
#include "comms/socket_common.h"

int main(int argc, char const* argv[]){
  Entity entity;
  std::cout << "Passing an instance object:" << common::getClassName(entity) << std::endl;
  std::cout << "Passing a class name:" << common::getClassName<Entity>() << std::endl;
  return 0;
}
