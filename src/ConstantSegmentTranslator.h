#ifndef __CONSTANTSEGMENTTRANSLATOR_H__
#define __CONSTANTSEGMENTTRANSLATOR_H__

#include "VmSegmentTranslator.h"

class ConstantSegmentTranslator : public VmSegmentTranslator{
    public:
        ConstantSegmentTranslator()
        :VmSegmentTranslator("constant"){}
        std::string PutFromD() override;
        std::string PutToD(std::string index) override;
};

#endif // __CONSTANTSEGMENTTRANSLATOR_H__