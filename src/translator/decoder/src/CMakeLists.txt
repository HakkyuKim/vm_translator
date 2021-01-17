add_subdirectory(decoder_arithmetic)
#add_subdirectory(decoder_branch)
#add_subdirectory(decoder_func)
add_subdirectory(decoder_logic)
add_subdirectory(decoder_memory)

add_library(decoder_base DecoderBase.cc)

target_link_libraries(decoder_base token segment codeblock)
target_include_directories(decoder_base PUBLIC ${CMAKE_SOURCE_DIR})

add_library(sub_decoder INTERFACE)

target_link_libraries(sub_decoder 
INTERFACE
decoder_arithmetic
#decoder_branch
#decoder_func
decoder_logic
decoder_memory
)

