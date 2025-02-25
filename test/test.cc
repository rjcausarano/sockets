#include <iostream>
#include "file.h"
#include <sys/inotify.h>

int main(){
  File file("./renamed.txt");
  std::cout << "The file path is: " << file.getPath() << std::endl;
  std::cout << "The file name is: " << file.getName() << std::endl;
  file.move("..");
  std::cout << "The file path is: " << file.getPath() << std::endl;
  std::cout << "The file name is: " << file.getName() << std::endl;
  return 0;
}