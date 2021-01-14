#include "ParserFunction.h"

std::shared_ptr<BaseTokens> ParserFunction::parse(OperationType operationType, std::vector<std::string> stringTokens) 
{
    return std::make_shared<FuncTokens>(operationType, stringTokens[1], stringTokens[2]);
}
