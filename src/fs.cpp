#include "./fs.h"
#include <fstream>
#include <string>

std::string FS::readFile(std::string fileName) {
  std::string output = "";
  std::ifstream fileStream(fileName);
  std::string line;

  while (std::getline(fileStream, line)) {
    output += line + "\n";
  }

  return output;
}