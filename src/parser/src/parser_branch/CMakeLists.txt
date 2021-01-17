add_library(parser_branch
ParserGoTo.cc
ParserIfGoTo.cc
ParserLabel.cc
ParserBranch.cc
)

target_link_libraries(parser_branch parser_base)
target_include_directories(parser_branch PUBLIC ${CMAKE_SOURCE_DIR})