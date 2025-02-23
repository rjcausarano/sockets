#include "comms/shared_message.h"

void SharedMessage::setMessage(const std::string& message){
  mtx.lock();
  messages_.push(message);
  mtx.unlock();
}

const std::string SharedMessage::getMessage(){
  std::string return_value;
  mtx.lock();
  return_value = messages_.top();
  messages_.pop();
  mtx.unlock();
  return return_value;
}

bool SharedMessage::hasMessage(){
  bool isEmpty;
  mtx.lock();
  isEmpty = messages_.empty();
  mtx.unlock();
  return !isEmpty;
}
