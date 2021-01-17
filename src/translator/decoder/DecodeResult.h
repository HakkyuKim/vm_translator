#ifndef __DECODERESULT_H__
#define __DECODERESULT_H__

#include <memory>
#include <string>

#include "src/translator/code_block/CodeBlock.h"

class DecodeResult {
 public:
  DecodeResult(bool hasCodeBlock, bool isFunction,
               std::unique_ptr<CodeBlock> codeBlock, std::string fileName,
               std::string funcName);
  bool hasCodeBlock;
  bool isFunction;
  std::unique_ptr<CodeBlock> codeBlock;
  std::string fileName;
  std::string funcName;
};
#endif  // __DECODERESULT_H__