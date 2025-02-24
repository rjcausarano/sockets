#include "comms/communicator.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "comms/header_factory.h"
#include "comms/entity.pb.h"

Communicator::Communicator(const std::string& ip) : client_{ip.c_str()} {
  client_.Connect();
}

Entity Communicator::getDirTree(const std::string& path) {
  EntityRequest req;
  req.set_path(path);
  Header respHeader = sendHeader(HeaderFactory::createHeader(req));
  Entity entity;
  entity.ParseFromString(respHeader.data());
  return entity;
}

Header Communicator::sendHeader(Header header){
  std::string serialized;
  header.SerializeToString(&serialized);
  std::string strResponse = client_.Send(serialized.c_str());
  Header respHeader;
  respHeader.ParseFromString(strResponse);
  return respHeader;
}

// Communicator::Communicator(const std::string& ip, SocketThread* socket_thread){
//   coms_thread_ = std::thread(std::ref(*socket_thread), ip, std::ref(shared_message_));
// }

// void Communicator::sendTest(){
//   Entity entity;
//   Header header = HeaderFactory::createHeader(entity);
//   std::string serialized;
//   if(header.SerializeToString(&serialized)){
//     shared_message_.setMessage(serialized);
//   } else {
//     std::cout << "Unable to serialize header to string" << std::endl;
//   }
// }
