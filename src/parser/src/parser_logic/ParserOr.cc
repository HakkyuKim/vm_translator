#include "ParserOr.h"

#include "src/token/token_logic/TokenOr.h"

ParserOr::ParserOr() {}

ParserOr::~ParserOr() {}

std::unique_ptr<TokenBase> ParserOr::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenOr>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}