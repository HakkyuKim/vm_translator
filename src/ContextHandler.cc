#include "ContextHandler.h"
#include <iostream>

// Creates a new 'FileContext' referred to by 'currentFileContext'.
void ContextHandler::CreateFileContext(std::string fileName) 
{
    currentFileContext_ = std::make_unique<FileContext>(fileName);
}

void ContextHandler::SaveFileContext(std::unique_ptr<CodeBlock> codeBlock) 
{
    if(codeBlock) currentFileContext_->codeBlock_ = std::move(codeBlock);
    fileContexts_[currentFileContext_->fileName_] = std::move(currentFileContext_);
}

// Creates a new 'FunctionContext' referred to by 'currentFuncContext'.
void ContextHandler::CreateFunctionContext(std::string funcName, uint32_t nLocals) 
{
    currentFuncContext_ = std::make_unique<FunctionContext>(
        currentFileContext_->fileName_,
        funcName,
        nLocals
    );
}

void ContextHandler::SaveFunctionContext(std::unique_ptr<CodeBlock> codeBlock) 
{
    currentFuncContext_->codeBlock_ = std::move(codeBlock);
    currentFileContext_->AddFunctionContext(std::move(currentFuncContext_));
}

void ContextHandler::SwitchContext(OperationType operationType, CodeBlockBuilder codeBlockBuilder) 
{
    if(operationType == OperationType::END){
        CodeBlock codeBlock = codeBlockBuilder.build();
        std::unique_ptr<CodeBlock> ptr = std::make_unique<CodeBlock>();
        ptr->extend(codeBlock);
        if(currentFuncContext_){
            SaveFunctionContext(std::move(ptr));
        }
        SaveFileContext(std::move(ptr));
    }
}

CodeBlock ContextHandler::Merge() 
{
    CodeBlock codeBlock;
    for(auto &fileContext : fileContexts_){
        codeBlock.extend(fileContext.second->Merge());
    }
    return codeBlock;
}
