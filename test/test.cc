#include <iostream>
#include "file.h"
#include "file_observer.h"
#include "file_change_event.h"
#include <unistd.h>

void onFileChange(FileChangeEvent& event){
  std::string newName;
  std::string oldName;
  off_t newSize;
  off_t oldSize;
  mode_t newMode;
  mode_t oldMode;

  switch(event.getType()){
    case FileChangeEvent::Type::NAME:
      newName = event.getNewValue<std::string>();
      oldName = event.getOldValue<std::string>();
      std::cout << "The file name has changed from " << oldName << " to " << newName << std::endl;
      break;
    case FileChangeEvent::Type::SIZE:
      newSize = event.getNewValue<off_t>();
      oldSize = event.getOldValue<off_t>();
      std::cout << "The file size changed from " << oldSize << " to " << newSize << std::endl;
      break;
    case FileChangeEvent::Type::PERMISSIONS:
      newMode = event.getNewValue<mode_t>();
      oldMode = event.getOldValue<mode_t>();
      std::cout << "The file permissions changed from " << oldMode << " to " << newMode << std::endl;
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