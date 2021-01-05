add_library(UNIT_TESTS StackSegmentTranslatorUnittest.cc 
                                    VmSegmentTranslatorUnittest.cc
                                    CodeWriterUnittest.cc)

target_include_directories(UNIT_TESTS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_directories(UNIT_TESTS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(UNIT_TESTS STACK_SEGMENT_TRANSLATOR 
                                                    VM_SEGMENT_TRANSLATOR
                                                    CODE_WRITER)