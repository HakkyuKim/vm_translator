#include "ParserAdd.h"

#include "src/token/token_arithmetic/TokenAdd.h"

ParserAdd::ParserAdd() {}

ParserAdd::~ParserAdd() {}

std::unique_ptr<TokenBase> ParserAdd::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenAdd>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}