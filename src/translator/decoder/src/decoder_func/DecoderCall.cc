#include "DecoderCall.h"

#include "src/token/token_func/TokenCall.h"

DecoderCall::DecoderCall(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::shared_ptr<DecoderState> decoderState)
    : DecoderFunc(codeBlockBuilder, decoderState) {}

DecoderCall::~DecoderCall() {}

// push retAddress
// push LCL
// push ARG
// push THIS
// push THAT
// LCL = SP
// ARG = (SP - 5 - nArgs)
// @funcName
// 0; JMP
// (retAddress)
void DecoderCall::Decode(std::unique_ptr<TokenBase> token) {
  TokenCall* tokenCall = static_cast<TokenCall*>(token.get());
  // get the caller function name from decoderState_
  std::string retAddr = decoderState_->NextReturnAddress();
  (*codeBlockBuilder_).WriteLine("@" + retAddr).WriteLine("D=A");
  globalStack_->PushFromD();

  vmSegments_[SegmentType::LOCAL]->CopyRamToD("LCL");
  globalStack_->PushFromD();

  vmSegments_[SegmentType::ARGUMENT]->CopyRamToD("ARG");
  globalStack_->PushFromD();

  vmSegments_[SegmentType::THIS]->CopyRamToD("THIS");
  globalStack_->PushFromD();

  vmSegments_[SegmentType::THAT]->CopyRamToD("THAT");
  globalStack_->PushFromD();

  vmSegments_[SegmentType::LOCAL]->CopyRamToD("SP");
  vmSegments_[SegmentType::LOCAL]->CopyDToRam("LCL");

  vmSegments_[SegmentType::ARGUMENT]->CopyRamToD("SP");
  int n = std::stoi(tokenCall->nArgs);
  vmSegments_[SegmentType::ARGUMENT]->PlusMinusD(-5 - n);
  vmSegments_[SegmentType::ARGUMENT]->CopyDToRam("ARG");

  (*codeBlockBuilder_)
      .WriteLine("@" + tokenCall->funcName)
      .WriteLine("0; JMP")
      .WriteLine("(" + retAddr + ")");
}