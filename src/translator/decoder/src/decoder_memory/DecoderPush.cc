#include "DecoderPush.h"

#include "src/token/token_memory/TokenPush.h"

DecoderPush::DecoderPush(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::shared_ptr<DecoderState> decoderState)
    : DecoderMemory(codeBlockBuilder, decoderState) {}

DecoderPush::~DecoderPush() {}

void DecoderPush::Decode(std::unique_ptr<TokenBase> token) {
  TokenPush* tokenPush = static_cast<TokenPush*>(token.get());
  vmSegments_[tokenPush->segmentType]->Push(globalStack_, tokenPush->offset);
}