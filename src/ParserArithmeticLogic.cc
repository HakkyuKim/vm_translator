#include "ParserArithmeticLogic.h"

std::shared_ptr<BaseTokens> ParserArithmeticLogic::parse(OperationType operationType, std::vector<std::string> stringTokens) 
{
    return std::make_shared<ArithmeticLogicalTokens>(operationType);
}
