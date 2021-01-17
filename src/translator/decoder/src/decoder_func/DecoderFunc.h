#ifndef __DECODERFUNC_H__
#define __DECODERFUNC_H__

#include "src/translator/decoder/src/DecoderBase.h"

class DecoderFunc : public DecoderBase {
 public:
  DecoderFunc(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
              std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderFunc();

 private:
};

#endif  // __DECODERFUNC_H__