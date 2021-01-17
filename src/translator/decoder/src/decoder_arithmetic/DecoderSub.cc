#include "DecoderSub.h"

DecoderSub::DecoderSub(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderArithmetic(codeBlockBuilder, decoderState) {}

DecoderSub::~DecoderSub() {}