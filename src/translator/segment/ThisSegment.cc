#include "ThisSegment.h"

ThisSegment::ThisSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

ThisSegment::~ThisSegment() {}

void ThisSegment::Push(std::shared_ptr<StackSegment> globalStack, std::string) {
  CopyRamToD(symbol_);
  globalStack->PushFromD();
}

void ThisSegment::Pop(std::shared_ptr<StackSegment> globalStack, std::string) {
  CopyRamToD(symbol_);
  globalStack->PushFromD();
}