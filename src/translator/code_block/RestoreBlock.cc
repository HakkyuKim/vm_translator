#include "RestoreBlock.h"

RestoreBlock::RestoreBlock(){};

CodeBlock RestoreBlock::CreateRestoreCodeBlock(std::string tempRam) {
  // *tempRam = LCL
  // restore
  return CodeBlock::Create()
      .WriteLine("@LCL")
      .WriteLine("D=A")
      .WriteLine("@" + tempRam)
      .WriteLine("M=D")
      .Extend(RestoreCodeBlock(tempRam, "THAT"))
      .Extend(RestoreCodeBlock(tempRam, "THIS"))
      .Extend(RestoreCodeBlock(tempRam, "ARG"))
      .Extend(RestoreCodeBlock(tempRam, "LCL"))
      .build();
}

CodeBlock RestoreBlock::RestoreCodeBlock(std::string tempRam,
                                         std::string destRam) {
  // *tempRam = *tempRam - 1
  // D = *tempRam
  // *destRam = *D
  return CodeBlock::Create()
      .WriteLine("@" + tempRam)
      .WriteLine("M=M-1")
      .WriteLine("A=M")
      .WriteLine("D=M")
      .WriteLine("@" + destRam)
      .WriteLine("M=D")
      .build();
}
