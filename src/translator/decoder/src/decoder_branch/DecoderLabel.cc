#include "DecoderLabel.h"

#include "src/token/token_branch/TokenLabel.h"

DecoderLabel::DecoderLabel(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                           std::shared_ptr<DecoderState> decoderState)
    : DecoderBranch(codeBlockBuilder, decoderState) {}

DecoderLabel::~DecoderLabel() {}

void DecoderLabel::Decode(std::unique_ptr<TokenBase> token) {
  TokenLabel* tokenLabel = static_cast<TokenLabel*>(token.get());
  (*codeBlockBuilder_).WriteLine("(" + tokenLabel->labelName + ")");
}
