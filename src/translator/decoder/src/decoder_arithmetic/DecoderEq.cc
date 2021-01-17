#include "DecoderEq.h"

DecoderEq::DecoderEq(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                     std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderEq::~DecoderEq() {}

void DecoderEq::Decode(std::unique_ptr<TokenBase> token) {
  DecodeCompare("JEQ");
}