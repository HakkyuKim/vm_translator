#include <iostream>
#include "CodeWriter.h"
#include "ConstantSegmentTranslator.h"

CodeWriter::CodeWriter() 
{
    segments_ = {
        {SegmentType::CONSTANT, new ConstantSegmentTranslator()},
        {SegmentType::STATIC, new VmSegmentTranslator("static")},
        {SegmentType::LOCAL, new VmSegmentTranslator("local")},
        {SegmentType::ARGUMENT, new VmSegmentTranslator("argument")},
        {SegmentType::TEMP, new VmSegmentTranslator("temp")},
        {SegmentType::THIS, new VmSegmentTranslator("this")},
        {SegmentType::THAT, new VmSegmentTranslator("that")},
        {SegmentType::POINTER, new VmSegmentTranslator("pointer")}
    };
}

CodeWriter::~CodeWriter() 
{
    for(auto entry : segments_){
        if(entry.second != nullptr) delete entry.second;
    }
}

std::string CodeWriter::Decode(Tokens tokens) 
{
    std::string asmCode = "";
    switch(tokens.operation){
        case OperationType::POP:
        asmCode = DecodePopOperation(tokens);
        break;
        case OperationType::PUSH:
        asmCode = DecodePushOperation(tokens);
        break;
        case OperationType::ADD:
        case OperationType::SUB:
        asmCode = DecodeAddSubOperation(tokens);
        break;
        default:
        break;
    }
    return asmCode;
}

std::string CodeWriter::DecodePopOperation(Tokens tokens) 
{
    std::string asmCode;
    VmSegmentTranslator *segmentTranslator = segments_[tokens.segmentType];
    asmCode += segmentTranslator->SetLocationOverwrite(tokens.index);
    asmCode += stack_.PopToD();
    asmCode += segmentTranslator->PutFromD();
    asmCode += segmentTranslator->SetLocationOverwrite("-" + tokens.index);
    return asmCode;
}

std::string CodeWriter::DecodePushOperation(Tokens tokens) 
{
    std::string asmCode;
    VmSegmentTranslator *segmentTranslator = segments_[tokens.segmentType];
    asmCode += segmentTranslator->PutToD(tokens.index);
    asmCode += stack_.PushFromD();
    return asmCode;
}

std::string CodeWriter::DecodeAddSubOperation(Tokens tokens) 
{
    std::string asmCode;
    std::string operation = tokens.operation == OperationType::ADD ? "+" : "-";
    std::string tempRegister = "R13";
    asmCode += stack_.PopToD();
    asmCode += PlaceDToTempRegister(tempRegister);
    asmCode += stack_.PopToD();
    asmCode += "@" + tempRegister +"\nD=D" + operation +"M\n";
    asmCode += stack_.PushFromD();
    return asmCode;
}

std::string CodeWriter::PlaceDToTempRegister(std::string symbol)
{
    std::string asmCode;
    asmCode += "@" + symbol + "\n";
    asmCode += "M=D\n";
    return asmCode;
}
