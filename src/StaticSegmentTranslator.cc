#include "StaticSegmentTranslator.h"

CodeBlock StaticSegmentTranslator::CopyFromD(std::string address, std::string index) 
{
    return CodeBlock(std::vector<std::string>({"@" + fileName_ + "." + index, "M=D"}));
}

CodeBlock StaticSegmentTranslator::CopyToD(std::string address, std::string index) 
{
    return CodeBlock(std::vector<std::string>({"@" + fileName_ + "." + index, "D=M"}));
}

CodeBlock StaticSegmentTranslator::CalculateAddress(std::string address, std::string index) 
{
    return CodeBlock();
}
