#ifndef __DECODERLOGIC_H__
#define __DECODERLOGIC_H__

#include "src/translator/decoder/src/DecoderBase.h"

class DecoderLogic : public DecoderBase {
 public:
  DecoderLogic(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
               std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderLogic();

 private:
};

#endif  // __DECODERLOGIC_H__