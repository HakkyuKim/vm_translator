#ifndef __TYPES_H__
#define __TYPES_H__

#include <string>

enum OperationType {
    PUSH,
    POP,
    ADD,
    SUB
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

class Tokens {
    public:
    OperationType operation;
    SegmentType segmentType;
    std::string index;
    private:
};

#endif // __TYPES_H__