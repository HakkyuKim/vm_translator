add_subdirectory(src)

add_library(parser Parser.cc
                   ParseResult.cc
                   LineReader.cc)
                   
target_link_libraries(parser PUBLIC sub_parser)