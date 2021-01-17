#ifndef __DECODEREQ_H__
#define __DECODEREQ_H__

#include "DecoderArithmetic.h"

class DecoderEq : public DecoderArithmetic {
 public:
  DecoderEq(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
            std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderEq();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODEREQ_H__