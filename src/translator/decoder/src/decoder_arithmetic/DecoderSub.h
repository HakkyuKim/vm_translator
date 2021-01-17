#ifndef __DECODERSUB_H__
#define __DECODERSUB_H__

#include "DecoderArithmetic.h"

class DecoderSub : public DecoderArithmetic {
 public:
  DecoderSub(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
             std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderSub();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERSUB_H__