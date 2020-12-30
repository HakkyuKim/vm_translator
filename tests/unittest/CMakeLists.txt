add_library(STACK_SEGMENT_TRANSLATOR_TEST StackSegmentTranslatorUnittest.cc)

target_include_directories(STACK_SEGMENT_TRANSLATOR_TEST PUBLIC ../../src)
target_link_directories(STACK_SEGMENT_TRANSLATOR_TEST PUBLIC ../../src)
target_link_libraries(STACK_SEGMENT_TRANSLATOR_TEST STACK_SEGMENT_TRANSLATOR)