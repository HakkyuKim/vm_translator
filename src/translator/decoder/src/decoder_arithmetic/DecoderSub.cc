#include "DecoderSub.h"

#include "src/token/token_arithmetic/TokenSub.h"

DecoderSub::DecoderSub(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderSub::~DecoderSub() {}

void DecoderSub::Decode(std::unique_ptr<TokenBase> token) 
{
  TokenSub* tokenSub = static_cast<TokenSub*>(token.get());
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("@R13")
                      .WriteLine("M=D");
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("@R13")
                      .WriteLine("D=D-M");
  globalStack_->PushFromD();
}