#ifndef __CODEBLOCKBUILDER_H__
#define __CODEBLOCKBUILDER_H__

#include <string>
#include "CodeBlock.h"

class CodeBlockBuilder {
    private:
    CodeBlock codeBlock_;
    public:
    CodeBlockBuilder& WriteLine(std::string line);
    CodeBlockBuilder& Extend(CodeBlock codeBlock);
    CodeBlock build();
};

#endif // __CODEBLOCKBUILDER_H__