#include "FunctionContext.h"
#include <iostream>

FunctionContext::FunctionContext(std::string fileName, std::string functionName, std::string nLocals) 
:fileName_(fileName), functionName_(functionName), nLocals_(nLocals){}

CodeBlock FunctionContext::Merge() 
{
    return *codeBlock_;
}
