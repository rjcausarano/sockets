#pragma once

#include "shared_message.h"
#include <thread>
#include <string>

class SocketThread{
  public:
  virtual void operator()(const std::string& ip, SharedMessage& shared_message) = 0;
};

class Communicator {
  public:
  Communicator(const std::string& ip, SocketThread* socket_thread);
  void sendTest();
  private:
  std::thread coms_thread_;
  SharedMessage shared_message_;
};
