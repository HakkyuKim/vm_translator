#include "DecoderNeg.h"

#include "src/token/token_arithmetic/TokenNeg.h"

DecoderNeg::DecoderNeg(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderNeg::~DecoderNeg() {}

void DecoderNeg::Decode(std::unique_ptr<TokenBase> token) {
  TokenNeg* tokenNeg = static_cast<TokenNeg*>(token.get());
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("D=-D");
  globalStack_->PushFromD();
}