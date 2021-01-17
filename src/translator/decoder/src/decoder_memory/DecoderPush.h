#ifndef __DECODERPUSH_H__
#define __DECODERPUSH_H__

#include "DecoderMemory.h"

class DecoderPush : public DecoderMemory {
 public:
  DecoderPush(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
              std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderPush();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERPUSH_H__