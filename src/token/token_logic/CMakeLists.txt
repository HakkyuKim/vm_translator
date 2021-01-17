add_library(token_logic 
                             TokenAnd.cc
                             TokenNot.cc
                             TokenOr.cc
                             TokenLogic.cc
)

target_link_libraries(token_logic token_base)
target_include_directories(token_logic PUBLIC ${CMAKE_SOURCE_DIR})