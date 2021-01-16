#include "LineReader.h"

LineReader::LineReader() {}

LineReader::~LineReader() { stream_.clear(); }

void LineReader::SetFile(std::string fileName) { fileName_ = fileName; }

std::string LineReader::ReadNextLine() {
  std::string line;
  while (stream_.good()) {
    char c = stream_.get();
    if (c == '\n' || c == EOF) {
      return line;
    }
    line.push_back(c);
  }
  return line;
}

bool LineReader::IsEof() { return stream_.eof(); }
