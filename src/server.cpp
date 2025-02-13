#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string>

#include "server.h"

Server::Server() : buffer_{0} {
    addrlen_ = sizeof(address_);

    if ((server_fd_ = socket(AF_INET, SOCK_STREAM, PROTOCOL)) < 0){
        perror("Error creating the server socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd_, SOL_SOCKET,
                   SO_REUSEADDR, &opt_,
                   sizeof(opt_))) {
        perror("error setting setsockopt SO_REUSEADDR");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd_, SOL_SOCKET,
                   SO_REUSEPORT, &opt_,
                   sizeof(opt_))) {
        perror("error setting setsockopt SO_REUSEPORT");
        exit(EXIT_FAILURE);
    }

    address_.sin_family = AF_INET;
    address_.sin_addr.s_addr = INADDR_ANY;
    address_.sin_port = htons(PORT);
    if (bind(server_fd_, (struct sockaddr*)&address_,
             sizeof(address_))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd_, 3) < 0) {
        perror("error in listen function");
        exit(EXIT_FAILURE);
    }
}

void Server::Listen(){
    if ((socket_handle_ = accept(server_fd_, (struct sockaddr*)&address_, &addrlen_))) {
        ssize_t bytes;
        while((bytes = read(socket_handle_, buffer_, BUFFER_SIZE - 1))){
            printf("%s\n", buffer_);
            std::string msg(buffer_);
            std::string response;
            if(msg == "Hello"){
                response = "Hey there";
            } else if(msg == "quit"){
                return;
            } else {
                response = "I didn't understand your message";
            }
            send(socket_handle_, response.c_str(), response.size() + 1, 0);
        }
    } else {
        perror("error accepting connection");
        exit(EXIT_FAILURE);
    }
}

Server::~Server(){
    close(socket_handle_);
    close(server_fd_);
}