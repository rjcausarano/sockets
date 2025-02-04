#include <stdio.h>
#include <stdlib.h>

#include "client.h"

int main(int argc, char const* argv[])
{
    if(argc != 2){
        perror("Need to specify the IP address of the server");
        exit(EXIT_FAILURE);
    }

    Client client(argv[1]);
    client.Connect();
    client.Send("I");
    client.Send("am");
    client.Send("short");
    client.Send("First message");
    client.Send("Second");
    client.Send("Hello World");
    client.Close();

    return 0;
}
