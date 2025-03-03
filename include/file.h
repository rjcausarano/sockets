#pragma once

#include <string>
#include <vector>
#include <memory>
#include <dirent.h>

class File;
class FileObserver;

typedef std::vector<std::string> stringvec;
typedef std::unique_ptr<File> FilePtr;
typedef std::vector<FilePtr> filevec;

class File {
public:
  static FilePtr create(const std::string& path);
  static const FilePtr& create(const std::string& path, FileObserver& observer);
  const std::string& getName() const;
  const std::string& getPath() const;
  const off_t getSize() const;
  const mode_t getPermissions() const;
  filevec children() const;
  bool isDir() const;
  bool isEmptyDir() const;
  void del();
  void move(const std::string& path);
  void rename(const std::string& name);
private:
  File(const File&) = delete;
  File& operator=(const File&) = delete;
  File(File&&) = delete;
  File& operator=(File&&) = delete;
  explicit File(const std::string& path);
  void assert_existance(const std::string& path) const;
  bool exists(const std::string& path) const;
  stringvec list() const;
  
  std::string path_;
  std::string name_;
};
