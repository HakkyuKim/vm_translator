#include "CodeWriter.h"

#include <iostream>
#include <vector>

#define GENERAL_PURPOSE_REGISTER_0 "R13"
#define GENERAL_PURPOSE_REGISTER_1 "R14"
#define GENERAL_PURPOSE_REGISTER_2 "R15"

#include "TokenAdd.h"
#include "TokenAnd.h"
#include "TokenCall.h"
#include "TokenEq.h"
#include "TokenFunction.h"
#include "TokenGoTo.h"
#include "TokenGt.h"
#include "TokenIfGoTo.h"
#include "TokenLabel.h"
#include "TokenLt.h"
#include "TokenNeg.h"
#include "TokenNot.h"
#include "TokenOr.h"
#include "TokenPop.h"
#include "TokenPush.h"
#include "TokenReturn.h"
#include "TokenSub.h"

CodeWriter::CodeWriter(std::string fileName) {
  segments_ = {{SegmentType::CONSTANT, new ConstantSegmentTranslator()},
               {SegmentType::STATIC, new StaticSegmentTranslator(fileName)},
               {SegmentType::LOCAL, new VmSegmentTranslator("LCL")},
               {SegmentType::ARGUMENT, new VmSegmentTranslator("ARG")},
               {SegmentType::TEMP, new TempSegmentTranslator()},
               {SegmentType::THIS, new VmSegmentTranslator("THIS")},
               {SegmentType::THAT, new VmSegmentTranslator("THAT")},
               {SegmentType::POINTER, new PointerSegmentTranslator()}};
  lineNumber = 0;
  contextHandler_.CreateFileContext(fileName);
}

CodeWriter::~CodeWriter() {
  for (auto entry : segments_) {
    if (entry.second != nullptr) delete entry.second;
  }
}

void CodeWriter::Decode(std::shared_ptr<BaseTokens> tokens) {
  switch (tokens->operationType) {
    case OperationType::POP:
      DecodePopOperation(*static_cast<Tokens *>(tokens.get()));
      break;
    case OperationType::PUSH:
      DecodePushOperation(*static_cast<Tokens *>(tokens.get()));
      break;
    case OperationType::ADD:
    case OperationType::SUB:
      DecodeAddSubOperation(
          *static_cast<ArithmeticLogicalTokens *>(tokens.get()));
      break;
    case OperationType::NEG:
    case OperationType::NOT:
      DecodeNegNotOperation(
          *static_cast<ArithmeticLogicalTokens *>(tokens.get()));
      break;
    case OperationType::AND:
    case OperationType::OR:
      DecodeAndOrOperation(
          *static_cast<ArithmeticLogicalTokens *>(tokens.get()));
      break;
    case OperationType::EQ:
    case OperationType::LT:
    case OperationType::GT:
      DecodeComparisonOperation(
          *static_cast<ArithmeticLogicalTokens *>(tokens.get()), lineNumber);
      break;
    case OperationType::LABEL:
      DecodeLable(*static_cast<BranchTokens *>(tokens.get()));
      break;
    case OperationType::GOTO:
      DecodeGoto(*static_cast<BranchTokens *>(tokens.get()));
      break;
    case OperationType::IFGOTO:
      DecodeIfGoto(*static_cast<BranchTokens *>(tokens.get()));
      break;
    case OperationType::FUNC:
      DecodeFuncDeclare(*static_cast<FuncTokens *>(tokens.get()));
      break;
    case OperationType::CALL:
      DecodeFuncCall(*static_cast<FuncTokens *>(tokens.get()));
      break;
    case OperationType::RETURN:
      DecodeReturn(*static_cast<ReturnTokens *>(tokens.get()),
                   contextHandler_.GetCurrentFunctionName());
      break;
    default:
      break;
  }
  lineNumber = codeBuilder_.GetLineNumbers();
}

CodeBlock CodeWriter::GenerateCode() {
  contextHandler_.SwitchContext(OperationType::END, codeBuilder_);
  CodeBlock codeBlock = contextHandler_.Merge();
  return codeBlock;
}

void CodeWriter::DecodePopOperation(Tokens tokens) {
  VmSegmentTranslator *segmentTranslator = segments_[tokens.segmentType];
  codeBuilder_
      .Extend(segmentTranslator->CalculateAddress(GENERAL_PURPOSE_REGISTER_0,
                                                  tokens.index))
      .Extend(stack_.PopToD())
      .Extend(segmentTranslator->CopyFromD(GENERAL_PURPOSE_REGISTER_0,
                                           tokens.index));
}

void CodeWriter::DecodePushOperation(Tokens tokens) {
  VmSegmentTranslator *segmentTranslator = segments_[tokens.segmentType];
  codeBuilder_
      .Extend(segmentTranslator->CalculateAddress(GENERAL_PURPOSE_REGISTER_0,
                                                  tokens.index))
      .Extend(
          segmentTranslator->CopyToD(GENERAL_PURPOSE_REGISTER_0, tokens.index))
      .Extend(stack_.PushFromD());
}

void CodeWriter::DecodeAddSubOperation(ArithmeticLogicalTokens tokens) {
  std::string asmCode;
  std::string operation =
      tokens.operationType == OperationType::ADD ? "+" : "-";
  std::string tempRegister = "R13";

  codeBuilder_.Extend(stack_.PopToD())
      .Extend(PlaceDToTempRegister(tempRegister))
      .Extend(stack_.PopToD())
      .WriteLine("@" + tempRegister)
      .WriteLine("D=D" + operation + "M")
      .Extend(stack_.PushFromD());
}

void CodeWriter::DecodeNegNotOperation(ArithmeticLogicalTokens tokens) {
  std::string operation =
      tokens.operationType == OperationType::NEG ? "-" : "!";
  codeBuilder_.Extend(stack_.PopToD())
      .WriteLine("D=" + operation + "D")
      .Extend(stack_.PushFromD());
}

void CodeWriter::DecodeAndOrOperation(ArithmeticLogicalTokens tokens) {
  std::string operation = tokens.operationType == OperationType::OR ? "|" : "&";
  std::string tempRegister = "R13";
  codeBuilder_.Extend(stack_.PopToD())
      .Extend(PlaceDToTempRegister(tempRegister))
      .Extend(stack_.PopToD())
      .WriteLine("@" + tempRegister)
      .WriteLine("D=D" + operation + "M")
      .Extend(stack_.PushFromD());
}

void CodeWriter::DecodeComparisonOperation(ArithmeticLogicalTokens tokens,
                                           uint32_t lineNum) {
  std::string operation = GetComparisonOperator(tokens.operationType);
  std::string tempRegister = "R13";

  // Set Block
  CodeBlock setBlock;
  setBlock.extend(stack_.PopToD());
  setBlock.extend(PlaceDToTempRegister(tempRegister));
  setBlock.extend(stack_.PopToD());
  setBlock.WriteLine("@" + tempRegister);
  setBlock.WriteLine("D=D-M");

  // Compare Block
  CodeBlock compareBlock(std::vector<std::string>({"where"}));
  compareBlock.WriteLine("D; " + operation);

  // False Block
  CodeBlock falseBlock(std::vector<std::string>({"D=0"}));
  falseBlock.extend(stack_.PushFromD());

  // Break Block
  CodeBlock breakBlock(std::vector<std::string>({"where", "0; JMP"}));

  // True Block
  CodeBlock trueBlock(std::vector<std::string>({"D=-1"}));
  trueBlock.extend(stack_.PushFromD());

  // Replace where
  uint32_t input1 =
      lineNum + setBlock.GetNumberOfLines() + compareBlock.GetNumberOfLines() +
      falseBlock.GetNumberOfLines() + breakBlock.GetNumberOfLines();
  compareBlock.ReplaceWhere(std::vector<std::string>({std::to_string(input1)}));
  uint32_t input2 = input1 + trueBlock.GetNumberOfLines();
  breakBlock.ReplaceWhere(std::vector<std::string>({std::to_string(input2)}));

  // Merge
  codeBuilder_.Extend(setBlock)
      .Extend(compareBlock)
      .Extend(falseBlock)
      .Extend(breakBlock)
      .Extend(trueBlock);
}

void CodeWriter::DecodeLable(BranchTokens tokens) {
  codeBuilder_.WriteLine("(" + tokens.label + ")");
}

void CodeWriter::DecodeGoto(BranchTokens tokens) {
  codeBuilder_.WriteLine("@" + tokens.label).WriteLine("0; JMP");
}

void CodeWriter::DecodeIfGoto(BranchTokens tokens) {
  // Jumps to 'label' if the value of D is "greater than 0".
  codeBuilder_.Extend(stack_.PopToD())
      .WriteLine("@" + tokens.label)
      .WriteLine("D; JGT");
}

void CodeWriter::DecodeFuncDeclare(FuncTokens tokens) {
  contextHandler_.CreateFunctionContext(tokens.funcName, tokens.n);

  codeBuilder_.WriteLine("(" + tokens.funcName + ")");
  uint32_t n = static_cast<uint32_t>(std::stoi(tokens.n));
  for (uint32_t i = 0; i < n; ++i) {
    codeBuilder_.WriteLine("@0").WriteLine("@D=A").Extend(stack_.PushFromD());
  }
}

void CodeWriter::DecodeFuncCall(FuncTokens tokens) {
  // ARG = SP - tokens.n
  CodeBlock setArg = CodeBlock::Create()
                         .WriteLine("@SP")
                         .WriteLine("D=A")
                         .WriteLine("@" + tokens.n)
                         .WriteLine("D=D-A")
                         .WriteLine("@ARG")
                         .WriteLine("M=D")
                         .build();

  codeBuilder_.Extend(setArg)
      .Extend(PushRam("SP"))  // push frame
      .Extend(PushRam("LCL"))
      .Extend(PushRam("ARG"))
      .Extend(PushRam("THIS"))
      .Extend(PushRam("THAT"))
      .WriteLine("@SP")  // LCL = SP
      .WriteLine("D=M")
      .WriteLine("@LCL")
      .WriteLine("M=D")
      .WriteLine("@" + tokens.funcName)  // jump to funcName label
      .WriteLine("0; JMP")
      .WriteLine("(" + tokens.funcName + ".RET)");  // return label
}

void CodeWriter::DecodeReturn(ReturnTokens tokens, std::string funcName) {
  // *R13 = *(LCL - 5)
  CodeBlock tempSaveSP = CodeBlock::Create()
                             .WriteLine("@5")
                             .WriteLine("D=A")
                             .WriteLine("LCL")
                             .WriteLine("A=A-D")
                             .WriteLine("D=M")
                             .WriteLine("@R13")
                             .WriteLine("M=D")
                             .build();

  // *(LCL - 5) = *(SP - 1)
  CodeBlock saveReturn = CodeBlock::Create()
                             .WriteLine("@SP")
                             .WriteLine("A=A-1")
                             .WriteLine("D=M")
                             .WriteLine("@R14")
                             .WriteLine("M=D")
                             .WriteLine("@5")
                             .WriteLine("D=A")
                             .WriteLine("LCL")
                             .WriteLine("A=A-D")
                             .WriteLine("@R15")
                             .WriteLine("M=A")
                             .WriteLine("@R14")
                             .WriteLine("D=M")
                             .WriteLine("@R15")
                             .WriteLine("M=D")
                             .build();

  // restore
  CodeBlock restoreFrame = RestoreBlock::CreateRestoreCodeBlock("R14");

  // *SP = *R13
  CodeBlock setSp = CodeBlock::Create()
                        .WriteLine("@R13")
                        .WriteLine("D=M")
                        .WriteLine("@SP")
                        .WriteLine("M=D")
                        .build();
  codeBuilder_.Extend(tempSaveSP)
      .Extend(saveReturn)
      .Extend(restoreFrame)
      .Extend(setSp)
      .WriteLine("@" + funcName)
      .WriteLine("0; JMP");

  contextHandler_.SwitchContext(tokens.operationType, codeBuilder_);
}

CodeBlock CodeWriter::PushRam(std::string ram) {
  return CodeBlock::Create()
      .WriteLine("@" + ram)
      .WriteLine("D=M")
      .Extend(stack_.PushFromD())
      .build();
}

std::string CodeWriter::GetComparisonOperator(OperationType operation) {
  if (operation == OperationType::EQ) {
    return "JEQ";
  } else if (operation == OperationType::LT) {
    return "JLT";
  } else {
    return "JGT";
  }
}

CodeBlock CodeWriter::PlaceDToTempRegister(std::string symbol) {
  return CodeBlock(std::vector<std::string>({"@" + symbol, "M=D"}));
}
