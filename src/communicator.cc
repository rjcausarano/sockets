#include "communicator.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#include "client.h"
#include "header_factory.h"

class SocketThread{
  public:
  void operator()(SharedMessage& shared_message){
    Client client("0.0.0.0");
    client.Connect();
    while(true){
      if(shared_message.hasMessage()){
        const std::string message = shared_message.getMessage();
        std::string response = client.Send(message.c_str());
        std::cout << response << std::endl;
      }
      sleep(1);
    }
  }
};

Communicator::Communicator(){
  SocketThread socket_thread;
  coms_thread_ = std::thread(socket_thread, std::ref(shared_message_));
}

void Communicator::sendTest(){
  Header header = HeaderFactory::createHeader(Header::NONE, "Hello World");
  std::string serialized;
  if(header.SerializeToString(&serialized)){
    shared_message_.setMessage(serialized);
  } else {
    std::cout << "Unable to serialize header to string" << std::endl;
  }
}
