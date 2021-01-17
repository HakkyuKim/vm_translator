add_library(decoder_logic 
DecoderAnd.cc
DecoderOr.cc
DecoderNot.cc
DecoderLogic.cc
)

target_include_directories(decoder_logic PUBLIC ${CMAKE_SOURCE_DIR})