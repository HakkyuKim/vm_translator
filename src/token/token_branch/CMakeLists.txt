add_library(
    token_branch 
    TokenGoTo.cc
    TokenIfGoTo.cc
    TokenLabel.cc
    TokenBranch.cc
)

target_link_libraries(token_branch token_base)
target_include_directories(token_branch PUBLIC ${CMAKE_SOURCE_DIR})