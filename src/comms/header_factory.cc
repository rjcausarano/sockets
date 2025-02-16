#include "comms/header_factory.h"

Header HeaderFactory::createHeader(Header::Type type, std::string data){
    Header header;
    header.set_type(type);
    header.set_data(data);
    return header;
}