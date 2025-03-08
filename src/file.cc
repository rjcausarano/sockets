#include "file.h"
#include <iostream>
#include <unistd.h>
#include <libgen.h>
#include <cstring>
#include <sys/stat.h>
#include <cstdio>
#include <cstdlib>
#include "file_observer.h"

File::File(const std::string& path) : path_check_enabled_{true} {
  assert_existance(path);
  char* resolvedPath = realpath(path.c_str(), nullptr);
  path_ = std::string(resolvedPath);
  free(resolvedPath);
  char c_path[256];
  strcpy(c_path, path_.c_str());
  name_ = basename(c_path);
  struct stat info;
  stat(path_.c_str(), &info);
  file_id_ = info.st_ino;
}

FilePtr File::create(const std::string& path) {
  return FilePtr(new File(path));
}

const FilePtr& File::create(const std::string& path, FileObserver& observer){
  FilePtr file = create(path);
  return observer.append(file);
}

const std::string& File::getName() {
  assert_existance(path_);
  return name_;
}

const std::string& File::getPath() {
  assert_existance(path_);
  return path_;
}

const off_t File::getSize() {
  assert_existance(path_);
  struct stat info;
  stat(path_.c_str(), &info);
  return info.st_size;
}

const mode_t File::getPermissions() {
  assert_existance(path_);
  struct stat info;
  stat(path_.c_str(), &info);
  return info.st_mode;
}

StringVec File::list() {
  assert_existance(path_);
  StringVec items;
  DIR* dir = opendir(path_.c_str());
  if(dir == nullptr){
    return items;
  }
  dirent* ent;
  while( (ent = readdir(dir)) != nullptr ){
    if((strcmp(ent->d_name, ".") != 0) && (strcmp(ent->d_name, "..") != 0)){
      items.emplace_back(ent->d_name);
    }
  }
  closedir(dir);
  return items;
}

FilePtrVec File::children() {
  assert_existance(path_);
  FilePtrVec children;
  for(std::string filename : list()){
    children.emplace_back(create(path_ + "/" + filename));
  }
  return children;
}

FilePtrVec File::siblings() {
  assert_existance(path_);
  std::string path_copy = path_;
  std::string parent_path(dirname(path_copy.data()));
  FilePtr parent = File::create(parent_path);
  FilePtrVec childrenVec = parent->children();
  childrenVec.erase(std::remove_if(childrenVec.begin(), childrenVec.end(),
    [this](const FilePtr& element){
      return element->getName() == this->getName();
    }
    ), childrenVec.end());
  return childrenVec;
}


bool File::isDir() {
  assert_existance(path_);
  struct stat info;
  stat(path_.c_str(), &info);
  return S_ISDIR(info.st_mode);
}

bool File::isEmptyDir() {
  assert_existance(path_);
  return ( isDir() && list().empty() );
}

void File::del(){
  assert_existance(path_);
  if(isDir()){
    for(std::string filename : list()){
      const std::string filepath(path_ + "/" + filename);
      File file(filepath);
      if(file.isDir()){
        if(!file.isEmptyDir()){
          file.del();
        }
      } else {  
        file.del();
      }
    }
    rmdir(path_.c_str());
  } else {
    remove(path_.c_str());
  }
}

void File::move(const std::string& path){
  assert_existance(path_);
  assert_existance(path);
  char* resolvedPath = realpath(path.c_str(), nullptr);
  std::string newPath(std::string(resolvedPath) + "/" + name_);
  free(resolvedPath);
  if((std::rename(path_.c_str(), newPath.c_str()) == 0)){
    path_ = newPath;
  } else{
    std::perror("Unable to move file");
    throw std::runtime_error("Unable to move file: " + path_);
  }
}

void File::rename(const std::string& name){
  assert_existance(path_);
  std::string pathCopy = path_;
  std::string newPath(std::string(dirname(pathCopy.data())) + "/" + name);
  if((std::rename(path_.c_str(), newPath.c_str()) == 0)){
    path_ = newPath;
    name_ = name;
  } else{
    std::perror("Unable to rename file");
    throw std::runtime_error("Unable to rename file: " + path_);
  }
}

bool File::checkRenamed(){
  path_check_enabled_ = false;
  bool modified = false;
  for(const FilePtr& file : siblings()){
    if((file->file_id_ == file_id_) && (file->name_ != name_)){
      path_ = file->getPath();
      name_ = file->getName();
      modified = true;
      break;
    }
  }
  path_check_enabled_ = true;
  assert_existance(path_);
  return modified;
}

void File::assert_existance(const std::string& path) {
  if(path_check_enabled_ && !exists(path)){
    throw std::runtime_error("Path does not exist: " + path);
  }
}

bool File::exists(const std::string& path) {
  return access(path.c_str(), F_OK) == 0;
}
