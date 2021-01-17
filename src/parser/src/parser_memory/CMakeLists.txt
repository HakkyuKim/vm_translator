add_library(parser_memory
ParserPop.cc
ParserPush.cc
ParserMemory.cc
)
target_include_directories(parser_memory PUBLIC ${CMAKE_SOURCE_DIR})