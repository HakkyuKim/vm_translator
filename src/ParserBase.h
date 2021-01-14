#ifndef __PARSERBASE_H__
#define __PARSERBASE_H__

#include "types.h"

class ParserBase {
public:
    virtual std::shared_ptr<BaseTokens> parse(OperationType operationType, std::vector<std::string> stringTokens) = 0;
};

#endif // __PARSERBASE_H__