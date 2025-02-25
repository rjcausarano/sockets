#pragma once

#include <string>
#include <vector>
#include <dirent.h>

class File;

typedef std::vector<std::string> stringvec;
typedef std::vector<File> filevec;

class File {
public:
  File(const std::string& path);
  ~File();
  std::string getName() const;
  std::string getPath() const;
  filevec children() const;
  bool isDir() const;
  bool isEmptyDir() const;
  void del();
  void move(const std::string& path);
  void rename(const std::string& name);
private:
  void assert_existance(const std::string& path) const;
  bool exists(const std::string& path) const;
  stringvec list() const;
  
  std::string path_;
  std::string name_;
};