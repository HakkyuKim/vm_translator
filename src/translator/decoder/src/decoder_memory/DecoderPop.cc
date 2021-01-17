#include "DecoderPop.h"

#include "src/token/token_memory/TokenPop.h"

DecoderPop::DecoderPop(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                       std::shared_ptr<DecoderState> decoderState)
    : DecoderMemory(codeBlockBuilder, decoderState) {}

DecoderPop::~DecoderPop() {}

void DecoderPop::Decode(std::unique_ptr<TokenBase> token) {
  TokenPop* tokenPop = static_cast<TokenPop*>(token.get());
  vmSegments_[tokenPop->segmentType]->Pop(globalStack_, tokenPop->offset);
}