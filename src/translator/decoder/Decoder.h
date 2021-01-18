#ifndef __DECODER_H__
#define __DECODER_H__

#include <map>
#include <memory>

#include "DecodeResult.h"
#include "DecoderState.h"
#include "src/token/TokenBase.h"
#include "src/translator/decoder/src/DecoderBase.h"
#include "src/type/OperationType.h"

class Decoder {
 public:
  Decoder();
  void FeedLine(std::unique_ptr<TokenBase> token);
  void SetFile(std::string fileName);
  void CloseFile();

  bool IsResultEmpty();
  std::shared_ptr<DecodeResult> Poll();

 private:
  std::map<OperationType, std::shared_ptr<DecoderBase>> decoders_;
  std::shared_ptr<DecoderState> decoderState_;
};

#endif  // __DECODER_H__