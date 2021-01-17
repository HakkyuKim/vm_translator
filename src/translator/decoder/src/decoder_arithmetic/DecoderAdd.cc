#include "DecoderAdd.h"

#include "src/token/token_arithmetic/TokenAdd.h"

DecoderAdd::DecoderAdd(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderAdd::~DecoderAdd() {}

void DecoderAdd::Decode(std::unique_ptr<TokenBase> token) 
{
  TokenAdd* tokenAdd = static_cast<TokenAdd*>(token.get());
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("@R13")
                      .WriteLine("M=D");
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("@R13")
                      .WriteLine("D=D+M");
  globalStack_->PushFromD();
}