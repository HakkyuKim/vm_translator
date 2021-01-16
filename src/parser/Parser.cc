#include "Parser.h"

#include <iostream>
#include <stdexcept>

#include "ParserAdd.h"
#include "ParserAnd.h"
#include "ParserCall.h"
#include "ParserEq.h"
#include "ParserFunction.h"
#include "ParserGoTo.h"
#include "ParserGt.h"
#include "ParserIfGoTo.h"
#include "ParserLabel.h"
#include "ParserLt.h"
#include "ParserNeg.h"
#include "ParserNot.h"
#include "ParserOr.h"
#include "ParserPop.h"
#include "ParserPush.h"
#include "ParserReturn.h"
#include "ParserSub.h"

Parser::Parser() {
  parsers_ = std::map<OperationType, std::unique_ptr<ParserBase>>{
      {OperationType::POP, std::make_unique<ParserPop>()},
      {OperationType::PUSH, std::make_unique<ParserPush>()},
      {OperationType::ADD, std::make_unique<ParserAdd>()},
      {OperationType::SUB, std::make_unique<ParserSub>()},
      {OperationType::NEG, std::make_unique<ParserNeg>()},
      {OperationType::EQ, std::make_unique<ParserEq>()},
      {OperationType::LT, std::make_unique<ParserLt>()},
      {OperationType::GT, std::make_unique<ParserGt>()},
      {OperationType::AND, std::make_unique<ParserAnd>()},
      {OperationType::OR, std::make_unique<ParserOr>()},
      {OperationType::NOT, std::make_unique<ParserNot>()},
      {OperationType::LABEL, std::make_unique<ParserLabel>()},
      {OperationType::GOTO, std::make_unique<ParserGoTo>()},
      {OperationType::IFGOTO, std::make_unique<ParserIfGoTo>()},
      {OperationType::FUNC, std::make_unique<ParserFunc>()},
      {OperationType::CALL, std::make_unique<ParserCall>()},
      {OperationType::RETURN, std::make_unique<ParserReturn>()}};
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
