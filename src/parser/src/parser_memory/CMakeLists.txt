add_library(parser_memory
ParserPop.cc
ParserPush.cc
ParserMemory.cc
)

target_link_libraries(parser_memory parser_base)
target_include_directories(parser_memory PUBLIC ${CMAKE_SOURCE_DIR})