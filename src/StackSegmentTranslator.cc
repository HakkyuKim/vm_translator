#include "StackSegmentTranslator.h"

CodeBlock StackSegmentTranslator::PushFromD(){
    CodeBlock codeBlock = CodeBlock(std::vector<std::string>({"@SP", "A=M", "M=D"}));
    codeBlock.extend(IncreaseSP());
    return codeBlock;
}

CodeBlock StackSegmentTranslator::PopToD(){
    CodeBlock codeBlock = DecreaseSP();
    codeBlock.extend(CodeBlock(std::vector<std::string>({"A=M", "D=M"})));
    return codeBlock;
}

CodeBlock StackSegmentTranslator::IncreaseSP(){
    return CodeBlock(std::vector<std::string>({"@SP","M=M+1"}));
}

CodeBlock StackSegmentTranslator::DecreaseSP(){
    return CodeBlock(std::vector<std::string>({"@SP","M=M-1"}));
}