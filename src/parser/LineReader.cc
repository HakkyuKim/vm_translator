#include "LineReader.h"
#include <iostream>

LineReader::LineReader() {}

LineReader::~LineReader() {}

void LineReader::SetFile(std::string fileName) { fileName_ = fileName; }

std::string LineReader::ReadNextLine() {
  if(!stream_.is_open()){
    stream_.open(fileName_);
    if(stream_.fail()){
      throw std::logic_error("Error: failed to open file " + fileName_ + "\n");
    }
  }
  std::string line;
  while (stream_.good()) {
    char c = stream_.get();
    if (c == '\n' || c == EOF) {
      std::cout << line << "\n";
      return line;
    }
    line.push_back(c);
  }
  std::cout << line;
  return line;
}

bool LineReader::IsEof() { return stream_.eof(); }
