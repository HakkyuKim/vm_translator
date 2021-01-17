#include "ParserNot.h"

#include "src/token/token_logic/TokenNot.h"

ParserNot::ParserNot() {}

ParserNot::~ParserNot() {}

std::unique_ptr<TokenBase> ParserNot::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenNot>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}