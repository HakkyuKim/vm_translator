add_library(parser_func
ParserCall.cc
ParserFunction.cc
ParserReturn.cc
ParserFunc.cc
)

target_link_libraries(parser_func parser_base)
target_include_directories(parser_func PUBLIC ${CMAKE_SOURCE_DIR})