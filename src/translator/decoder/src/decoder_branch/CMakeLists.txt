add_library(decoder_branch 
DecoderGoTo.cc
DecoderIfGoTo.cc
DecoderLabel.cc
DecoderBranch.cc
)
target_include_directories(decoder_branch PUBLIC ${CMAKE_SOURCE_DIR})