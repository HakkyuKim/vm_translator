#ifndef __TYPES_H__
#define __TYPES_H__

#include <string>
#include <vector>

#define OP_TYPE_NUM 4
#define SEG_TYPE_NUM 8

enum OperationType {
    PUSH,
    POP,
    ADD,
    SUB,
    NEG,
    EQ,
    LT,
    GT,
    AND,
    OR,
    NOT,
    LABEL,
    GOTO,
    IFGOTO,
    END,
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

struct BaseTokens {
    BaseTokens(OperationType operationType)
    :operationType(operationType){};
    OperationType operationType;
};

class Tokens {
    public:
    Tokens(OperationType operation, SegmentType segmentType, std::string index)
    :operation(operation), segmentType(segmentType), index(index){};
    OperationType operation;
    SegmentType segmentType;
    std::string index;
    private:
};

struct BranchTokens: public BaseTokens
{
    BranchTokens(OperationType operationType, std::string label)
    :label(label), BaseTokens(operationType){};
    std::string label;
};


#endif // __TYPES_H__