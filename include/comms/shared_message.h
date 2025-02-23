#pragma once

#include <mutex>
#include <stack>
#include <string>

class SharedMessage {
  public:
  void setMessage(const std::string& message);
  const std::string getMessage();
  bool hasMessage();

  private:
  std::stack<std::string> messages_;
  std::mutex mtx;
};