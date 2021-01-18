#include "DecoderIfGoTo.h"

#include "src/token/token_branch/TokenIfGoTo.h"

DecoderIfGoTo::DecoderIfGoTo(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                             std::shared_ptr<DecoderState> decoderState)
    : DecoderBranch(codeBlockBuilder, decoderState) {}

DecoderIfGoTo::~DecoderIfGoTo() {}

// Jumps to '(labelName)' if stack.top() is "greater than 0".
// Remove stack.top() after.
void DecoderIfGoTo::Decode(std::unique_ptr<TokenBase> token) {
  TokenIfGoTo* tokenIfGoTo = static_cast<TokenIfGoTo*>(token.get());
  globalStack_->PopToD();
  (*codeBlockBuilder_)
      .WriteLine("@" + tokenIfGoTo->labelName)
      .WriteLine("D; JGT");
}