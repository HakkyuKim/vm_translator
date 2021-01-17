#include "DecoderAnd.h"

#include "src/token/token_logic/TokenAnd.h"

DecoderAnd::DecoderAnd(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderLogic(codeBlockBuilder, decoderState) {}

DecoderAnd::~DecoderAnd() {}

void DecoderAnd::Decode(std::unique_ptr<TokenBase> token) {
  TokenAnd* tokenAnd = static_cast<TokenAnd*>(token.get());
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("@R13").WriteLine("M=D");
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("@R13").WriteLine("D=D&M");
  globalStack_->PushFromD();
}