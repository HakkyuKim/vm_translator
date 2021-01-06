#include <stdexcept>
#include "ConstantSegmentTranslator.h"


std::string ConstantSegmentTranslator::PutFromD() 
{
    throw std::logic_error("Putting a value to a constant stack is an invalid operation.");
}

std::string ConstantSegmentTranslator::PutToD(std::string index) 
{
    return "@" + index + "\nD=A\n";
}
