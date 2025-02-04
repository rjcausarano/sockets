#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "client.h"

Client::Client(const char * server_ip) : buffer_{0} {
    if ((client_fd_ = socket(AF_INET, SOCK_STREAM, PROTOCOL)) < 0) {
        perror("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }

    serv_addr_.sin_family = AF_INET;
    serv_addr_.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, server_ip, &serv_addr_.sin_addr)
        <= 0) {
        perror("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }
}

void Client::Connect(){
    if (connect(client_fd_, (struct sockaddr*)&serv_addr_, sizeof(serv_addr_)) < 0) {
        perror("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }
}

void Client::Send(const char* msg){
    send(client_fd_, msg, strlen(msg), 0);
    ssize_t bytes = read(client_fd_, buffer_, BUFFER_SIZE - 1);
    buffer_[bytes] = '\0';
    printf("%s\n", buffer_);
}

Client::~Client(){
    printf("Client destructor called\n");
    close(client_fd_);
}
