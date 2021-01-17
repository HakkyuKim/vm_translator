#include "ThatSegment.h"

ThatSegment::ThatSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

ThatSegment::~ThatSegment() {}

void ThatSegment::Push(std::shared_ptr<StackSegment> globalStack, std::string) {
  CopyRamToD(symbol_);
  globalStack->PushFromD();
}

void ThatSegment::Pop(std::shared_ptr<StackSegment> globalStack, std::string) {
  globalStack->PopToD();
  CopyDToRam(symbol_);
}