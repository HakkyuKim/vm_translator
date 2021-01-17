#include "ParserAnd.h"

#include "src/token/token_logic/TokenAnd.h"

ParserAnd::ParserAnd() {}

ParserAnd::~ParserAnd() {}

std::unique_ptr<TokenBase> ParserAnd::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenAnd>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}