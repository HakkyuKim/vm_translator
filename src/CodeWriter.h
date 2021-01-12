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
    void Decode(Tokens tokens);
    uint32_t lineNumber;
    CodeBlock GenerateCode();

    private:
    CodeBlockBuilder codeBuilder_;
    ContextHandler contextHandler_;

    std::map<SegmentType, VmSegmentTranslator*> segments_;
    StackSegmentTranslator stack_;

    void DecodePushOperation(Tokens tokens);
    void DecodePopOperation(Tokens tokens);
    void DecodeAddSubOperation(Tokens tokens);
    void DecodeNegNotOperation(Tokens tokens);
    void DecodeAndOrOperation(Tokens tokens);
    void DecodeComparisonOperation(Tokens tokens, uint32_t lineNum);
    void DecodeLable(BranchTokens tokens);
    void DecodeGoto(BranchTokens tokens);
    void DecodeIfGoto(BranchTokens tokens);

    std::string GetComparisonOperator(OperationType operation);
    CodeBlock PlaceDToTempRegister(std::string symbol);
};

#endif // __CODEWRITER_H__