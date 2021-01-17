#include "DecoderNeg.h"

DecoderNeg::DecoderNeg(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderNeg::~DecoderNeg() {}