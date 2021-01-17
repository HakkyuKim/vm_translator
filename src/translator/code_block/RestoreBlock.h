#ifndef __RESTOREBLOCK_H__
#define __RESTOREBLOCK_H__

#include <string>

#include "CodeBlock.h"
#include "CodeBlockBuilder.h"

class RestoreBlock {
 public:
  static CodeBlock CreateRestoreCodeBlock(std::string tempRam);

 private:
  RestoreBlock();
  static CodeBlock RestoreCodeBlock(std::string tempRam, std::string destRam);
};

#endif  // __RESTOREBLOCK_H__