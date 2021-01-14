#include "ParserReturn.h"

std::shared_ptr<BaseTokens> ParserReturn::parse(OperationType operationType, std::vector<std::string> stringTokens) 
{
    return std::make_shared<ReturnTokens>(operationType);
}
