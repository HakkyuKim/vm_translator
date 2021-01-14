#include "ParserBranch.h"

std::shared_ptr<BaseTokens> ParserBranch::parse(OperationType operationType, std::vector<std::string> stringTokens) 
{
    return std::make_shared<BranchTokens>(operationType, stringTokens[1]);
}
