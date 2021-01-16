#include "ParserIfGoTo.h"

#include "TokenIfGoTo.h"

ParserIfGoTo::ParserIfGoTo() {}

ParserIfGoTo::~ParserIfGoTo() {}

std::unique_ptr<TokenBase> ParserIfGoTo::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenIfGoTo>(
      OperationTypeUtil::getOperationType(stringTokens[0]), stringTokens[1]);
}