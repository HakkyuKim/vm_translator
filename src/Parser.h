#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <vector>
#include "types.h"

enum ParseType {
    UNDEFINED,
    WHITESPACE,
    CODE,
    COMMENT
};

struct ParseResult {
    ParseResult(bool success, ParseType parseType, Tokens *tokens)
    :success(success), parseType(parseType), tokens(tokens){};
    ~ParseResult(){
        if(tokens != nullptr){
            delete tokens;
        }   
    }
    bool success;
    ParseType parseType;
    Tokens *tokens;
};

class Parser
{
public:
    ParseResult parse(std::string vmCodeLine);
    private:
    std::vector<std::string> SplitBySpace(std::string line);
    OperationType GetOperationType(std::string operationType);
    SegmentType GetSegmentType(std::string segmentType);
};

#endif // __PARSER_H__