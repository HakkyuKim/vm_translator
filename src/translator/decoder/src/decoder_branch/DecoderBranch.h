#ifndef __DECODERBRANCH_H__
#define __DECODERBRANCH_H__

#include "src/translator/decoder/src/DecoderBase.h"

class DecoderBranch : public DecoderBase {
 public:
  DecoderBranch(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderBranch();

 private:
};

#endif  // __DECODERBRANCH_H__