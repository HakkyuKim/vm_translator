#include "ParserOr.h"

#include "TokenOr.h"

ParserOr::ParserOr() {}

ParserOr::~ParserOr() {}

std::unique_ptr<TokenBase> ParserOr::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenOr>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}