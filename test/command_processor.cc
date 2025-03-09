#include "command_processor.h"
#include "comms/socket_common.h"
#include "comms/entity.pb.h"
#include "entity_processor.h"
#include "comms/header_factory.h"

CommandProcessor::CommandProcessor() : HeaderProcessor() {}

Header CommandProcessor::process(std::string type, std::string data) const {
  Header responseHeader;
  if(type == common::getClassName<EntityChildrenRequest>()){
    EntityChildrenRequest req;
    req.ParseFromString(data);
    FilePtr file = File::create(req.path());
    EntityProcessor processor(file);
    Entity entity = processor.getEntity();
    responseHeader = HeaderFactory::createHeader(entity);
  }
  return responseHeader;
}
