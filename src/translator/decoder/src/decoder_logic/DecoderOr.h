#ifndef __DECODEROR_H__
#define __DECODEROR_H__

#include "DecoderLogic.h"

class DecoderOr : public DecoderLogic {
 public:
  DecoderOr(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
            std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderOr();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODEROR_H__