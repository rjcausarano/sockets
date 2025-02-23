#pragma once

#include <netinet/in.h>

#include "socket_common.h"
#include "header.pb.h"
#include "header_processor.h"

class Server{
public:
  Server() = delete;
  Server(HeaderProcessor* processor);
  ~Server();
  void listenToClient();
    
private:
  int server_fd_, socket_handle_;
  int opt_{TRUE};
  struct sockaddr_in address_;
  socklen_t addrlen_;
  char buffer_[BUFFER_SIZE];
  HeaderProcessor* processor_;
};