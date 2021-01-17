#include "DecoderAnd.h"

DecoderAnd::DecoderAnd(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderLogic(codeBlockBuilder, decoderState) {}

DecoderAnd::~DecoderAnd() {}

void DecoderAnd::Decode(std::unique_ptr<TokenBase> token) {}