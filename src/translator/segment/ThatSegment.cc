#include "ThatSegment.h"

ThatSegment::ThatSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

ThatSegment::~ThatSegment() {}