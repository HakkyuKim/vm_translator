#include "TempSegment.h"

TempSegment::TempSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

TempSegment::~TempSegment() {}

void TempSegment::Push(std::shared_ptr<StackSegment> globalStack,
                       std::string offset) {
  (*codeBlockBuilder_).WriteLine("@5").WriteLine("D=A");
  PlusMinusD(std::stoi(offset));

  CopyDRefToD();
  globalStack->PushFromD();
}

// The temp segment has a fixed based address of 5.
// Hence, the calculated address is 5 + offset.
void TempSegment::Pop(std::shared_ptr<StackSegment> globalStack,
                      std::string offset) {
  (*codeBlockBuilder_).WriteLine("@5").WriteLine("D=A");
  PlusMinusD(std::stoi(offset));

  // Is R13 necessary?
  CopyDToRam("R13");
  globalStack->PopToD();
  CopyDToRamRef("R13");
}
