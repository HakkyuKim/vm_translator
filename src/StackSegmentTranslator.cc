#include "StackSegmentTranslator.h"

std::string StackSegmentTranslator::PushFromD(){
    std::string vmCode = "@SP\nA=M\nM=D\n";
    vmCode += IncreaseSP();
    return vmCode;
}

std::string StackSegmentTranslator::PopToD(){
    std::string vmCode = "@SP\nA=M\nD=M\n";
    vmCode += DecreaseSP();
    return vmCode;
}

std::string StackSegmentTranslator::IncreaseSP(){
    std::string vmCode = "@SP\nM=M+1\n";
    return vmCode;
}

std::string StackSegmentTranslator::DecreaseSP(){
    std::string vmCode = "@SP\nM=M-1\n";
    return vmCode;
}