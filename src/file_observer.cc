#include "file_observer.h"
#include <iostream>
#include <unistd.h>

ObserverTask::ObserverTask(FileObserver* observer) : observer_{observer} {}

void ObserverTask::operator()(){
  while(true){
    sleep(1);
    observer_->observe();
  }
}

FileObserver::FileObserver(void (*onChange)(FileChangeEvent event)) : onChange_{onChange} {
  observerThread_ = std::thread(ObserverTask(this));
}

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
      fileName = filePtr->getName();
      FileChangeEvent event(FileChangeEvent::Type::NAME, &fileName);
      onChange_(event);
    }
    if(filePtr->getSize() != fileSize){
      fileSize = filePtr->getSize();
      FileChangeEvent event(FileChangeEvent::Type::SIZE, &fileSize);
      onChange_(event);
    }
    if(filePtr->getPermissions() != filePermissions){
      filePermissions = filePtr->getPermissions();
      FileChangeEvent event(FileChangeEvent::Type::PERMISSIONS, &filePermissions);
      onChange_(event);
    }
  }
}

void FileObserver::listNames(){
  for(const FileProps& file : files_){
    std::cout << std::get<1>(file) << std::endl;
  }
}
