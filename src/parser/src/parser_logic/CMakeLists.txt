add_library(parser_logic
ParserAnd.cc
ParserNot.cc
ParserOr.cc
ParserLogic.cc
)

target_link_libraries(parser_logic parser_base)
target_include_directories(parser_logic PUBLIC ${CMAKE_SOURCE_DIR})