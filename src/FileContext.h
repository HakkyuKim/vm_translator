#ifndef __FILECONTEXT_H__
#define __FILECONTEXT_H__

#include <string>
#include <map>
#include <memory>
#include "Context.h"
#include "FunctionContext.h"

class ContextHandler;

class FileContext : public Context{
public:
FileContext(std::string fileName);
CodeBlock Merge() override;
void AddFunctionContext(std::unique_ptr<FunctionContext> functionContext);
friend ContextHandler;
private:
std::string fileName_;
std::map<std::string, std::unique_ptr<FunctionContext>> functionContexts_;
};

#endif // __FILECONTEXT_H__