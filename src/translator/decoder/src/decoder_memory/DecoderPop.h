#ifndef __DECODERPOP_H__
#define __DECODERPOP_H__

#include "DecoderMemory.h"

class DecoderPop : public DecoderMemory {
 public:
  DecoderPop(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
             std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderPop();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERPOP_H__