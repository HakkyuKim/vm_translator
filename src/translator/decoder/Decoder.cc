#include "Decoder.h"

#include <iostream>

#include "src/translator/decoder/src/decoder_arithmetic/DecoderAdd.h"
#include "src/translator/decoder/src/decoder_arithmetic/DecoderEq.h"
#include "src/translator/decoder/src/decoder_arithmetic/DecoderGt.h"
#include "src/translator/decoder/src/decoder_arithmetic/DecoderLt.h"
#include "src/translator/decoder/src/decoder_arithmetic/DecoderNeg.h"
#include "src/translator/decoder/src/decoder_arithmetic/DecoderSub.h"
#include "src/translator/decoder/src/decoder_branch/DecoderGoTo.h"
#include "src/translator/decoder/src/decoder_branch/DecoderIfGoTo.h"
#include "src/translator/decoder/src/decoder_branch/DecoderLabel.h"
#include "src/translator/decoder/src/decoder_func/DecoderCall.h"
#include "src/translator/decoder/src/decoder_func/DecoderFunction.h"
#include "src/translator/decoder/src/decoder_func/DecoderReturn.h"
#include "src/translator/decoder/src/decoder_logic/DecoderAnd.h"
#include "src/translator/decoder/src/decoder_logic/DecoderNot.h"
#include "src/translator/decoder/src/decoder_logic/DecoderOr.h"
#include "src/translator/decoder/src/decoder_memory/DecoderPop.h"
#include "src/translator/decoder/src/decoder_memory/DecoderPush.h"

Decoder::Decoder() {
  std::shared_ptr<CodeBlockBuilder> codeBlockBuilder =
      std::make_shared<CodeBlockBuilder>();
  decoderState_ = std::make_shared<DecoderState>(codeBlockBuilder);
  decoders_ = {
      {OperationType::PUSH,
       std::make_shared<DecoderPush>(codeBlockBuilder, decoderState_)},
      {OperationType::POP,
       std::make_shared<DecoderPop>(codeBlockBuilder, decoderState_)},
      {OperationType::ADD,
       std::make_shared<DecoderAdd>(codeBlockBuilder, decoderState_)},
      {OperationType::SUB,
       std::make_shared<DecoderSub>(codeBlockBuilder, decoderState_)},
      {OperationType::NEG,
       std::make_shared<DecoderNeg>(codeBlockBuilder, decoderState_)},
      {OperationType::EQ,
       std::make_shared<DecoderEq>(codeBlockBuilder, decoderState_)},
      {OperationType::GT,
       std::make_shared<DecoderGt>(codeBlockBuilder, decoderState_)},
      {OperationType::LT,
       std::make_shared<DecoderLt>(codeBlockBuilder, decoderState_)},
      {OperationType::AND,
       std::make_shared<DecoderAnd>(codeBlockBuilder, decoderState_)},
      {OperationType::OR,
       std::make_shared<DecoderOr>(codeBlockBuilder, decoderState_)},
      {OperationType::NOT,
       std::make_shared<DecoderNot>(codeBlockBuilder, decoderState_)},
      {OperationType::LABEL,
       std::make_shared<DecoderLabel>(codeBlockBuilder, decoderState_)},
      {OperationType::GOTO,
       std::make_shared<DecoderGoTo>(codeBlockBuilder, decoderState_)},
      {OperationType::IFGOTO,
       std::make_shared<DecoderIfGoTo>(codeBlockBuilder, decoderState_)},
      {OperationType::FUNCTION,
       std::make_shared<DecoderFunction>(codeBlockBuilder, decoderState_)},
      {OperationType::RETURN,
       std::make_shared<DecoderReturn>(codeBlockBuilder, decoderState_)},
      {OperationType::CALL,
       std::make_shared<DecoderCall>(codeBlockBuilder, decoderState_)},
  };
}

void Decoder::FeedLine(std::unique_ptr<TokenBase> token) {
  if (decoders_[token->operationType] == nullptr) {
    throw new std::logic_error("is not a supported command\n");
  }
  decoders_[token->operationType]->Decode(std::move(token));
}

void Decoder::SetFile(std::string fileName) {
  decoderState_->OnFileOpen(fileName);
}

void Decoder::CloseFile() { decoderState_->OnFileClose(); }

bool Decoder::IsResultEmpty() { return decoderState_->IsResultEmpty(); }

std::shared_ptr<DecodeResult> Decoder::Poll() { return decoderState_->Poll(); }