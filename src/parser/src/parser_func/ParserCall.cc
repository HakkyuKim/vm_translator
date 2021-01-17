#include "ParserCall.h"

#include "src/token/token_func/TokenCall.h"

ParserCall::ParserCall() {}

ParserCall::~ParserCall() {}

std::unique_ptr<TokenBase> ParserCall::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenCall>(
      OperationTypeUtil::getOperationType(stringTokens[0]), stringTokens[1],
      stringTokens[2]);
}