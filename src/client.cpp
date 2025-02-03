#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PROTOCOL 0
#define PORT 8080
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char const* argv[])
{
    int client_fd;
    struct sockaddr_in serv_addr;
    const char* hello = "Hello from client";
    char buffer[BUFFER_SIZE] = { 0 };
    if ((client_fd = socket(AF_INET, SOCK_STREAM, PROTOCOL)) < 0) {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    if (connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }

    send(client_fd, hello, strlen(hello), 0);
    ssize_t bytes = read(client_fd, buffer, BUFFER_SIZE - 1);
    printf("%s\n", buffer);

    // closing the connected socket
    close(client_fd);
    return 0;
}
