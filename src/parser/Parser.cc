#include "Parser.h"

#include <iostream>
#include <stdexcept>

#include "src/parser_arithmetic/ParserAdd.h"
#include "src/parser_arithmetic/ParserEq.h"
#include "src/parser_arithmetic/ParserGt.h"
#include "src/parser_arithmetic/ParserLt.h"
#include "src/parser_arithmetic/ParserNeg.h"
#include "src/parser_arithmetic/ParserSub.h"
#include "src/parser_branch/ParserGoTo.h"
#include "src/parser_branch/ParserIfGoTo.h"
#include "src/parser_branch/ParserLabel.h"
#include "src/parser_func/ParserCall.h"
#include "src/parser_func/ParserFunction.h"
#include "src/parser_func/ParserReturn.h"
#include "src/parser_logic/ParserAnd.h"
#include "src/parser_logic/ParserNot.h"
#include "src/parser_logic/ParserOr.h"
#include "src/parser_memory/ParserPop.h"
#include "src/parser_memory/ParserPush.h"

Parser::Parser() {
  parsers_ = std::map<OperationType, std::shared_ptr<ParserBase>>{
      {OperationType::POP, std::make_shared<ParserPop>()},
      {OperationType::PUSH, std::make_shared<ParserPush>()},
      {OperationType::ADD, std::make_shared<ParserAdd>()},
      {OperationType::SUB, std::make_shared<ParserSub>()},
      {OperationType::NEG, std::make_shared<ParserNeg>()},
      {OperationType::EQ, std::make_shared<ParserEq>()},
      {OperationType::LT, std::make_shared<ParserLt>()},
      {OperationType::GT, std::make_shared<ParserGt>()},
      {OperationType::AND, std::make_shared<ParserAnd>()},
      {OperationType::OR, std::make_shared<ParserOr>()},
      {OperationType::NOT, std::make_shared<ParserNot>()},
      {OperationType::LABEL, std::make_shared<ParserLabel>()},
      {OperationType::GOTO, std::make_shared<ParserGoTo>()},
      {OperationType::IFGOTO, std::make_shared<ParserIfGoTo>()},
      {OperationType::FUNC, std::make_shared<ParserFunction>()},
      {OperationType::CALL, std::make_shared<ParserCall>()},
      {OperationType::RETURN, std::make_shared<ParserReturn>()}};
}

void Parser::SetFile(std::string fileName) {
  fileName_ = fileName;
  lineReader_.SetFile(fileName);
}

std::string Parser::GetFileName() { return fileName_; }

bool Parser::IsEof() { return lineReader_.IsEof(); }

ParseResult Parser::ParseNextLine() {
  std::vector<std::string> tokenStrings =
      SplitBySpace(lineReader_.ReadNextLine());
  if (tokenStrings.empty()) {
    return ParseResult(true, ParseType::WHITESPACE, nullptr);
  }
  if (tokenStrings[0] == "//") {
    return ParseResult(true, ParseType::COMMENT, nullptr);
  };

  OperationType operationType =
      OperationTypeUtil::getOperationType(tokenStrings[0]);
  return ParseResult(true, ParseType::CODE,
                     parsers_[operationType]->parse(tokenStrings));
}

std::vector<std::string> Parser::SplitBySpace(std::string line) {
  std::string token;
  std::vector<std::string> tokens;
  for (char c : line) {
    if (c == ' ') {
      if (!token.empty()) {
        tokens.push_back(token);
      }
      token.clear();
      continue;
    }
    token.push_back(c);
  }
  if (!token.empty()) {
    tokens.push_back(token);
  }
  return tokens;
}
