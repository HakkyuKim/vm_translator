#include "PointerSegmentTranslator.h"

// RAM[THIS or THAT] = D
CodeBlock PointerSegmentTranslator::CopyFromD(std::string address, std::string index) 
{
    return CodeBlock(std::vector<std::string>({"@" + symbolThisThat_, "M=D"}));
}

// D = RAM[THIS or THAT]
CodeBlock PointerSegmentTranslator::CopyToD(std::string address, std::string index)
{
    return CodeBlock(std::vector<std::string>({"@" + symbolThisThat_, "D=M"}));
}

CodeBlock PointerSegmentTranslator::CalculateAddress(std::string address, std::string index) 
{
    symbolThisThat_ = index == "0" ? "THIS" : "THAT";
    return CodeBlock();   
}
