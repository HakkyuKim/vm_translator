#include "FileContext.h"
#include <iostream>

FileContext::FileContext(std::string fileName) 
: fileName_(fileName){}

void FileContext::AddFunctionContext(std::unique_ptr<FunctionContext> functionContext) 
{
    functionContexts_[functionContext->functionName_] = std::move(functionContext);
}

CodeBlock FileContext::Merge() 
{
    CodeBlock codeBlock;
    codeBlock.extend(*codeBlock_);
    for(auto& funcContext : functionContexts_){
        codeBlock.extend(*(funcContext.second->codeBlock_));
    }
    return codeBlock;
}
