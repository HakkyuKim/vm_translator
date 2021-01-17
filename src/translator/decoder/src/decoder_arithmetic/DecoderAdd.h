#ifndef __DECODERADD_H__
#define __DECODERADD_H__

#include "DecoderArithmetic.h"

class DecoderAdd : public DecoderArithmetic {
 public:
  DecoderAdd(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
             std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderAdd();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERADD_H__