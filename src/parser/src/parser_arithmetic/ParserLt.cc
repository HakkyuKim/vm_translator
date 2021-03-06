#include "ParserLt.h"

#include "src/token/token_arithmetic/TokenLt.h"

ParserLt::ParserLt() {}

ParserLt::~ParserLt() {}

std::unique_ptr<TokenBase> ParserLt::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenLt>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}