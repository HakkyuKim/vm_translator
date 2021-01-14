#ifndef __FUNCTIONCONTEXT_H__
#define __FUNCTIONCONTEXT_H__

#include <string>
#include "Context.h"

class FileContext;
class ContextHandler;

class FunctionContext : public Context {
    public:
    FunctionContext(std::string fileName, std::string functionName, std::string nLocals);
    CodeBlock Merge() override;
    friend ContextHandler;
    friend FileContext;
    private:
    std::string fileName_;
    std::string functionName_;
    std::string nLocals_;  
};

#endif // __FUNCTIONCONTEXT_H__