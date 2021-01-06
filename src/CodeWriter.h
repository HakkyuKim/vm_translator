#ifndef __CODEWRITER_H__
#define __CODEWRITER_H__

#include <map>
#include <string>
#include "StackSegmentTranslator.h"
#include "types.h"
#include "VmSegmentTranslator.h"

class CodeWriter{
    public:
    CodeWriter();
    ~CodeWriter();
    std::string Decode(Tokens tokens);

    private:
    std::map<SegmentType, VmSegmentTranslator*> segments_;
    StackSegmentTranslator stack_;

    std::string DecodePushOperation(Tokens tokens);
    std::string DecodePopOperation(Tokens tokens);
    std::string DecodeAddSubOperation(Tokens tokens);

    std::string PlaceDToTempRegister(std::string symbol);
};

#endif // __CODEWRITER_H__