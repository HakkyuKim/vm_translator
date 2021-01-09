#include "VmSegmentTranslator.h"

// The sub-operation of 'push segment i'.
// Generates assembly code that copies the value in the related segment's position 
// referenced by 'address' to the D register.
//   D = RAM[RAM[address]]
// Typically the 'address' is one the general-purpose registers (13 ~ 15) storing
// the pre-calculated address of the related segment's i-th position.
CodeBlock VmSegmentTranslator::CopyToD(std::string address, std::string index) 
{
    return CodeBlock(std::vector<std::string>({ "@" + address, "A=M", "D=M"}));
}

// The sub-operation of 'pop segment i'.
// Generates assembly code that copies the value stored in D register 
// to the segment position referenced by 'address'.
//   RAM[RAM[address]] = D
// Typically the 'address' is one the general-purpose registers (13 ~ 15) storing
// the pre-calculated address of the related segment's i-th position.
CodeBlock VmSegmentTranslator::CopyFromD(std::string address, std::string index) 
{
    return CodeBlock(std::vector<std::string>({ "@" + address, "A=M", "M=D"}));
}

// The sub-operation of 'push/pop segment i'.
// Generates assembly code that calculates the address of the 
// related segment's i-th postion to 'address'.
//   RAM[address] = D
CodeBlock VmSegmentTranslator::CalculateAddress(std::string address, std::string index)
{
    CodeBlock codeBlock;
    codeBlock.WriteLine("@" + index);
    codeBlock.WriteLine("D=A");
    codeBlock.WriteLine("@" + baseAddrPointerSymbol_);
    codeBlock.WriteLine("A=M");
    codeBlock.WriteLine("D=D+A");
    codeBlock.WriteLine("@" + address);
    codeBlock.WriteLine("M=D");
    return codeBlock;
}
