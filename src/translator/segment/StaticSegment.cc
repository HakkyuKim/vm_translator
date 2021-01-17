#include "StaticSegment.h"

StaticSegment::StaticSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                             std::string symbol)
    : VmSegment(codeBlockBuilder, symbol) {}

StaticSegment::~StaticSegment() {}

void StaticSegment::Push(std::shared_ptr<StackSegment> globalStack,
                         std::string offset) {
  std::string ram = fileName_ + "." + offset;
  CopyRamToD(ram);
  globalStack->PushFromD();
}

void StaticSegment::Pop(std::shared_ptr<StackSegment> globalStack,
                        std::string offset) {
  std::string ram = fileName_ + "." + offset;
  globalStack->PopToD();
  CopyDToRam(ram);
}

void StaticSegment::SetFileName(std::string fileName) { fileName_ = fileName; }