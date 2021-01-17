#include "DecoderBase.h"

#include "src/translator/code_block/CodeBlockBuilder.h"
#include "src/translator/segment/ArgumentSegment.h"
#include "src/translator/segment/ConstantSegment.h"
#include "src/translator/segment/LocalSegment.h"
#include "src/translator/segment/PointerSegment.h"
#include "src/translator/segment/StaticSegment.h"
#include "src/translator/segment/TempSegment.h"
#include "src/translator/segment/ThatSegment.h"
#include "src/translator/segment/ThisSegment.h"

DecoderBase::DecoderBase(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
                         std::shared_ptr<DecoderState> decoderState)
    : codeBlockBuilder_(codeBlockBuilder), decoderState_(decoderState) {
  globalStack_ = std::make_shared<StackSegment>(codeBlockBuilder_);
  vmSegments_ = {
      {SegmentType::CONSTANT,
       std::make_shared<ConstantSegment>(codeBlockBuilder_)},
      {SegmentType::STATIC, std::make_shared<StaticSegment>(codeBlockBuilder_)},
      {SegmentType::LOCAL, std::make_shared<LocalSegment>(codeBlockBuilder_)},
      {SegmentType::ARGUMENT,
       std::make_shared<ArgumentSegment>(codeBlockBuilder_)},
      {SegmentType::TEMP, std::make_shared<TempSegment>(codeBlockBuilder_)},
      {SegmentType::THIS, std::make_shared<ThisSegment>(codeBlockBuilder_)},
      {SegmentType::THAT, std::make_shared<ThatSegment>(codeBlockBuilder_)},
      {SegmentType::POINTER,
       std::make_shared<PointerSegment>(codeBlockBuilder_)}};
}

DecoderBase::~DecoderBase() {}
