#include "PointerSegment.h"

#include <iostream>

PointerSegment::PointerSegment(
    std::shared_ptr<CodeBlockBuilder> codeBlockBuilder, std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

PointerSegment::~PointerSegment() {}

void PointerSegment::Push(std::shared_ptr<StackSegment> globalStack,
                          std::string zeroOrOne) {
  std::string symbol = zeroOrOne == "0" ? "THIS" : "THAT";
  (*codeBlockBuilder_).WriteLine("@" + symbol).WriteLine("D=M");
  globalStack->PushFromD();
}

void PointerSegment::Pop(std::shared_ptr<StackSegment> globalStack,
                         std::string zeroOrOne) {
  globalStack->PopToD();
  std::string symbol = zeroOrOne == "0" ? "THIS" : "THAT";
  (*codeBlockBuilder_).WriteLine("@" + symbol).WriteLine("M=D");
}