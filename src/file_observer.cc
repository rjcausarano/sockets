#include "file_observer.h"
#include <iostream>
#include <unistd.h>

ObserverTask::ObserverTask(FileObserver* observer) : observer_{observer} {}

void ObserverTask::operator()(){
  while(true){
    sleep(1);

    for(FileProps& fileProps : observer_->files_){
      const FilePtr& filePtr = std::get<0>(fileProps);
      std::string& fileName = std::get<1>(fileProps);
      off_t& fileSize = std::get<2>(fileProps);
      mode_t& filePermissions = std::get<3>(fileProps);
      filePtr->checkRenamed();
      if(filePtr->getName() != fileName){
        std::string oldName = fileName;
        fileName = filePtr->getName();
        FileChangeEvent event(FileChangeEvent::Type::NAME, oldName, fileName);
        observer_->onChange_(event);
      }
      if(filePtr->getSize() != fileSize){
        off_t oldSize = fileSize;
        fileSize = filePtr->getSize();
        FileChangeEvent event(FileChangeEvent::Type::SIZE, oldSize, fileSize);
        observer_->onChange_(event);
      }
      if(filePtr->getPermissions() != filePermissions){
        mode_t oldPermissions = filePermissions;
        filePermissions = filePtr->getPermissions();
        FileChangeEvent event(FileChangeEvent::Type::PERMISSIONS, oldPermissions, filePermissions);
        observer_->onChange_(event);
      }
    }

  }
}

FileObserver::FileObserver(void (*onChange)(FileChangeEvent& event)) : onChange_{onChange} {
  observerThread_ = std::thread(ObserverTask(this));
}

const FilePtr& FileObserver::append(FilePtr& file){
  std::string name = file->getName();
  off_t size = file->getSize();
  mode_t permissions = file->getPermissions();
  files_.emplace_back(std::move(file), name, size, permissions);
  const FilePtr& ptr = std::get<0>(files_.back());
  return ptr;
}

void FileObserver::listNames(){
  for(const FileProps& file : files_){
    std::cout << std::get<1>(file) << std::endl;
  }
}
