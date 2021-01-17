#include "StackSegment.h"

StackSegment::StackSegment(std::shared_ptr<CodeBlockBuilder> codeBlockBuilder)
    : codeBlockBuilder_(codeBlockBuilder) {}

void StackSegment::PushFromD() {
  (*codeBlockBuilder_).WriteLine("@SP").WriteLine("A=M").WriteLine("M=D");
  IncreaseSP();
}

void StackSegment::PopToD() {
  DecreaseSP();
  (*codeBlockBuilder_).WriteLine("@SP").WriteLine("A=M").WriteLine("D=M");
}

void StackSegment::IncreaseSP() {
  (*codeBlockBuilder_).WriteLine("@SP").WriteLine("M=M+1");
}

void StackSegment::DecreaseSP() {
  (*codeBlockBuilder_).WriteLine("@SP").WriteLine("M=M-1");
}
