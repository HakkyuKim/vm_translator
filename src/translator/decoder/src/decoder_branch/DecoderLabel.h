#ifndef __DECODERLABEL_H__
#define __DECODERLABEL_H__

#include "DecoderBranch.h"

class DecoderLabel : public DecoderBranch {
 public:
  DecoderLabel(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
               std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderLabel();
  void Decode(std::unique_ptr<TokenBase> token) override;

 private:
};

#endif  // __DECODERLABEL_H__