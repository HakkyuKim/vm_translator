#include <stdexcept>
#include "Parser.h"

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

    OperationType operationType = GetOperationType(tokenStrings[0]);
    if(operationType == OperationType::LABEL || 
       operationType == OperationType::GOTO || 
       operationType == OperationType::IFGOTO) {
        return ParseResult(true, ParseType::CODE,
                        new Tokens(operationType, defulatSegment, tokenStrings[1]));
    }
    else{
        SegmentType segmentType = tokenStrings.size() >= 2 ? GetSegmentType(tokenStrings[1]) : defulatSegment;
        std::string index = tokenStrings.size() >= 3 ? tokenStrings[2] : "0";
        return ParseResult(true, ParseType::CODE,
                       new Tokens(operationType, segmentType, index));
    }
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

OperationType Parser::GetOperationType(std::string operationType)
{
    if (operationType == "push")
    {
        return OperationType::PUSH;
    }
    else if (operationType == "pop")
    {
        return OperationType::POP;
    }
    else if (operationType == "add")
    {
        return OperationType::ADD;
    }
    else if (operationType == "sub")
    {
        return OperationType::SUB;
    }
    else if(operationType == "eq"){
        return OperationType::EQ;
    }
    else if(operationType == "lt"){
        return OperationType::LT;
    }
    else if(operationType == "gt"){
        return OperationType::GT;
    }
    else if(operationType == "neg"){
        return OperationType::NEG;
    }
    else if(operationType == "not"){
        return OperationType::NOT;
    }
    else if(operationType == "and"){
        return OperationType::AND;
    }
    else if(operationType == "or"){
        return OperationType::OR;
    }
    else if(operationType == "label"){
        return OperationType::LABEL;
    }
    else if(operationType == "goto"){
        return OperationType::GOTO;
    }
    else if(operationType == "if-goto"){
        return OperationType::IFGOTO;
    }
    else
    {
        throw std::invalid_argument("Undefined operation type " + operationType + "\n");
    }
}

SegmentType Parser::GetSegmentType(std::string segmentType)
{
    if (segmentType == "static")
    {
        return SegmentType::STATIC;
    }
    else if (segmentType == "local")
    {
        return SegmentType::LOCAL;
    }
    else if (segmentType == "argument")
    {
        return SegmentType::ARGUMENT;
    }
    else if (segmentType == "constant")
    {
        return SegmentType::CONSTANT;
    }
    else if (segmentType == "this")
    {
        return SegmentType::THIS;
    }
    else if (segmentType == "that")
    {
        return SegmentType::THAT;
    }
    else if (segmentType == "pointer")
    {
        return SegmentType::POINTER;
    }
    else if (segmentType == "temp")
    {
        return SegmentType::TEMP;
    }
    else
    {
        throw std::invalid_argument("Undefined virtual segment type " + segmentType + "\n");
    }
}
