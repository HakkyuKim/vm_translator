#ifndef __CONTEXTHANDLER_H__
#define __CONTEXTHANDLER_H__

#include <map>
#include <memory>
#include <string>
#include "FileContext.h"
#include "FunctionContext.h"
#include "CodeBlockBuilder.h"
#include "types.h"

class ContextHandler {
public:
    void CreateFileContext(std::string fileName);
    void SaveFileContext(std::unique_ptr<CodeBlock> codeBlock);
    void CreateFunctionContext(std::string funcName, uint32_t nLocals);
    void SaveFunctionContext(std::unique_ptr<CodeBlock> codeBlock);
    void SwitchContext(OperationType operationType, CodeBlockBuilder codeBlockBuilder);
    CodeBlock Merge();
private:
    std::map<std::string, std::unique_ptr<FileContext>> fileContexts_;
    std::unique_ptr<FileContext> currentFileContext_;
    std::unique_ptr<FunctionContext> currentFuncContext_;
};

#endif // __CONTEXTHANDLER_H__