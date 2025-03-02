#include <iostream>
#include "file.h"
#include "file_observer.h"

int main(){
  FileObserver observer;
  const FilePtr& file1 = File::create("../testdir/file1.txt", observer);
  const FilePtr& file2 = File::create("../testdir/file2.txt", observer);
  const FilePtr& file3 = File::create("../testdir/file3.txt", observer);

  observer.listNames();
  return 0;
}