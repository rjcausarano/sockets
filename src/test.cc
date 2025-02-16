#include <iostream>
#include "comms/entity.pb.h"
#include "comms/header.pb.h"
#include "comms/header_factory.h"
#include <string>

int main(int argc, char const* argv[]){
    
    Entity file;
    file.set_type(Entity::FILE);
    file.set_name("test_file_name");

    Entity dir;
    dir.set_type(Entity::DIRECTORY);
    dir.set_name("test_dir_name");
    *(dir.add_entities()) = file;

    std::string serialized_data;
    dir.SerializeToString(&serialized_data);
    Header header = HeaderFactory::createHeader(Header::COMMAND, serialized_data);

    std::string serialized_header;
    header.SerializeToString(&serialized_header);

    // I am now at the server end

    Header server_header;
    server_header.ParseFromString(serialized_header);

    if(server_header.type() == Header::COMMAND){
        Entity server_dir;
        server_dir.ParseFromString(server_header.data());

        std::cout << "The folder name is: "<< server_dir.name() << std::endl;
        std::cout << "The containing file name is: "<< server_dir.entities(0).name() << std::endl;
    }

    return 0;
}
