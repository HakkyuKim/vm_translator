#ifndef __PARSER_H__
#define __PARSER_H__

#include <map>
#include "types.h"
#include "ParserBase.h"

enum ParseType {
    UNDEFINED,
    WHITESPACE,
    CODE,
    COMMENT
};

struct ParseResult {
    ParseResult(bool success, ParseType parseType, std::shared_ptr<BaseTokens> tokens)
    :success(success), parseType(parseType), tokens(tokens){};
    bool success;
    ParseType parseType;
    std::shared_ptr<BaseTokens> tokens;
};

class Parser
{
public:
    Parser();
    ParseResult parse(std::string vmCodeLine);
private:
    std::vector<std::string> SplitBySpace(std::string line);
    std::map<OperationType, std::shared_ptr<ParserBase>> parsers_;
};

#endif // __PARSER_H__