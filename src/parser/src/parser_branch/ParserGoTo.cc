#include "ParserGoTo.h"

#include "src/token/token_branch/TokenGoTo.h"

ParserGoTo::ParserGoTo() {}

ParserGoTo::~ParserGoTo() {}

std::unique_ptr<TokenBase> ParserGoTo::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenGoTo>(
      OperationTypeUtil::getOperationType(stringTokens[0]), stringTokens[1]);
}