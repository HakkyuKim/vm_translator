add_library(parser_branch
ParserGoTo.cc
ParserIfGoTo.cc
ParserLabel.cc
ParserBranch.cc
)

target_include_directories(parser_branch PUBLIC ${CMAKE_SOURCE_DIR})