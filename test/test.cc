#include <iostream>
#include "file.h"
#include "file_observer.h"

void onFileChange(std::string message){
  std::cout << "Received message: " << message << std::endl;
}

int main(){
  FileObserver observer(onFileChange);
  
  const FilePtr& file1 = File::create("../testdir/file1.txt", observer);
  const FilePtr& file2 = File::create("../testdir/file2.txt", observer);
  const FilePtr& file3 = File::create("../testdir/file3.txt", observer);

  observer.listNames();

  return 0;
}