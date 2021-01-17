add_subdirectory(token_arithmetic)
add_subdirectory(token_branch)
add_subdirectory(token_func)
add_subdirectory(token_logic)
add_subdirectory(token_memory)

add_library(token_base TokenBase.cc)
add_library(token INTERFACE)

target_link_libraries(
    token 
    INTERFACE
    token_arithmetic
    token_branch
    token_func
    token_logic
    token_memory
)

target_include_directories(token_base PUBLIC 
${CMAKE_SOURCE_DIR}
)
