add_library(token_arithmetic TokenAdd.cc
                             TokenEq.cc
                             TokenGt.cc
                             TokenLt.cc
                             TokenNeg.cc
                             TokenSub.cc
                             TokenArithmetic.cc)

target_include_directories(token_arithmetic PUBLIC ${CMAKE_SOURCE_DIR})