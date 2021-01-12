#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include <memory>
#include "CodeBlock.h"

class ContextHandler;

class Context {
    public:
    virtual CodeBlock Merge() = 0;
    protected:
    std::unique_ptr<CodeBlock> codeBlock_;
};

#endif // __CONTEXT_H__