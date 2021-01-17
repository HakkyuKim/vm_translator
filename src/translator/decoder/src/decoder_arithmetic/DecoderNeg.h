#ifndef __DECODERNEG_H__
#define __DECODERNEG_H__

#include "DecoderArithmetic.h"

class DecoderNeg : public DecoderArithmetic {
 public:
  DecoderNeg(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
             std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderNeg();
  void Decode(TokenBase token) override;

 private:
};

#endif  // __DECODERNEG_H__