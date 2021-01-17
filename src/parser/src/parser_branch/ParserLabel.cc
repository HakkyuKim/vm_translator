#include "ParserLabel.h"

#include "src/token/token_branch/TokenLabel.h"

ParserLabel::ParserLabel() {}

ParserLabel::~ParserLabel() {}

std::unique_ptr<TokenBase> ParserLabel::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenLabel>(
      OperationTypeUtil::getOperationType(stringTokens[0]), stringTokens[1]);
}