#include <stdexcept>
#include "Parser.h"
#include <iostream>
#include "ParserMemoryAccess.h"
#include "ParserArithmeticLogic.h"
#include "ParserBranch.h"
#include "ParserFunction.h"
#include "ParserReturn.h"

Parser::Parser() 
{
    parsers_ = std::map<OperationType, std::shared_ptr<ParserBase>> {
        {OperationType::POP, std::make_shared<ParserMemoryAccess>()},
        {OperationType::PUSH, std::make_shared<ParserMemoryAccess>()},
        {OperationType::ADD, std::make_shared<ParserArithmeticLogic>()},
        {OperationType::SUB, std::make_shared<ParserArithmeticLogic>()},
        {OperationType::NEG, std::make_shared<ParserArithmeticLogic>()},
        {OperationType::EQ, std::make_shared<ParserArithmeticLogic>()},
        {OperationType::LT, std::make_shared<ParserArithmeticLogic>()},
        {OperationType::GT, std::make_shared<ParserArithmeticLogic>()},
        {OperationType::AND, std::make_shared<ParserArithmeticLogic>()},
        {OperationType::OR, std::make_shared<ParserArithmeticLogic>()},
        {OperationType::NOT, std::make_shared<ParserArithmeticLogic>()},
        {OperationType::LABEL, std::make_shared<ParserBranch>()},
        {OperationType::GOTO, std::make_shared<ParserBranch>()},
        {OperationType::IFGOTO, std::make_shared<ParserBranch>()},
        {OperationType::FUNC, std::make_shared<ParserFunction>()},
        {OperationType::CALL, std::make_shared<ParserFunction>()},
        {OperationType::RETURN, std::make_shared<ParserReturn>()}
    };
}

ParseResult Parser::parse(std::string vmCodeLine)
{
    SegmentType defulatSegment = SegmentType::STATIC;

    std::vector<std::string> tokenStrings = SplitBySpace(vmCodeLine);
    if(tokenStrings.empty()){
        return ParseResult(true, ParseType::WHITESPACE, nullptr);
    }
    if (tokenStrings[0] == "//")
    {
        return ParseResult(true, ParseType::COMMENT, nullptr);
    };

    OperationType operationType = EnumUtil::getOperationType(tokenStrings[0]);
    return ParseResult(true, ParseType::CODE, parsers_[operationType]->parse(operationType, tokenStrings));
}

std::vector<std::string> Parser::SplitBySpace(std::string line)
{
    std::string token;
    std::vector<std::string> tokens;
    for (char c : line)
    {
        if (c == ' ')
        {
            if (!token.empty())
            {
                tokens.push_back(token);
            }
            token.clear();
            continue;
        }
        token.push_back(c);
    }
    if (!token.empty())
    {
        tokens.push_back(token);
    }
    return tokens;
}

