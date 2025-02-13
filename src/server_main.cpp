#include "server.h"
#include "../proto/person.pb.h"

int main(int argc, char const* argv[]){

    Server server;
    server.Listen();

    // sockets::Person person;
    // person.set_name("RodriC");
    // person.set_id(32);
    // person.set_email("rjcausarano@gmail.com");
    // std::string binary_data;
    // person.SerializeToString(&binary_data);
    // printf("object serialized: %s \n", binary_data.c_str());

    return 0;
}
