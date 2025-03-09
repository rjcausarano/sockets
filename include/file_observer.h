#pragma once

#include "file.h"
#include "file_change_event.h"
#include <list>
#include <tuple>
#include <string>
#include <thread>

typedef std::tuple<FilePtr, std::string, off_t, mode_t> FileProps;
typedef std::list<FileProps> FilePropsArray;

class ObserverTask{
  public:
  ObserverTask(FileObserver* observer);
  void operator()();
  private:
  FileObserver* observer_;
};

class FileObserver{
  public:
  friend class ObserverTask;
  FileObserver(void (*onChange)(FileChangeEvent& event));
  const FilePtr& append(FilePtr& file);
  void listNames();
  private:
  FilePropsArray files_;
  void (*onChange_)(FileChangeEvent& event);
  std::thread observerThread_;
};