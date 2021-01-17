#ifndef __DECODERGT_H__
#define __DECODERGT_H__

#include "DecoderArithmetic.h"

class DecoderGt : public DecoderArithmetic {
 public:
  DecoderGt(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
            std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderGt();
  void Decode(TokenBase token) override;

 private:
};

#endif  // __DECODERGT_H__