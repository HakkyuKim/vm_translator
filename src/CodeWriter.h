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
    std::string Decode(Tokens tokens);

    private:
    std::map<SegmentType, VmSegmentTranslator> segments_;
    StackSegmentTranslator stack_;
};

#endif // __CODEWRITER_H__