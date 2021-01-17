#ifndef __DECODER_H__
#define __DECODER_H__

#include <map>
#include <memory>

#include "DecodeResult.h"
#include "DecoderState.h"
#include "src/token/TokenBase.h"
#include "src/translator/code_block/CodeBlockBuilder.h"
#include "src/translator/decoder/src/DecoderBase.h"
#include "src/type/OperationType.h"

class Decoder {
 public:
  Decoder();
  DecodeResult FeedLine(std::unique_ptr<TokenBase> token);
  void SetFile(std::string fileName);
  DecodeResult CloseFile();

 private:
  DecodeResult PackageDecodeResult();
  std::map<OperationType, std::shared_ptr<DecoderBase>> decoders_;
  std::shared_ptr<DecoderState> decoderState_;
  std::shared_ptr<CodeBlockBuilder> codeBlockbuilder_;
};

#endif  // __DECODER_H__