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
}

CodeWriter::~CodeWriter()
{
    for (auto entry : segments_)
    {
        if (entry.second != nullptr)
            delete entry.second;
    }
}

CodeBlock CodeWriter::Decode(Tokens tokens)
{
    CodeBlock codeBlock;
    switch (tokens.operation)
    {
    case OperationType::POP:
        codeBlock = DecodePopOperation(tokens);
        break;
    case OperationType::PUSH:
        codeBlock = DecodePushOperation(tokens);
        break;
    case OperationType::ADD:
    case OperationType::SUB:
        codeBlock = DecodeAddSubOperation(tokens);
        break;
    case OperationType::NEG:
    case OperationType::NOT:
        codeBlock = DecodeNegNotOperation(tokens);
        break;
    case OperationType::AND:
    case OperationType::OR:
        codeBlock = DecodeAndOrOperation(tokens);
        break;
    case OperationType::EQ:
    case OperationType::LT:
    case OperationType::GT:
        codeBlock = DecodeComparisonOperation(tokens, lineNumber);
        break;
    case OperationType::LABEL:
        codeBlock = DecodeLable(BranchTokens(tokens.operation, tokens.index));
        break;
    case OperationType::GOTO:
        codeBlock = DecodeGoto(BranchTokens(tokens.operation, tokens.index));
        break;
    case OperationType::IFGOTO:
        codeBlock = DecodeIfGoto(BranchTokens(tokens.operation, tokens.index));
        break;
    default:
        break;
    }
    lineNumber += codeBlock.GetNumberOfLines();
    return codeBlock;
}

CodeBlock CodeWriter::DecodePopOperation(Tokens tokens)
{
    CodeBlock codeBlock;
    VmSegmentTranslator *segmentTranslator = segments_[tokens.segmentType];
    codeBlock.extend(segmentTranslator->CalculateAddress(GENERAL_PURPOSE_REGISTER_0, tokens.index));
    codeBlock.extend(stack_.PopToD());
    codeBlock.extend(segmentTranslator->CopyFromD(GENERAL_PURPOSE_REGISTER_0, tokens.index));
    return codeBlock;
}

CodeBlock CodeWriter::DecodePushOperation(Tokens tokens)
{
    CodeBlock codeBlock;
    VmSegmentTranslator *segmentTranslator = segments_[tokens.segmentType];
    codeBlock.extend(segmentTranslator->CalculateAddress(GENERAL_PURPOSE_REGISTER_0, tokens.index));
    codeBlock.extend(segmentTranslator->CopyToD(GENERAL_PURPOSE_REGISTER_0, tokens.index));
    codeBlock.extend(stack_.PushFromD());
    return codeBlock;
}

CodeBlock CodeWriter::DecodeAddSubOperation(Tokens tokens)
{
    std::string asmCode;
    std::string operation = tokens.operation == OperationType::ADD ? "+" : "-";
    std::string tempRegister = "R13";
    CodeBlock codeBlock;
    codeBlock.extend(stack_.PopToD());
    codeBlock.extend(PlaceDToTempRegister(tempRegister));
    codeBlock.extend(stack_.PopToD());
    codeBlock.WriteLine("@" + tempRegister);
    codeBlock.WriteLine("D=D" + operation + "M");
    codeBlock.extend(stack_.PushFromD());
    return codeBlock;
}

CodeBlock CodeWriter::DecodeNegNotOperation(Tokens tokens)
{
    std::string operation = tokens.operation == OperationType::NEG ? "-" : "!";
    CodeBlock codeBlock;
    codeBlock.extend(stack_.PopToD());
    codeBlock.WriteLine("D=" + operation + "D");
    codeBlock.extend(stack_.PushFromD());
    return codeBlock;
}

CodeBlock CodeWriter::DecodeAndOrOperation(Tokens tokens)
{
    CodeBlock codeBlock;
    std::string operation = tokens.operation == OperationType::OR ? "|" : "&";
    std::string tempRegister = "R13";
    codeBlock.extend(stack_.PopToD());
    codeBlock.extend(PlaceDToTempRegister(tempRegister));
    codeBlock.extend(stack_.PopToD());
    codeBlock.WriteLine("@" + tempRegister);
    codeBlock.WriteLine("D=D" + operation + "M");
    codeBlock.extend(stack_.PushFromD());
    return codeBlock;
}

CodeBlock CodeWriter::DecodeComparisonOperation(Tokens tokens, uint32_t lineNum)
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
    CodeBlock codeBlock;
    codeBlock.extend(setBlock);
    codeBlock.extend(compareBlock);
    codeBlock.extend(falseBlock);
    codeBlock.extend(breakBlock);
    codeBlock.extend(trueBlock);
    return codeBlock;
}

CodeBlock CodeWriter::DecodeLable(BranchTokens tokens) 
{
    return CodeBlock::Create().WriteLine("(" + tokens.label + ")").build();
}

CodeBlock CodeWriter::DecodeGoto(BranchTokens tokens) 
{
    return CodeBlock::Create().WriteLine("@" + tokens.label)
                              .WriteLine("0; JMP")
                              .build();
}

CodeBlock CodeWriter::DecodeIfGoto(BranchTokens tokens) 
{
    // Jumps to 'label' if the value of D is "greater than 0".
    return CodeBlock::Create().Extend(stack_.PopToD())
                              .WriteLine("@" + tokens.label)
                              .WriteLine("D; JGT")
                              .build();
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
