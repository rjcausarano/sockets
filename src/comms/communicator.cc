#include "comms/communicator.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "comms/client.h"
#include "comms/header_factory.h"
#include "comms/entity.pb.h"
#include "comms/header.pb.h"

Communicator::Communicator(const std::string& ip, SocketThread* socket_thread){
  coms_thread_ = std::thread(std::ref(*socket_thread), ip, std::ref(shared_message_));
}

void Communicator::sendTest(){
  Entity entity;
  Header header = HeaderFactory::createHeader(entity);
  std::string serialized;
  if(header.SerializeToString(&serialized)){
    shared_message_.setMessage(serialized);
  } else {
    std::cout << "Unable to serialize header to string" << std::endl;
  }
}
