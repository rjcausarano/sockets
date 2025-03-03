#include "file_observer.h"
#include <iostream>

FileObserver::FileObserver(void (*onChange)(std::string message)) : onChange_{onChange} {}

const FilePtr& FileObserver::append(FilePtr&& file){
  files_.emplace_back(std::move(file), file->getName(), file->getSize(), file->getPermissions());
  return std::get<0>(files_.back());
}

void FileObserver::listNames(){
  for(const FileProps& file : files_){
    std::cout << std::get<1>(file) << std::endl;
  }
  onChange_("Hello there");
}
