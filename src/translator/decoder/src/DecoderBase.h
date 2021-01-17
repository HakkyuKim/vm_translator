#ifndef __DECODERBASE_H__
#define __DECODERBASE_H__

#include <map>
#include <memory>

#include "src/token/TokenBase.h"
#include "src/translator/code_block/CodeBlockBuilder.h"
#include "src/translator/decoder/DecoderState.h"
#include "src/translator/segment/StackSegment.h"
#include "src/translator/segment/VmSegment.h"
#include "src/type/SegmentType.h"

class DecoderBase {
 public:
  DecoderBase(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
              std::shared_ptr<DecoderState> decoderState);
  virtual ~DecoderBase();
  virtual void Decode(std::unique_ptr<TokenBase> token) = 0;

 protected:
  std::shared_ptr<CodeBlockBuilder> codeBlockBuilder_;
  std::map<SegmentType, std::shared_ptr<VmSegment>> vmSegments_;
  std::shared_ptr<StackSegment> globalStack_;
  std::shared_ptr<DecoderState> decoderState_;
};

#endif  // __DECODERBASE_H__