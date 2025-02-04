#pragma once

#include <netinet/in.h>

#include "socket_common.h"

class Server{
public:
    Server();
    ~Server();
    void Listen();
    
private:
    int server_fd_, socket_handle_;
    int opt_{TRUE};
    struct sockaddr_in address_;
    socklen_t addrlen_;
    char buffer_[BUFFER_SIZE];
};