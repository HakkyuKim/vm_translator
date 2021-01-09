#ifndef __TEMPSEGMENTTRANSLATOR_H__
#define __TEMPSEGMENTTRANSLATOR_H__

#include "VmSegmentTranslator.h"

class TempSegmentTranslator : public VmSegmentTranslator {
public:
        TempSegmentTranslator()
        :VmSegmentTranslator(""){}
        CodeBlock CalculateAddress(std::string address, std::string index) override;
};

#endif // __TEMPSEGMENTTRANSLATOR_H__