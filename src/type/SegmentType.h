#ifndef __SEGMENTTYPE_H__
#define __SEGMENTTYPE_H__

#include <stdexcept>
#include <string>

enum SegmentType {
  STATIC,
  LOCAL,
  ARGUMENT,
  CONSTANT,
  THIS,
  THAT,
  POINTER,
  TEMP
};

class SegmentTypeUtil {
 public:
  static SegmentType getSegmentType(std::string segmentType) {
    if (segmentType == "static") {
      return SegmentType::STATIC;
    } else if (segmentType == "local") {
      return SegmentType::LOCAL;
    } else if (segmentType == "argument") {
      return SegmentType::ARGUMENT;
    } else if (segmentType == "constant") {
      return SegmentType::CONSTANT;
    } else if (segmentType == "this") {
      return SegmentType::THIS;
    } else if (segmentType == "that") {
      return SegmentType::THAT;
    } else if (segmentType == "pointer") {
      return SegmentType::POINTER;
    } else if (segmentType == "temp") {
      return SegmentType::TEMP;
    } else {
      throw std::invalid_argument("Undefined virtual segment type " +
                                  segmentType + "\n");
    }
  }
};
#endif  // __SEGMENTTYPE_H__