#include "ParserPop.h"

#include "src/token/token_memory/TokenPop.h"
#include "src/type/SegmentType.h"

ParserPop::ParserPop() {}

ParserPop::~ParserPop() {}

std::unique_ptr<TokenBase> ParserPop::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenPop>(
      OperationTypeUtil::getOperationType(stringTokens[0]),
      SegmentTypeUtil::getSegmentType(stringTokens[1]), stringTokens[2]);
}