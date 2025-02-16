#include "communicator.h"
#include <string>
#include <iostream>

int main(int argc, char const* argv[])
{
  if(argc < 2){
    std::cout << "The server IP address must be passed as argument." << std::endl;
    return 1;
  }

  Communicator communicator((std::string(argv[1])));
  communicator.sendTest();

  std::string tmp;
  std::cin >> tmp;

  return 0;
}
