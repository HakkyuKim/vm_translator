#ifndef __PARSERMEMORYACCESS_H__
#define __PARSERMEMORYACCESS_H__

#include "types.h"
#include "ParserBase.h"

class ParserMemoryAccess : public ParserBase {
    std::shared_ptr<BaseTokens> parse(OperationType operationType, std::vector<std::string> stringTokens) override;
};

#endif // __PARSERMEMORYACCESS_H__