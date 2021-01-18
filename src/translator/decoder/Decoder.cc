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
#include "src/translator/decoder/src/decoder_func/DecoderFunction.h"
#include "src/translator/decoder/src/decoder_func/DecoderReturn.h"
#include "src/translator/decoder/src/decoder_logic/DecoderAnd.h"
#include "src/translator/decoder/src/decoder_logic/DecoderNot.h"
#include "src/translator/decoder/src/decoder_logic/DecoderOr.h"
#include "src/translator/decoder/src/decoder_memory/DecoderPop.h"
#include "src/translator/decoder/src/decoder_memory/DecoderPush.h"

Decoder::Decoder() {
  decoderState_ = std::make_shared<DecoderState>();
  codeBlockbuilder_ = std::make_shared<CodeBlockBuilder>();
  decoders_ = {
      {OperationType::PUSH,
       std::make_shared<DecoderPush>(codeBlockbuilder_, decoderState_)},
      {OperationType::POP,
       std::make_shared<DecoderPop>(codeBlockbuilder_, decoderState_)},
      {OperationType::ADD,
       std::make_shared<DecoderAdd>(codeBlockbuilder_, decoderState_)},
      {OperationType::SUB,
       std::make_shared<DecoderSub>(codeBlockbuilder_, decoderState_)},
      {OperationType::NEG,
       std::make_shared<DecoderNeg>(codeBlockbuilder_, decoderState_)},
      {OperationType::EQ,
       std::make_shared<DecoderEq>(codeBlockbuilder_, decoderState_)},
      {OperationType::GT,
       std::make_shared<DecoderGt>(codeBlockbuilder_, decoderState_)},
      {OperationType::LT,
       std::make_shared<DecoderLt>(codeBlockbuilder_, decoderState_)},
      {OperationType::AND,
       std::make_shared<DecoderAnd>(codeBlockbuilder_, decoderState_)},
      {OperationType::OR,
       std::make_shared<DecoderOr>(codeBlockbuilder_, decoderState_)},
      {OperationType::NOT,
       std::make_shared<DecoderNot>(codeBlockbuilder_, decoderState_)},
      {OperationType::LABEL,
       std::make_shared<DecoderLabel>(codeBlockbuilder_, decoderState_)},
      {OperationType::GOTO,
       std::make_shared<DecoderGoTo>(codeBlockbuilder_, decoderState_)},
      {OperationType::IFGOTO,
       std::make_shared<DecoderIfGoTo>(codeBlockbuilder_, decoderState_)},
      {OperationType::FUNCTION,
       std::make_shared<DecoderFunction>(codeBlockbuilder_, decoderState_)},
      {OperationType::RETURN,
       std::make_shared<DecoderReturn>(codeBlockbuilder_, decoderState_)},
  };
}

std::unique_ptr<DecodeResult> Decoder::FeedLine(
    std::unique_ptr<TokenBase> token) {
  if (decoders_[token->operationType] == nullptr) {
    throw new std::logic_error("is not a supported command\n");
  }
  decoders_[token->operationType]->Decode(std::move(token));
  // std::unique_ptr<DecodeResult> shuh = PackageDecodeResult();
  return std::make_unique<DecodeResult>(false, false, nullptr, "", "");
}

void Decoder::SetFile(std::string fileName) {
  decoderState_->SetFile(fileName);
}

std::unique_ptr<DecodeResult> Decoder::CloseFile() {
  decoderState_->CloseFile();
  std::unique_ptr<DecodeResult> shuh = PackageDecodeResult();
  // std::cout << shuh->codeBlock->String();
  return shuh;
}

std::unique_ptr<DecodeResult> Decoder::PackageDecodeResult() {
  if (!decoderState_->isCodeReturnable()) {
    return std::make_unique<DecodeResult>(false, false, nullptr, "", "");
  }
  std::unique_ptr<DecodeResult> p = std::make_unique<DecodeResult>(
      true, decoderState_->isFunction(), codeBlockbuilder_->build(),
      decoderState_->GetFileName(), decoderState_->GetFuncName());

  // std::cout << p->codeBlock->String();

  return p;
}
