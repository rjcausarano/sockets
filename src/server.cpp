#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PROTOCOL 0
#define PORT 8080
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0
 
int main(int argc, char const* argv[]){
    int server_fd, socket_handle;
    int opt = TRUE;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = { 0 };

    // TODO: Change to AF_LOCAL for inter process communication
    if ((server_fd = socket(AF_INET, SOCK_STREAM, PROTOCOL)) < 0){
        perror("Error creating the server socket");
        exit(EXIT_FAILURE);
    }
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR, &opt,
                   sizeof(opt))) {
        perror("error setting setsockopt SO_REUSEADDR");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("error setting setsockopt SO_REUSEPORT");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("error in listen function");
        exit(EXIT_FAILURE);
    }

    // Wait for a connection and send a message to it
    if ((socket_handle = accept(server_fd, (struct sockaddr*)&address, &addrlen))) {
        ssize_t bytes = read(socket_handle, buffer, BUFFER_SIZE - 1);
        printf("%s\n", buffer);
        const char* hello = "Hello from server";
        send(socket_handle, hello, strlen(hello), 0);
    } else {
        perror("error accepting connection");
        exit(EXIT_FAILURE);
    }

    printf("exiting the program...\n");
    // closing the connected socket
    close(socket_handle);
    // closing the listening socket
    close(server_fd);
    return 0;
}
