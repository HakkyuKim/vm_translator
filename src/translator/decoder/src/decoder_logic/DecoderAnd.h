#ifndef __DECODERAND_H__
#define __DECODERAND_H__

#include "DecoderLogic.h"

class DecoderAnd : public DecoderLogic {
 public:
  DecoderAnd(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
             std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderAnd();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERAND_H__