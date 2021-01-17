#ifndef __DECODERARITHMETIC_H__
#define __DECODERARITHMETIC_H__

#include "src/translator/decoder/src/DecoderBase.h"

class DecoderArithmetic : public DecoderBase {
 public:
  DecoderArithmetic(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                    std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderArithmetic();
  void DecodeCompare(std::string operation);

 private:
  static uint32_t compareCnt_;
};

#endif  // __DECODERARITHMETIC_H__