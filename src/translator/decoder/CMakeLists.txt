add_subdirectory(src)

add_library(decoder Decoder.cc
                      DecodeResult.cc
                      DecoderState.cc
                      )

target_link_libraries(decoder sub_decoder)
target_include_directories(decoder PUBLIC ${CMAKE_SOURCE_DIR})