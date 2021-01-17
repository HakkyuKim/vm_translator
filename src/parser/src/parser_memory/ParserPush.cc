#include "ParserPush.h"

#include "src/token/token_memory/TokenPush.h"
#include "src/type/SegmentType.h"

ParserPush::ParserPush() {}

ParserPush::~ParserPush() {}

std::unique_ptr<TokenBase> ParserPush::parse(
    std::vector<std::string> stringTokens) {
  return std::make_unique<TokenPush>(
      OperationTypeUtil::getOperationType(stringTokens[0]),
      SegmentTypeUtil::getSegmentType(stringTokens[1]), stringTokens[2]);
}