#include "StaticSegment.h"

StaticSegment::StaticSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                             std::shared_ptr<DecoderState> decoderState,
                             std::string symbol)
    : decoderState_(decoderState), VmSegment(codeBlockBuilder, symbol) {}

StaticSegment::~StaticSegment() {}

void StaticSegment::Push(std::shared_ptr<StackSegment> globalStack,
                         std::string offset) {
  std::string staticSymbol = decoderState_->GetFileName() + "." + offset;
  CopyRamToD(staticSymbol);
  globalStack->PushFromD();
}

void StaticSegment::Pop(std::shared_ptr<StackSegment> globalStack,
                        std::string offset) {
  std::string staticSymbol = decoderState_->GetFileName() + "." + offset;
  globalStack->PopToD();
  CopyDToRam(staticSymbol);
}
