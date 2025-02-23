#include "command_processor.h"
#include "comms/socket_common.h"

CommandProcessor::CommandProcessor() : HeaderProcessor() {}

Header CommandProcessor::process(std::string type, std::string data) const {
  Header responseHeader;
  responseHeader.set_type(common::getClassName<std::string>());
  responseHeader.set_data("successfully parsed! We are now inside command processor.");
  return responseHeader;
}
