#include "ParserEq.h"

#include "TokenEq.h"

ParserEq::ParserEq() {}

ParserEq::~ParserEq() {}

std::unique_ptr<TokenBase> ParserEq::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenEq>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}