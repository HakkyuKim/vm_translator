#ifndef __CONSTANTSEGMENTTRANSLATOR_H__
#define __CONSTANTSEGMENTTRANSLATOR_H__

#include "VmSegmentTranslator.h"

class ConstantSegmentTranslator : public VmSegmentTranslator{
    public:
        ConstantSegmentTranslator()
        :VmSegmentTranslator(""){}
        CodeBlock CopyFromD(std::string address, std::string index) override;
        CodeBlock CopyToD(std::string address, std::string index) override;
        CodeBlock CalculateAddress(std::string address, std::string index) override;
};

#endif // __CONSTANTSEGMENTTRANSLATOR_H__