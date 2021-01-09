#ifndef __STATICSEGMENTTRANSLATOR_H__
#define __STATICSEGMENTTRANSLATOR_H__

#include "VmSegmentTranslator.h"

class StaticSegmentTranslator : public VmSegmentTranslator {
public:
        StaticSegmentTranslator(std::string vmFileName)
        :fileName_(vmFileName), VmSegmentTranslator(""){}
        CodeBlock CopyFromD(std::string address, std::string index) override;
        CodeBlock CopyToD(std::string address, std::string index) override;
        CodeBlock CalculateAddress(std::string address, std::string index) override;
private:
        std::string fileName_;
};

#endif // __STATICSEGMENTTRANSLATOR_H__