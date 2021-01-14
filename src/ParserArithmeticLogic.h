#ifndef __PARSERARITHMETICLOGIC_H__
#define __PARSERARITHMETICLOGIC_H__

#include "types.h"
#include "ParserBase.h"

class ParserArithmeticLogic : public ParserBase {
    std::shared_ptr<BaseTokens> parse(OperationType operationType, std::vector<std::string> stringTokens) override;
};

#endif // __PARSERARITHMETICLOGIC_H__