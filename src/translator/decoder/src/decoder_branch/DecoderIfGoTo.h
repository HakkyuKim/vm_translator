#ifndef __DECODERIFGOTO_H__
#define __DECODERIFGOTO_H__

#include "DecoderBranch.h"

class DecoderIfGoTo : public DecoderBranch {
 public:
  DecoderIfGoTo(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderIfGoTo();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERIFGOTO_H__