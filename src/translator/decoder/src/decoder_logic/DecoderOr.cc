#include "DecoderOr.h"

DecoderOr::DecoderOr(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                     std::shared_ptr<DecoderState> decoderState)
    : DecoderLogic(codeBlockBuilder, decoderState) {}

DecoderOr::~DecoderOr() {}

void DecoderOr::Decode(std::unique_ptr<TokenBase> token) {}