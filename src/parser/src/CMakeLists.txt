add_subdirectory(parser_arithmetic)
add_subdirectory(parser_branch)
add_subdirectory(parser_func)
add_subdirectory(parser_logic)
add_subdirectory(parser_memory)

add_library(sub_parser ParserBase.cc)

target_link_libraries(sub_parser PUBLIC 
parser_arithmetic
parser_branch
parser_func
parser_logic
parser_memory
)

target_include_directories(sub_parser PUBLIC ${CMAKE_SOURCE_DIR})