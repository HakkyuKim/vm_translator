#include "TempSegmentTranslator.h"

// The temp segment has a fixed based address of 5.
// Hence, the calculated address is 5 + index.
CodeBlock TempSegmentTranslator::CalculateAddress(std::string address, std::string index) 
{
    CodeBlock codeBlock;
    std::string fixedBaseAddress = "5";
    codeBlock.WriteLine("@" + index);
    codeBlock.WriteLine("D=A");
    codeBlock.WriteLine("@" + fixedBaseAddress);
    codeBlock.WriteLine("D=D+A");
    codeBlock.WriteLine("@" + address);
    codeBlock.WriteLine("M=D");
    return codeBlock;
}
