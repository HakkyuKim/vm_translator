#include "ConstantSegment.h"

#include <stdexcept>

ConstantSegment::ConstantSegment(
    std::shared_ptr<CodeBlockBuilder> codeBlockBuilder, std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

ConstantSegment::~ConstantSegment() {}

void ConstantSegment::Push(std::shared_ptr<StackSegment> globalStack,
                           std::string val) {
  (*codeBlockBuilder_).WriteLine("@" + val).WriteLine("D=A");
  globalStack->PushFromD();
}

void ConstantSegment::Pop(std::shared_ptr<StackSegment> globalStack,
                          std::string) {
  throw new std::logic_error("Cannot perform pop command on constant segment");
}