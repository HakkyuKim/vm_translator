#include "FunctionContext.h"

FunctionContext::FunctionContext(std::string fileName, std::string functionName, int nLocals) 
:fileName_(fileName), functionName_(functionName), nLocals_(nLocals){}

CodeBlock FunctionContext::Merge() 
{
    return *codeBlock_;
}
