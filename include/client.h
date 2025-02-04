#pragma once

#include <arpa/inet.h>

#include "socket_common.h"

class Client{
public:
    Client(const char * server_ip);
    ~Client();
    void Connect();
    void Send(const char* msg);

private:
    int client_fd_;
    struct sockaddr_in serv_addr_;
    char buffer_[BUFFER_SIZE];
};