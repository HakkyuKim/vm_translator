#include "DecoderArithmetic.h"

DecoderArithmetic::DecoderArithmetic(
    std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
    std::shared_ptr<DecoderState> decoderState)
    : DecoderBase(codeBlockBuilder, decoderState) {}

DecoderArithmetic::~DecoderArithmetic() {}