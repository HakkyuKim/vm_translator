#include "Decoder.h"

#include "src/translator/decoder/src/decoder_memory/DecoderPop.h"
#include "src/translator/decoder/src/decoder_memory/DecoderPush.h"

Decoder::Decoder() {
  decoderState_ = std::make_shared<DecoderState>();
  codeBlockbuilder_ = std::make_shared<CodeBlockBuilder>();
  decoders_ = {{OperationType::PUSH, std::make_shared<DecoderPush>(
                                         codeBlockbuilder_, decoderState_)},
               {OperationType::POP, std::make_shared<DecoderPop>(
                                        codeBlockbuilder_, decoderState_)}};
}

DecodeResult Decoder::FeedLine(std::unique_ptr<TokenBase> token) {
  decoders_[token->operationType]->Decode(std::move(token));
  return PackageDecodeResult();
}

void Decoder::SetFile(std::string fileName) {
  decoderState_->SetFile(fileName);
}

DecodeResult Decoder::CloseFile() {
  decoderState_->CloseFile();
  return PackageDecodeResult();
}

DecodeResult Decoder::PackageDecodeResult() {
  if (!decoderState_->isCodeReturnable()) {
    return DecodeResult(false, false, nullptr, "", "");
  }

  return DecodeResult(true, decoderState_->isFunction(),
                      codeBlockbuilder_->build(), decoderState_->GetFileName(),
                      decoderState_->GetFuncName());
}
