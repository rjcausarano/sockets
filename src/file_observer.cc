#include "file_observer.h"
#include <iostream>

FileObserver::FileObserver(void (*onChange)(std::string message)) : onChange_{onChange} {}

const FilePtr& FileObserver::append(FilePtr&& file){
  files_.emplace_back(std::move(file), file->getName(), file->getSize(), file->getPermissions());
  return std::get<0>(files_.back());
}

void FileObserver::observe(){
  for(FileProps& fileProps : files_){
    const FilePtr& filePtr = std::get<0>(fileProps);
    std::string& fileName = std::get<1>(fileProps);
    off_t& fileSize = std::get<2>(fileProps);
    mode_t& filePermissions = std::get<3>(fileProps);
    if(filePtr->getName() != fileName){
      onChange_("File name has changed!");
      fileName = filePtr->getName();
    }
    if(filePtr->getSize() != fileSize){
      onChange_("File size has changed!");
      fileSize = filePtr->getSize();
    }
    if(filePtr->getPermissions() != filePermissions){
      onChange_("File permissions has changed!");
      filePermissions = filePtr->getPermissions();
    }
  }
}

void FileObserver::listNames(){
  for(const FileProps& file : files_){
    std::cout << std::get<1>(file) << std::endl;
  }
}
