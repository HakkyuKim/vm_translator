#ifndef __DECODERCALL_H__
#define __DECODERCALL_H__

#include "DecoderFunc.h"

class DecoderCall : public DecoderFunc {
 public:
  DecoderCall(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
              std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderCall();
  void Decode(TokenBase token) override;

 private:
};

#endif  // __DECODERCALL_H__