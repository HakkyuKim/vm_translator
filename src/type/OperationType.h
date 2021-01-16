#ifndef __OPERATIONTYPE_H__
#define __OPERATIONTYPE_H__

#include <stdexcept>
#include <string>

enum OperationType {
  PUSH,    // push segment value
  POP,     // pop segment value
  ADD,     // add
  SUB,     // sub
  NEG,     // neg
  EQ,      // eq
  LT,      // lt
  GT,      // gt
  AND,     // and
  OR,      // or
  NOT,     // not
  LABEL,   // label labelName
  GOTO,    // goto labelName
  IFGOTO,  // if-goto labelName
  FUNC,    // function funcName n
  CALL,    // call funcName n
  RETURN,  // return
};

class OperationTypeUtil {
 public:
  static OperationType getOperationType(std::string operationType) {
    if (operationType == "push") {
      return OperationType::PUSH;
    } else if (operationType == "pop") {
      return OperationType::POP;
    } else if (operationType == "add") {
      return OperationType::ADD;
    } else if (operationType == "sub") {
      return OperationType::SUB;
    } else if (operationType == "eq") {
      return OperationType::EQ;
    } else if (operationType == "lt") {
      return OperationType::LT;
    } else if (operationType == "gt") {
      return OperationType::GT;
    } else if (operationType == "neg") {
      return OperationType::NEG;
    } else if (operationType == "not") {
      return OperationType::NOT;
    } else if (operationType == "and") {
      return OperationType::AND;
    } else if (operationType == "or") {
      return OperationType::OR;
    } else if (operationType == "label") {
      return OperationType::LABEL;
    } else if (operationType == "goto") {
      return OperationType::GOTO;
    } else if (operationType == "if-goto") {
      return OperationType::IFGOTO;
    } else if (operationType == "function") {
      return OperationType::FUNC;
    } else if (operationType == "call") {
      return OperationType::CALL;
    } else if (operationType == "return") {
      return OperationType::RETURN;
    } else {
      throw std::invalid_argument("Undefined operation type " + operationType +
                                  "\n");
    }
  }
};

#endif  // __OPERATIONTYPE_H__
