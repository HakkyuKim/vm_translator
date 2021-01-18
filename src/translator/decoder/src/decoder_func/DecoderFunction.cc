#include "DecoderFunction.h"

#include <iostream>

#include "src/token/token_func/TokenFunction.h"

DecoderFunction::DecoderFunction(
    std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
    std::shared_ptr<DecoderState> decoderState)
    : DecoderFunc(codeBlockBuilder, decoderState) {}

DecoderFunction::~DecoderFunction() {}

void DecoderFunction::Decode(std::unique_ptr<TokenBase> token) {
  TokenFunction* tokenFunction = static_cast<TokenFunction*>(token.get());

  decoderState_->OnFuncClose();
  decoderState_->OnFuncOpen(tokenFunction->funcName);

  uint32_t n = static_cast<uint32_t>(std::stoi(tokenFunction->nLocals));
  (*codeBlockBuilder_)
      .WriteLine("(" + tokenFunction->funcName + ")")
      .WriteLine("D=0");

  for (uint32_t i = 0; i < n; ++i) {
    globalStack_->PushFromD();
  }
}