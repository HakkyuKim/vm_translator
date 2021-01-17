add_library(decoder_arithmetic
DecoderAdd.cc
DecoderEq.cc
DecoderGt.cc
DecoderLt.cc
DecoderNeg.cc
DecoderSub.cc
DecoderArithmetic.cc
)

target_include_directories(decoder_arithmetic PUBLIC ${CMAKE_SOURCE_DIR})