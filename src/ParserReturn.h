#ifndef __PARSERRETURN_H__
#define __PARSERRETURN_H__

#include "types.h"
#include "ParserBase.h"

class ParserReturn : public ParserBase {
    std::shared_ptr<BaseTokens> parse(OperationType operationType, std::vector<std::string> stringTokens) override;
};

#endif // __PARSERRETURN_H__