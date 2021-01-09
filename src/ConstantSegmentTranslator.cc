#include <stdexcept>
#include "ConstantSegmentTranslator.h"


CodeBlock ConstantSegmentTranslator::CopyFromD(std::string address, std::string index)
{
    return CodeBlock();
}

// For the constant segment, A register needs to be set to 'index'.
CodeBlock ConstantSegmentTranslator::CopyToD(std::string address, std::string index) 
{
    return CodeBlock(std::vector<std::string>({"@" + index, "D=A"}));
}

CodeBlock ConstantSegmentTranslator::CalculateAddress(std::string address, std::string index) 
{
    return CodeBlock();
}
