#ifndef __DECODERMEMORY_H__
#define __DECODERMEMORY_H__

#include "src/translator/decoder/src/DecoderBase.h"

class DecoderMemory : public DecoderBase {
 public:
  DecoderMemory(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderMemory();

 private:
};

#endif  // __DECODERMEMORY_H__