#include "ParserGt.h"

#include "src/token/token_arithmetic/TokenGt.h"

ParserGt::ParserGt() {}

ParserGt::~ParserGt() {}

std::unique_ptr<TokenBase> ParserGt::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenGt>(
      OperationTypeUtil::getOperationType(stringTokens[0]));
}