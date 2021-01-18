#include "DecoderState.h"

DecoderState::DecoderState(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder)
    : codeBlockBuilder_(codeBlockBuilder),
      returnAddressCnt_(static_cast<uint32_t>(0)),
      fileName_(""),
      funcName_(""),
      isFileActive_(false),
      isFuncActive_(false) {}

std::string DecoderState::GetFileName() {
  if (!isFileActive_) {
    throw new std::runtime_error("Decoder is not working on a file.");
  }
  return fileName_;
}

std::string DecoderState::GetFuncName() {
  if (!isFuncActive_) {
    throw new std::runtime_error("Decoder is not working on a function.");
  }
  return funcName_;
}

std::string DecoderState::NextReturnAddress() {
  return funcName_ + ".RET$" + std::to_string(++returnAddressCnt_);
}

bool DecoderState::IsResultEmpty() { return results_.empty(); }

std::shared_ptr<DecodeResult> DecoderState::Poll() {
  std::shared_ptr<DecodeResult> result = results_.front();
  results_.pop();
  return result;
}

void DecoderState::OnFileOpen(std::string fileName) {
  fileName_ = fileName;
  isFileActive_ = true;
}

void DecoderState::OnFileClose() {
  if (!codeBlockBuilder_->IsEmpty()) {
    if (isFuncActive_) {
      returnAddressCnt_ = 0;
      results_.push(std::move(std::make_shared<DecodeResult>(
          true, true, codeBlockBuilder_->build(), fileName_, funcName_)));
      isFuncActive_ = false;
    } else {
      results_.push(std::move(std::make_shared<DecodeResult>(
          true, false, codeBlockBuilder_->build(), fileName_, "")));
    }
  }
  isFileActive_ = false;
}

void DecoderState::OnFuncOpen(std::string funcName) {
  funcName_ = funcName;
  isFuncActive_ = true;
}

void DecoderState::OnFuncClose() {
  if (!codeBlockBuilder_->IsEmpty()) {
    returnAddressCnt_ = 0;
    results_.push(std::move(std::make_shared<DecodeResult>(
        true, true, codeBlockBuilder_->build(), fileName_, funcName_)));
  }
  isFuncActive_ = false;
}
