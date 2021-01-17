add_library(parser_func
ParserCall.cc
ParserFunction.cc
ParserReturn.cc
ParserFunc.cc
)

target_include_directories(parser_func PUBLIC ${CMAKE_SOURCE_DIR})