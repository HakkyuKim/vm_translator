#include "ParserFunction.h"

#include "src/token/token_func/TokenFunction.h"

ParserFunction::ParserFunction() {}

ParserFunction::~ParserFunction() {}

std::unique_ptr<TokenBase> ParserFunction::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenFunction>(
      OperationTypeUtil::getOperationType(stringTokens[0]), stringTokens[1],
      stringTokens[2]);
}