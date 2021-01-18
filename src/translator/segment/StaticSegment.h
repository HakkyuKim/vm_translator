#ifndef __STATICSEGMENT_H__
#define __STATICSEGMENT_H__

#include "VmSegment.h"
#include "src/translator/decoder/DecoderState.h"

class StaticSegment : public VmSegment {
 public:
  StaticSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                std::shared_ptr<DecoderState> decoderState,
                std::string symbol = "");
  virtual ~StaticSegment();
  void Push(std::shared_ptr<StackSegment> globalStack,
            std::string offset) override;
  void Pop(std::shared_ptr<StackSegment> globalStack,
           std::string offset) override;

 private:
  std::shared_ptr<DecoderState> decoderState_;
};

#endif  // __STATICSEGMENT_H__