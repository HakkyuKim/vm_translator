#include <iostream>
#include "CodeWriter.h"

CodeWriter::CodeWriter() 
{
    segments_ = {
        {SegmentType::CONSTANT, VmSegmentTranslator("constant")},
        {SegmentType::STATIC, VmSegmentTranslator("static")},
        {SegmentType::LOCAL, VmSegmentTranslator("local")},
        {SegmentType::ARGUMENT, VmSegmentTranslator("argument")},
        {SegmentType::TEMP, VmSegmentTranslator("temp")},
        {SegmentType::THIS, VmSegmentTranslator("this")},
        {SegmentType::THAT, VmSegmentTranslator("that")},
        {SegmentType::POINTER, VmSegmentTranslator("pointer")}
    };
}

std::string CodeWriter::Decode(Tokens tokens) 
{
    std::string asmCode = "";
    VmSegmentTranslator segmentTranslator = segments_[tokens.segmentType];
    if(tokens.operation == OperationType::POP){
        asmCode += segmentTranslator.PutToD(tokens.index);
        asmCode += stack_.PushFromD();
    }
    else{ 
        // OperationType::PUSH
        asmCode += segmentTranslator.SetLocationOverwrite(tokens.index);
        asmCode += stack_.PopToD();
        asmCode += segmentTranslator.PutFromD();
        asmCode += segmentTranslator.SetLocationOverwrite("-" + tokens.index);
    }
    return asmCode;
}
