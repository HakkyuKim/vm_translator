#include "DecoderOr.h"

#include "src/token/token_logic/TokenOr.h"

DecoderOr::DecoderOr(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                     std::shared_ptr<DecoderState> decoderState)
    : DecoderLogic(codeBlockBuilder, decoderState) {}

DecoderOr::~DecoderOr() {}

void DecoderOr::Decode(std::unique_ptr<TokenBase> token) {
  TokenOr* tokenOr = static_cast<TokenOr*>(token.get());
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("@R13").WriteLine("M=D");
  globalStack_->PopToD();
  (*codeBlockBuilder_).WriteLine("@R13").WriteLine("D=D|M");
  globalStack_->PushFromD();
}