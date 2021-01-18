#ifndef __DECODERSTATE_H__
#define __DECODERSTATE_H__

#include <queue>
#include <string>

#include "DecodeResult.h"
#include "src/translator/code_block/CodeBlockBuilder.h"

class DecoderState {
 public:
  DecoderState(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder);
  std::string GetFileName();
  std::string GetFuncName();
  std::string NextReturnAddress();

  bool IsResultEmpty();
  std::shared_ptr<DecodeResult> Poll();

  void OnFileOpen(std::string fileName);
  void OnFileClose();
  void OnFuncOpen(std::string funcName);
  void OnFuncClose();

 private:
  std::shared_ptr<CodeBlockBuilder> codeBlockBuilder_;
  uint32_t returnAddressCnt_;
  std::string fileName_;
  std::string funcName_;
  bool isFileActive_;
  bool isFuncActive_;

  std::queue<std::shared_ptr<DecodeResult>> results_;
};

#endif  // __DECODERSTATE_H__