add_library(parser_arithmetic 
ParserAdd.cc
ParserEq.cc
ParserGt.cc
ParserLt.cc
ParserNeg.cc
ParserSub.cc
ParserArithmetic.cc
)

target_link_libraries(parser_arithmetic parser_base)
target_include_directories(parser_arithmetic PUBLIC ${CMAKE_SOURCE_DIR})