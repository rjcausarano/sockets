#pragma once

#include "file.h"
#include <list>
#include <tuple>
#include <string>

typedef std::tuple<FilePtr, std::string, off_t, mode_t> FileProps;
typedef std::list<FileProps> FilePropsArray;

class FileObserver{
  public:
  FileObserver(void (*onChange)(std::string message));
  const FilePtr& append(FilePtr&& file);
  void listNames();
  void observe();
  private:
  FilePropsArray files_;
  void (*onChange_)(std::string message);
};