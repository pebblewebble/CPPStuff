#include <fstream>
#include <string>
#include <iostream>
namespace eric {
class files {
private:
  std::fstream fileOutput;

public:
  files(std::string fileName) {
    fileOutput.open(fileName, std::ios::in);
    if (!fileOutput.is_open()) {
      std::cout << "File could not open." << std::endl;
    }
  }
  ~files() {
    if(fileOutput.is_open()){
      fileOutput.close();
    }
  }
  string[] recordsToArray(){

  }
};
} // namespace eric
