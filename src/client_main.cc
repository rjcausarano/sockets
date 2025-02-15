#include "communicator.h"
#include <string>
#include <iostream>

int main(int argc, char const* argv[])
{
  Communicator communicator;
  communicator.sendTest();

  std::string tmp;
  std::cin >> tmp;

  return 0;
}
