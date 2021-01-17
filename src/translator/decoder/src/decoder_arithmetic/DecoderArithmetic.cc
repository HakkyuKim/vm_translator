#include "DecoderArithmetic.h"

uint32_t DecoderArithmetic::compareCnt_ = static_cast<uint32_t>(0);

DecoderArithmetic::DecoderArithmetic(
    std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
    std::shared_ptr<DecoderState> decoderState)
    : DecoderBase(codeBlockBuilder, decoderState) {}

DecoderArithmetic::~DecoderArithmetic() {}

void DecoderArithmetic::DecodeCompare(std::string operation) {
  compareCnt_++;
  std::string compareCntStr = std::to_string(compareCnt_);
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("@R13").WriteLine("M=D");
  globalStack_->PopToD();
  (*codeBlockBuilder_)
      .WriteLine("@R13")
      .WriteLine("D=D-M")
      .WriteLine("@TRUE" + compareCntStr)
      .WriteLine("D; " + operation);

  // false
  (*codeBlockBuilder_)
      .WriteLine("D=0")
      .WriteLine("@END" + compareCntStr)
      .WriteLine("0; JMP");

  // true
  (*codeBlockBuilder_)
      .WriteLine("(TRUE" + compareCntStr + ")")
      .WriteLine("D=-1");

  // end
  (*codeBlockBuilder_).WriteLine("(END" + compareCntStr + ")");
  globalStack_->PushFromD();
}