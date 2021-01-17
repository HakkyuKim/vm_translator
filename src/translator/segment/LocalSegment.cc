#include "LocalSegment.h"

LocalSegment::LocalSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                           std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

LocalSegment::~LocalSegment() {}