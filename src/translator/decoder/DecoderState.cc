#include "DecoderState.h"

DecoderState::DecoderState() { returnAddressCnt_ = 0; }

void DecoderState::SetFile(std::string fileName) { fileName_ = fileName; }

void DecoderState::CloseFile() {}

std::string DecoderState::GetFileName() { return fileName_; }

void DecoderState::SetFunc(std::string funcName) { funcName_ = funcName; }

void DecoderState::CloseFunc() {}

std::string DecoderState::GetFuncName() { return funcName_; }

std::string DecoderState::NextReturnAddressCnt() {
  return std::to_string(returnAddressCnt_++);
}

bool DecoderState::isCodeReturnable() { return true; }

bool DecoderState::isFunction() { return true; }
