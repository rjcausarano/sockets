#include "server.h"

int main(int argc, char const* argv[]){

    Server server;
    server.Listen();
    server.Close();

    return 0;
}
