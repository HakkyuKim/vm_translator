add_subdirectory(parser_arithmetic)
add_subdirectory(parser_branch)
add_subdirectory(parser_func)
add_subdirectory(parser_logic)
add_subdirectory(parser_memory)

add_library(parser_base ParserBase.cc)

target_link_libraries(parser_base token)
target_include_directories(parser_base PUBLIC ${CMAKE_SOURCE_DIR})


add_library(sub_parser INTERFACE)

target_link_libraries(sub_parser INTERFACE 
parser_arithmetic
parser_branch
parser_func
parser_logic
parser_memory
)
