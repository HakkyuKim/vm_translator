#include "DecoderGoTo.h"

#include "src/token/token_branch/TokenGoTo.h"

DecoderGoTo::DecoderGoTo(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::shared_ptr<DecoderState> decoderState)
    : DecoderBranch(codeBlockBuilder, decoderState) {}

DecoderGoTo::~DecoderGoTo() {}

void DecoderGoTo::Decode(std::unique_ptr<TokenBase> token) {
  TokenGoTo* tokenGoTo = static_cast<TokenGoTo*>(token.get());
  (*codeBlockBuilder_)
      .WriteLine("@" + tokenGoTo->labelName)
      .WriteLine("0; JMP");
}