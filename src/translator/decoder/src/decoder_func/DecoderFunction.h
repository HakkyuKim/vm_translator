#ifndef __DECODERFUNCTION_H__
#define __DECODERFUNCTION_H__

#include "DecoderFunc.h"

class DecoderFunction : public DecoderFunc {
 public:
  DecoderFunction(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                  std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderFunction();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERFUNCTION_H__