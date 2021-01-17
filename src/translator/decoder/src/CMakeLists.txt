#add_subdirectory(decoder_arithmetic)
#add_subdirectory(decoder_branch)
#add_subdirectory(decoder_func)
#add_subdirectory(decoder_logic)
add_subdirectory(decoder_memory)

add_library(sub_decoder DecoderBase.cc)

target_link_libraries(sub_decoder 
#decoder_arithmetic
#decoder_branch
#decoder_func
#decoder_logic
decoder_memory
)

target_include_directories(sub_decoder PUBLIC ${CMAKE_SOURCE_DIR})
