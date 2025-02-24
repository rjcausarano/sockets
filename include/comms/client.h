#pragma once

#include <arpa/inet.h>
#include "socket_common.h"
#include <string>

class Client{
public:
    Client();
    ~Client();
    void Connect(const char * server_ip);
    std::string Send(const char* msg);

private:
    int client_fd_;
    struct sockaddr_in serv_addr_;
    char buffer_[BUFFER_SIZE];
};