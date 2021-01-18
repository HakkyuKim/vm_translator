#ifndef __CODEWRITER_H__
#define __CODEWRITER_H__

#include <map>
#include <string>

#include "src/translator/code_manager/CodeManager.h"
#include "src/translator/decoder/Decoder.h"

class Translator {
 public:
  Translator();
  ~Translator();
  void FeedLine(std::unique_ptr<TokenBase> token);
  void CloseFile();
  void SetFile(std::string fileName);
  std::string Code();
  std::string GetBootStrap(std::string initialStackAddr);
  void ProcessDecodeResult();

 private:
  Decoder decoder_;
  CodeManager codeManager_;
  std::unique_ptr<CodeBlock> bootstrap_;
};

#endif  // __CODEWRITER_H__