#include <utility>
#include "CodeBlockBuilder.h"

CodeBlockBuilder& CodeBlockBuilder::WriteLine(std::string line) 
{
    codeBlock_.codes_.push_back(line);
    return *this;
}

CodeBlockBuilder& CodeBlockBuilder::Extend(CodeBlock codeBlock) 
{
    codeBlock_.extend(codeBlock);
    return *this;
}

CodeBlock CodeBlockBuilder::build() 
{
    return std::move(codeBlock_);
}

uint32_t CodeBlockBuilder::GetLineNumbers() 
{
    return static_cast<uint32_t>(codeBlock_.codes_.size());
}
