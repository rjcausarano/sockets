#pragma once

#include "file.h"
#include <vector>

class FileObserver{
  public:
  FileObserver();
  const FilePtr& append(FilePtr&& file);
  void listNames();
  private:
  std::vector<FilePtr> files_;
};