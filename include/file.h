#pragma once

#include <string>
#include <vector>
#include <memory>
#include <dirent.h>

class File;
class FileObserver;

typedef std::vector<std::string> StringVec;
typedef std::unique_ptr<File> FilePtr;
typedef std::vector<FilePtr> FilePtrVec;

class File {
public:
  static FilePtr create(const std::string& path);
  static const FilePtr& create(const std::string& path, FileObserver& observer);
  const std::string& getName();
  const std::string& getPath();
  const off_t getSize();
  const mode_t getPermissions();
  FilePtrVec children();
  FilePtrVec siblings();
  bool isDir();
  bool isEmptyDir();
  void del();
  void move(const std::string& path);
  void rename(const std::string& name);
  bool checkRenamed();
private:
  File(const File&) = delete;
  File& operator=(const File&) = delete;
  File(File&&) = delete;
  File& operator=(File&&) = delete;
  explicit File(const std::string& path);
  void assert_existance(const std::string& path);
  bool exists(const std::string& path);
  StringVec list();
  
  std::string path_;
  std::string name_;
  ino_t file_id_;
  bool path_check_enabled_;
};
