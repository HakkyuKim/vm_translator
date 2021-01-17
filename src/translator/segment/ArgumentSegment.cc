#include "ArgumentSegment.h"

ArgumentSegment::ArgumentSegment(
    std::shared_ptr<CodeBlockBuilder> codeBlockBuilder, std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

ArgumentSegment::~ArgumentSegment() {}