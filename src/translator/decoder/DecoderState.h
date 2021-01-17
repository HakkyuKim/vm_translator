#ifndef __DECODERSTATE_H__
#define __DECODERSTATE_H__

#include <string>

class DecoderState {
 public:
  DecoderState();
  void SetFile(std::string fileName);
  void CloseFile();
  std::string GetFileName();
  void SetFunc(std::string funcName);
  void CloseFunc();
  std::string GetFuncName();
  std::string NextReturnAddressCnt();
  bool isCodeReturnable();
  bool isFunction();

 private:
  int returnAddressCnt_;
  std::string fileName_;
  std::string funcName_;
};

#endif  // __DECODERSTATE_H__