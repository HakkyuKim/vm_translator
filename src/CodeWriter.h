#ifndef __CODEWRITER_H__
#define __CODEWRITER_H__

#include <map>
#include <string>
#include "CodeBlock.h"
#include "StackSegmentTranslator.h"
#include "types.h"
#include "VmSegmentTranslator.h"

#define GENERAL_PURPOSE_REGISTER_0 "R13"
#define GENERAL_PURPOSE_REGISTER_1 "R14"
#define GENERAL_PURPOSE_REGISTER_2 "R15"

class CodeWriter{
    public:
    CodeWriter(std::string fileName);
    ~CodeWriter();
    CodeBlock Decode(Tokens tokens);
    uint32_t lineNumber;

    private:
    std::map<SegmentType, VmSegmentTranslator*> segments_;
    StackSegmentTranslator stack_;

    CodeBlock DecodePushOperation(Tokens tokens);
    CodeBlock DecodePopOperation(Tokens tokens);
    CodeBlock DecodeAddSubOperation(Tokens tokens);
    CodeBlock DecodeNegNotOperation(Tokens tokens);
    CodeBlock DecodeAndOrOperation(Tokens tokens);
    CodeBlock DecodeComparisonOperation(Tokens tokens, uint32_t lineNum);
    CodeBlock DecodeLable(BranchTokens tokens);
    CodeBlock DecodeGoto(BranchTokens tokens);
    CodeBlock DecodeIfGoto(BranchTokens tokens);

    std::string GetComparisonOperator(OperationType operation);
    CodeBlock PlaceDToTempRegister(std::string symbol);
};

#endif // __CODEWRITER_H__