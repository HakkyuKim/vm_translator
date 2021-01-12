#include <iostream>
#include <vector>
#include "CodeWriter.h"
#include "CodeBlockBuilder.h"
#include "ConstantSegmentTranslator.h"
#include "StaticSegmentTranslator.h"
#include "TempSegmentTranslator.h"
#include "PointerSegmentTranslator.h"

CodeWriter::CodeWriter(std::string fileName)
{
    segments_ = {
        {SegmentType::CONSTANT, new ConstantSegmentTranslator()},
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

CodeWriter::~CodeWriter()
{
    for (auto entry : segments_)
    {
        if (entry.second != nullptr)
            delete entry.second;
    }
}

void CodeWriter::Decode(Tokens tokens)
{
    switch (tokens.operation)
    {
    case OperationType::POP:
        DecodePopOperation(tokens);
        break;
    case OperationType::PUSH:
        DecodePushOperation(tokens);
        break;
    case OperationType::ADD:
    case OperationType::SUB:
        DecodeAddSubOperation(tokens);
        break;
    case OperationType::NEG:
    case OperationType::NOT:
        DecodeNegNotOperation(tokens);
        break;
    case OperationType::AND:
    case OperationType::OR:
        DecodeAndOrOperation(tokens);
        break;
    case OperationType::EQ:
    case OperationType::LT:
    case OperationType::GT:
        DecodeComparisonOperation(tokens, lineNumber);
        break;
    case OperationType::LABEL:
        DecodeLable(BranchTokens(tokens.operation, tokens.index));
        break;
    case OperationType::GOTO:
        DecodeGoto(BranchTokens(tokens.operation, tokens.index));
        break;
    case OperationType::IFGOTO:
        DecodeIfGoto(BranchTokens(tokens.operation, tokens.index));
        break;
    default:
        break;
    }
    contextHandler_.SwitchContext(tokens.operation, codeBuilder_);
    lineNumber = codeBuilder_.GetLineNumbers();
}

CodeBlock CodeWriter::GenerateCode() 
{
    contextHandler_.SwitchContext(OperationType::END, codeBuilder_);
    CodeBlock codeBlock = contextHandler_.Merge();
    return codeBlock;
}

void CodeWriter::DecodePopOperation(Tokens tokens)
{
    VmSegmentTranslator *segmentTranslator = segments_[tokens.segmentType];
    codeBuilder_.Extend(segmentTranslator->CalculateAddress(GENERAL_PURPOSE_REGISTER_0, tokens.index))
                .Extend(stack_.PopToD())
                .Extend(segmentTranslator->CopyFromD(GENERAL_PURPOSE_REGISTER_0, tokens.index));
}

void CodeWriter::DecodePushOperation(Tokens tokens)
{
    VmSegmentTranslator *segmentTranslator = segments_[tokens.segmentType];
    codeBuilder_.Extend(segmentTranslator->CalculateAddress(GENERAL_PURPOSE_REGISTER_0, tokens.index))
                .Extend(segmentTranslator->CopyToD(GENERAL_PURPOSE_REGISTER_0, tokens.index))
                .Extend(stack_.PushFromD());
}

void CodeWriter::DecodeAddSubOperation(Tokens tokens)
{
    std::string asmCode;
    std::string operation = tokens.operation == OperationType::ADD ? "+" : "-";
    std::string tempRegister = "R13";

    codeBuilder_.Extend(stack_.PopToD())
    .Extend(PlaceDToTempRegister(tempRegister))
    .Extend(stack_.PopToD())
    .WriteLine("@" + tempRegister)
    .WriteLine("D=D" + operation + "M")
    .Extend(stack_.PushFromD());
}

void CodeWriter::DecodeNegNotOperation(Tokens tokens)
{
    std::string operation = tokens.operation == OperationType::NEG ? "-" : "!";
    codeBuilder_.Extend(stack_.PopToD())
    .WriteLine("D=" + operation + "D")
    .Extend(stack_.PushFromD());
}

void CodeWriter::DecodeAndOrOperation(Tokens tokens)
{
    std::string operation = tokens.operation == OperationType::OR ? "|" : "&";
    std::string tempRegister = "R13";
    codeBuilder_.Extend(stack_.PopToD())
    .Extend(PlaceDToTempRegister(tempRegister))
    .Extend(stack_.PopToD())
    .WriteLine("@" + tempRegister)
    .WriteLine("D=D" + operation + "M")
    .Extend(stack_.PushFromD());
}

void CodeWriter::DecodeComparisonOperation(Tokens tokens, uint32_t lineNum)
{
    std::string operation = GetComparisonOperator(tokens.operation);
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
    uint32_t input1 = lineNum + setBlock.GetNumberOfLines() + compareBlock.GetNumberOfLines() +  falseBlock.GetNumberOfLines() + breakBlock.GetNumberOfLines();
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

void CodeWriter::DecodeLable(BranchTokens tokens) 
{
    codeBuilder_.WriteLine("(" + tokens.label + ")");
}

void CodeWriter::DecodeGoto(BranchTokens tokens) 
{
    codeBuilder_.WriteLine("@" + tokens.label)
                              .WriteLine("0; JMP");
}

void CodeWriter::DecodeIfGoto(BranchTokens tokens) 
{
    // Jumps to 'label' if the value of D is "greater than 0".
    codeBuilder_.Extend(stack_.PopToD())
                              .WriteLine("@" + tokens.label)
                              .WriteLine("D; JGT");
}

std::string CodeWriter::GetComparisonOperator(OperationType operation)
{
    if (operation == OperationType::EQ)
    {
        return "JEQ";
    }
    else if (operation == OperationType::LT)
    {
        return "JLT";
    }
    else
    {
        return "JGT";
    }
}

CodeBlock CodeWriter::PlaceDToTempRegister(std::string symbol)
{
    return CodeBlock(std::vector<std::string>({"@" + symbol, "M=D"}));
}
