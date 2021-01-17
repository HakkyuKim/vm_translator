#include "DecoderNot.h"

DecoderNot::DecoderNot(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderLogic(codeBlockBuilder, decoderState) {}

DecoderNot::~DecoderNot() {}

void DecoderNot::Decode(std::unique_ptr<TokenBase> token) {}