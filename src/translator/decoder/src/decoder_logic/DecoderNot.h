#ifndef __DECODERNOT_H__
#define __DECODERNOT_H__

#include "DecoderLogic.h"

class DecoderNot : public DecoderLogic {
 public:
  DecoderNot(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
             std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderNot();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERNOT_H__