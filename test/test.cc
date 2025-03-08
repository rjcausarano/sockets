#include <iostream>
#include "file.h"
#include "file_observer.h"
#include "file_change_event.h"
#include <unistd.h>

void onFileChange(FileChangeEvent event){
  std::string newName;
  off_t newSize;
  mode_t newMode;

  switch(event.getType()){
    case FileChangeEvent::Type::NAME:
      newName = event.getValue<std::string>();
      std::cout << "The file name has changed to " << newName << std::endl;
      break;
    case FileChangeEvent::Type::SIZE:
      newSize = event.getValue<off_t>();
      std::cout << "The file size is now " << newSize << std::endl;
      break;
    case FileChangeEvent::Type::PERMISSIONS:
      newMode = event.getValue<mode_t>();
      std::cout << "The file permissions now is " << newMode << std::endl;
      break;
  }
}

int main(){
  FileObserver observer(onFileChange);

  const FilePtr& file1 = File::create("../testdir/file1.txt", observer);
  const FilePtr& file2 = File::create("../testdir/file2.txt", observer);
  const FilePtr& file3 = File::create("../testdir/file3.txt", observer);

  observer.listNames();

  std::string input;
  std::cin >> input;
  return 0;
}