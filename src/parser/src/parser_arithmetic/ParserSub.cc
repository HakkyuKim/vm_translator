#include "ParserSub.h"

#include "src/token/token_arithmetic/TokenSub.h"

ParserSub::ParserSub() {}

ParserSub::~ParserSub() {}

std::unique_ptr<TokenBase> ParserSub::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenSub>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}