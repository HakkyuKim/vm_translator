#include "ParserNeg.h"

#include "src/token/token_arithmetic/TokenNeg.h"

ParserNeg::ParserNeg() {}

ParserNeg::~ParserNeg() {}

std::unique_ptr<TokenBase> ParserNeg::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenNeg>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}