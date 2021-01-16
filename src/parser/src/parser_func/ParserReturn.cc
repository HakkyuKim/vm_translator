#include "ParserReturn.h"

#include "TokenReturn.h"

ParserReturn::ParserReturn() {}

ParserReturn::~ParserReturn() {}

std::unique_ptr<TokenBase> ParserReturn::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenReturn>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}