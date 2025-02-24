#pragma once

#include "shared_message.h"
#include <thread>
#include <string>
#include "comms/client.h"
#include "comms/entity.pb.h"

class SocketThread{
  public:
  virtual void operator()(const std::string& ip, SharedMessage& shared_message) = 0;
};

class Communicator {
  public:
  Communicator(const std::string& ip);
  Entity getDirTree(const std::string& path);
  // async constructor
  // Communicator(const std::string& ip, SocketThread* socket_thread);
  // async send test
  // void sendTest();
  private:
  Client client_;
  // async properties
  // std::thread coms_thread_;
  // SharedMessage shared_message_;
};
