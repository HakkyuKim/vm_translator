add_library(
    token_memory 
    TokenPop.cc
    TokenPush.cc
    TokenMemory.cc
)

target_include_directories(token_memory PUBLIC 
${CMAKE_SOURCE_DIR}
)