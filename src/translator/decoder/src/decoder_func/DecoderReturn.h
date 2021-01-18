#ifndef __DECODERRETURN_H__
#define __DECODERRETURN_H__

#include "DecoderFunc.h"

class DecoderReturn : public DecoderFunc {
 public:
  DecoderReturn(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderReturn();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERRETURN_H__