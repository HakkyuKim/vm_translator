#include "CodeFunction.h"

#include <iostream>

CodeFunction::CodeFunction(std::unique_ptr<CodeBlock> codeBlock)
    : codeBlock_(std::move(codeBlock)) {}

CodeBlock CodeFunction::Merge() { return *codeBlock_; }
