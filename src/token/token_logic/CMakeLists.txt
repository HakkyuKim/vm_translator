add_library(token_logic 
                             TokenAnd.cc
                             TokenNot.cc
                             TokenOr.cc
                             TokenLogic.cc
)

target_include_directories(token_logic PUBLIC ${CMAKE_SOURCE_DIR})