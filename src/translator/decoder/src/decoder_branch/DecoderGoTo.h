#ifndef __DECODERGOTO_H__
#define __DECODERGOTO_H__

#include "DecoderBranch.h"

class DecoderGoTo : public DecoderBranch {
 public:
  DecoderGoTo(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
              std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderGoTo();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERGOTO_H__