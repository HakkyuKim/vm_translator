#include "VmSegmentTranslator.h"

std::string VmSegmentTranslator::PutToD(std::string index) 
{
    return SetLocation(index) + "D=M\n";
}

std::string VmSegmentTranslator::PutFromD() 
{
    return "@" + baseAddrPointerSymbol_ + "\nA=M\nM=D\n";
}

std::string VmSegmentTranslator::SetLocation(std::string index)
{
    std::string asmCode = "";
    asmCode += "@" + index + "\nD=A\n";
    asmCode += "@" + baseAddrPointerSymbol_ + "\nA=M\nA=A+D\n";
    return asmCode;
}

std::string VmSegmentTranslator::SetLocationOverwrite(std::string index) 
{
    std::string asmCode ="";
    std::string operation = std::stoi(index) < 0 ? "-" : "+";
    asmCode += "@" + index + "\nD=A\n";
    asmCode += "@" + baseAddrPointerSymbol_ + "\nM=M" + operation + "D\n";
    return asmCode;
}
