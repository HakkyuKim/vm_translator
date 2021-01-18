add_subdirectory(src)

add_library(decoder Decoder.cc
                      DecodeResult.cc
                      DecoderState.cc
                      )

target_link_libraries(decoder sub_decoder)
target_include_directories(decoder PUBLIC ${CMAKE_SOURCE_DIR})

add_library(decoder_state DecoderState.cc)
target_link_libraries(decoder_state codeblock)
target_include_directories(decoder_state PUBLIC ${CMAKE_SOURCE_DIR})
