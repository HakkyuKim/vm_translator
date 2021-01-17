add_library(decoder_memory 
DecoderPop.cc
DecoderPush.cc
DecoderMemory.cc
)

target_link_libraries(decoder_memory decoder_base)
target_include_directories(decoder_memory PUBLIC ${CMAKE_SOURCE_DIR})