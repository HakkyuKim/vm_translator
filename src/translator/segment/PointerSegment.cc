#include "PointerSegment.h"

PointerSegment::PointerSegment(
    std::shared_ptr<CodeBlockBuilder> codeBlockBuilder, std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

PointerSegment::~PointerSegment() {}