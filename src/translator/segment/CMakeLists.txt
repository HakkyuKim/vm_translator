add_library(segment VmSegment.cc
                    ConstantSegment.cc
                    StaticSegment.cc
                    TempSegment.cc
                    PointerSegment.cc
                    LocalSegment.cc
                    ArgumentSegment.cc
                    ThisSegment.cc
                    ThatSegment.cc
                    StackSegment.cc)

target_link_libraries(segment codeblock decoder_state)
target_include_directories(segment PUBLIC ${CMAKE_SOURCE_DIR})