#ifndef __LINEREADER_H__
#define __LINEREADER_H__

#include <fstream>
#include <string>

class LineReader {
 public:
  LineReader();
  ~LineReader();
  void SetFile(std::string fileName);
  std::string ReadNextLine();
  bool IsEof();

 private:
  std::ifstream stream_;
  std::string fileName_;
};

#endif  // __LINEREADER_H__