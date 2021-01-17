#include "DecoderEq.h"

DecoderEq::DecoderEq(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                     std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderEq::~DecoderEq() {}