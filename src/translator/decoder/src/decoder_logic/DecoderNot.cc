#include "DecoderNot.h"

#include "src/token/token_logic/TokenNot.h"

DecoderNot::DecoderNot(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderLogic(codeBlockBuilder, decoderState) {}

DecoderNot::~DecoderNot() {}

void DecoderNot::Decode(std::unique_ptr<TokenBase> token) {
  TokenNot* tokenNot = static_cast<TokenNot*>(token.get());
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("D=!D");
  globalStack_->PushFromD();
}