#ifndef __VMSEGMENT_H__
#define __VMSEGMENT_H__

#include <memory>
#include <string>

#include "StackSegment.h"
#include "src/translator/code_block/CodeBlockBuilder.h"

class VmSegment {
 public:
  VmSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder,
            std::string symbol);
  virtual ~VmSegment();

  void CopyDToRam(std::string ram);
  void CopyDToRamRef(std::string ram);
  void CopyRamToD(std::string ram);
  void CopyRamRefToD(std::string ram);
  void CopyDRefToD();
  void PlusMinusD(int32_t val);

  virtual void Push(std::shared_ptr<StackSegment> globalStack, std::string);
  virtual void Pop(std::shared_ptr<StackSegment> globalStack, std::string);

 protected:
  std::shared_ptr<CodeBlockBuilder> codeBlockBuilder_;
  std::string symbol_;
};

#endif  // __VMSEGMENT_H__