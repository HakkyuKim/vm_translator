#ifndef __PARSERFUNCTION_H__
#define __PARSERFUNCTION_H__

#include "types.h"
#include "ParserBase.h"

class ParserFunction : public ParserBase {
    std::shared_ptr<BaseTokens> parse(OperationType operationType, std::vector<std::string> stringTokens) override;
};

#endif // __PARSERFUNCTION_H__