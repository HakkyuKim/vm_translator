#include "DecoderLt.h"

#include "src/token/token_arithmetic/TokenLt.h"

DecoderLt::DecoderLt(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                     std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderLt::~DecoderLt() {}

void DecoderLt::Decode(std::unique_ptr<TokenBase> token) {
  DecodeCompare("JLT");
}