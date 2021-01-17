#include "ThisSegment.h"

ThisSegment::ThisSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

ThisSegment::~ThisSegment() {}