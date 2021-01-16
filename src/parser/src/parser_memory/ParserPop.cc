#include "ParserPop.h"

#include "SegmentType.h"
#include "TokenPop.h"

ParserPop::ParserPop() {}

ParserPop::~ParserPop() {}

std::unique_ptr<TokenBase> ParserPop::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenPop>(
      OperationTypeUtil::getOperationType(stringTokens[0]),
      SegmentTypeUtil::getSegmentType(stringTokens[1]), stringTokens[2]);
}