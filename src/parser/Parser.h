#ifndef __PARSER_H__
#define __PARSER_H__

#include <map>
#include <memory>
#include <vector>

#include "LineReader.h"
#include "ParseResult.h"
#include "src/parser/src/ParserBase.h"
#include "src/type/OperationType.h"

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
  std::map<OperationType, std::shared_ptr<ParserBase>> parsers_;
};

#endif  // __PARSER_H__