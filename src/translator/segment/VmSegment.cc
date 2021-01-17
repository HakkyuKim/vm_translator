#include "VmSegment.h"

VmSegment::VmSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                     std::string symbol)
    : codeBlockBuilder_(codeBlockBuilder), symbol_(symbol) {}

VmSegment::~VmSegment() {}

// ram = D
void VmSegment::CopyDToRam(std::string ram) {
  (*codeBlockBuilder_).WriteLine("@" + ram).WriteLine("M=D");
}

// *ram = D
void VmSegment::CopyDToRamRef(std::string ram) {
  (*codeBlockBuilder_).WriteLine("@" + ram).WriteLine("A=M").WriteLine("M=D");
}

// D = ram
void VmSegment::CopyRamToD(std::string ram) {
  (*codeBlockBuilder_).WriteLine("@" + ram).WriteLine("D=M");
}

// D = *ram
void VmSegment::CopyRamRefToD(std::string ram) {
  (*codeBlockBuilder_).WriteLine("@" + ram).WriteLine("A=M").WriteLine("D=M");
}

// D = *D
void VmSegment::CopyDRefToD() {
  (*codeBlockBuilder_).WriteLine("A=D").WriteLine("D=M");
}

// D = D + val
void VmSegment::PlusMinusD(int32_t val) {
  std::string op = val >= 0 ? "+" : "-";
  std::string absVal = std::to_string(val >= 0 ? val : -val);

  (*codeBlockBuilder_).WriteLine("@" + absVal).WriteLine("D=D" + op + "A");
}

// @symbol
// D=M
// @offset
// D=D+A
// A=D
// D=M
// (push to stack)
void VmSegment::Push(std::shared_ptr<StackSegment> globalStack,
                     std::string offset) {
  CopyRamToD(symbol_);
  PlusMinusD(std::stoi(offset));
  CopyDRefToD();
  globalStack->PushFromD();
}

// @symbol
// D=M
// @offset
// D=D+A
// @R13
// M=D
// (pop from stack)
// @R13
// A=M
// M=D
void VmSegment::Pop(std::shared_ptr<StackSegment> globalStack,
                    std::string offset) {
  CopyRamToD(symbol_);
  PlusMinusD(std::stoi(offset));
  CopyDToRam("R13");
  globalStack->PopToD();
  CopyDToRamRef("R13");
}