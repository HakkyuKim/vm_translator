#include <map>
#include <memory>
#include <vector>

#include "LineReader.h"
#include "OperationType.h"
#include "ParseResult.h"
#include "ParserBase.h"

class Parser {
 public:
  Parser();
  void SetFile(std::string fileName);
  std::string GetFileName();
  ParseResult ParseNextLine();
  bool IsEof();

 private:
  std::vector<std::string> SplitBySpace(std::string line);
  LineReader lineReader_;
  std::string fileName_;
  std::map<OperationType, std::unique_ptr<ParserBase>> parsers_;
};
