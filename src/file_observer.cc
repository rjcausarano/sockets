#include "file_observer.h"
#include <iostream>

FileObserver::FileObserver(){}

const FilePtr& FileObserver::append(FilePtr&& file){
  files_.emplace_back(std::move(file));
  return files_.back();
}

void FileObserver::listNames(){
  for(const FilePtr& file : files_){
    std::cout << file->getName() << std::endl;
  }
}
