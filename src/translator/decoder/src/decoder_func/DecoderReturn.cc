#include "DecoderReturn.h"

#include "src/token/token_func/TokenReturn.h"

DecoderReturn::DecoderReturn(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                             std::shared_ptr<DecoderState> decoderState)
    : DecoderFunc(codeBlockBuilder, decoderState) {}

DecoderReturn::~DecoderReturn() {}

// tempRet = *(LCL -5)
// tempLCL = LCL
// SP--
// *ARG = pop()
// SP = ARG + 1
// THAT = *(LCL - 1)
// THIS = *(LCL - 2)
// ARG = *(LCL - 3)
// LCL = *(LCL - 4)
// @tempRet
// 0; JMP
void DecoderReturn::Decode(std::unique_ptr<TokenBase> token) {
  TokenReturn* tokenReturn = static_cast<TokenReturn*>(token.get());
  std::string tempRet = "R13";
  std::string tempLCL = "R14";

  vmSegments_[SegmentType::LOCAL]->CopyRamToD("LCL");
  vmSegments_[SegmentType::LOCAL]->PlusMinusD(-5);
  vmSegments_[SegmentType::LOCAL]->CopyDRefToD();
  vmSegments_[SegmentType::LOCAL]->CopyDToRam(tempRet);

  vmSegments_[SegmentType::LOCAL]->CopyRamToD("LCL");
  vmSegments_[SegmentType::LOCAL]->CopyDToRam(tempLCL);

  globalStack_->PopToD();
  vmSegments_[SegmentType::ARGUMENT]->CopyDToRamRef("ARG");

  vmSegments_[SegmentType::ARGUMENT]->CopyRamToD("ARG");
  vmSegments_[SegmentType::ARGUMENT]->PlusMinusD(1);
  vmSegments_[SegmentType::ARGUMENT]->CopyDToRam("SP");

  vmSegments_[SegmentType::THAT]->CopyRamToD(tempLCL);
  vmSegments_[SegmentType::THAT]->PlusMinusD(-1);
  vmSegments_[SegmentType::THAT]->CopyDRefToD();
  vmSegments_[SegmentType::THAT]->CopyDToRam("THAT");
  vmSegments_[SegmentType::THIS]->CopyRamToD(tempLCL);
  vmSegments_[SegmentType::THIS]->PlusMinusD(-2);
  vmSegments_[SegmentType::THIS]->CopyDRefToD();
  vmSegments_[SegmentType::THIS]->CopyDToRam("THIS");
  vmSegments_[SegmentType::ARGUMENT]->CopyRamToD(tempLCL);
  vmSegments_[SegmentType::ARGUMENT]->PlusMinusD(-3);
  vmSegments_[SegmentType::ARGUMENT]->CopyDRefToD();
  vmSegments_[SegmentType::ARGUMENT]->CopyDToRam("ARG");
  vmSegments_[SegmentType::LOCAL]->CopyRamToD(tempLCL);
  vmSegments_[SegmentType::LOCAL]->PlusMinusD(-4);
  vmSegments_[SegmentType::LOCAL]->CopyDRefToD();
  vmSegments_[SegmentType::LOCAL]->CopyDToRam("LCL");

  vmSegments_[SegmentType::LOCAL]->CopyRamToD(tempRet);
  (*codeBlockBuilder_).WriteLine("A=D").WriteLine("0; JMP");
}