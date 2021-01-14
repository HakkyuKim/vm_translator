#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdexcept>
#include <string>
#include <memory>
#include <vector>
#include <iostream>

enum OperationType {
    PUSH, // push segment value
    POP, // pop segment value
    ADD, // add
    SUB, // sub
    NEG, // neg
    EQ, // eq
    LT, // lt
    GT, // gt
    AND, // and
    OR, // or
    NOT, // not
    LABEL, // label labelName
    GOTO, // goto labelName
    IFGOTO, // if-goto labelName
    FUNC, // function funcName n
    CALL, // call funcName n
    RETURN, // return
    END, // 0
};

enum SegmentType {
    STATIC,
    LOCAL,
    ARGUMENT,
    CONSTANT,
    THIS,
    THAT,
    POINTER,
    TEMP
};

class EnumUtil {
    public:
    static OperationType getOperationType(std::string operationType)
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
    else if(operationType == "function"){
        return OperationType::FUNC;
    }
    else if(operationType == "call"){
        return OperationType::CALL;
    }
    else if(operationType == "return"){
        return OperationType::RETURN;
    }
    else
    {
        throw std::invalid_argument("Undefined operation type " + operationType + "\n");
    }
}

static SegmentType getSegmentType(std::string segmentType)
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
};

class BaseTokens {
public:
    BaseTokens(OperationType operationType)
    :operationType(operationType){}
    OperationType operationType;
};

class Tokens : public BaseTokens {
public:
    Tokens(OperationType operationType, SegmentType segmentType, std::string index)
    :segmentType(segmentType), index(index), BaseTokens(operationType){};
    SegmentType segmentType;
    std::string index;
};

class ArithmeticLogicalTokens : public BaseTokens
{
    public:
    ArithmeticLogicalTokens(OperationType operationType)
    :BaseTokens(operationType){}
};

class BranchTokens: public BaseTokens
{
public:
    BranchTokens(OperationType operationType, std::string label)
    :label(label), BaseTokens(operationType){}
    std::string label;
};

class FuncTokens: public BaseTokens
{
public:
    FuncTokens(OperationType operationType, std::string funcName, std::string n)
    : funcName(funcName), n(n), BaseTokens(operationType){}
    std::string funcName;
    std::string n;
};

class ReturnTokens: public BaseTokens
{
    public:
    ReturnTokens(OperationType operationType)
    :BaseTokens(operationType){}
};

#endif // __TYPES_H__