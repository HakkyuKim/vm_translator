#ifndef __CODEWRITER_H__
#define __CODEWRITER_H__

#include <map>
#include <string>
#include "CodeBlock.h"
#include "CodeBlockBuilder.h"
#include "ContextHandler.h"
#include "StackSegmentTranslator.h"
#include "VmSegmentTranslator.h"
#include "types.h"

#define GENERAL_PURPOSE_REGISTER_0 "R13"
#define GENERAL_PURPOSE_REGISTER_1 "R14"
#define GENERAL_PURPOSE_REGISTER_2 "R15"

class CodeWriter{
    public:
    CodeWriter(std::string fileName);
    ~CodeWriter();
    void Decode(std::shared_ptr<BaseTokens> tokens);
    uint32_t lineNumber;
    CodeBlock GenerateCode();

    private:
    CodeBlockBuilder codeBuilder_;
    ContextHandler contextHandler_;

    std::map<SegmentType, VmSegmentTranslator*> segments_;
    StackSegmentTranslator stack_;

    void DecodePushOperation(Tokens tokens);
    void DecodePopOperation(Tokens tokens);
    void DecodeAddSubOperation(ArithmeticLogicalTokens tokens);
    void DecodeNegNotOperation(ArithmeticLogicalTokens tokens);
    void DecodeAndOrOperation(ArithmeticLogicalTokens tokens);
    void DecodeComparisonOperation(ArithmeticLogicalTokens tokens, uint32_t lineNum);
    void DecodeLable(BranchTokens tokens);
    void DecodeGoto(BranchTokens tokens);
    void DecodeIfGoto(BranchTokens tokens);
    void DecodeFuncDeclare(FuncTokens tokens);
    void DecodeFuncCall(FuncTokens tokens);
    void DecodeReturn(ReturnTokens tokens, std::string funcName);

    CodeBlock PushRam(std::string ram);

    std::string GetComparisonOperator(OperationType operation);
    CodeBlock PlaceDToTempRegister(std::string symbol);
};

#endif // __CODEWRITER_H__