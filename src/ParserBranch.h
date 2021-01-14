#ifndef __PARSERBRANCH_H__
#define __PARSERBRANCH_H__

#include "types.h"
#include "ParserBase.h"

class ParserBranch : public ParserBase {
    std::shared_ptr<BaseTokens> parse(OperationType operationType, std::vector<std::string> stringTokens) override;
};

#endif // __PARSERBRANCH_H__