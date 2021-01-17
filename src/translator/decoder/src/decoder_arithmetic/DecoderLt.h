#ifndef __DECODERLT_H__
#define __DECODERLT_H__

#include "DecoderArithmetic.h"

class DecoderLt : public DecoderArithmetic {
 public:
  DecoderLt(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
            std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderLt();
  void Decode(TokenBase token) override;

 private:
};

#endif  // __DECODERLT_H__