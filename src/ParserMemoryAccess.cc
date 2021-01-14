#include "ParserMemoryAccess.h"

std::shared_ptr<BaseTokens> ParserMemoryAccess::parse(OperationType operationType, std::vector<std::string> stringTokens) 
{
    return std::make_shared<Tokens>(operationType, EnumUtil::getSegmentType(stringTokens[1]), stringTokens[2]);
}
