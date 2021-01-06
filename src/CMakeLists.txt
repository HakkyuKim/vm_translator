add_library(STACK_SEGMENT_TRANSLATOR StackSegmentTranslator.h StackSegmentTranslator.cc)
add_library(VM_SEGMENT_TRANSLATOR VmSegmentTranslator.h 
                                  VmSegmentTranslator.cc
                                  ConstantSegmentTranslator.h
                                  ConstantSegmentTranslator.cc)

add_library(CODE_WRITER types.h
                        StackSegmentTranslator.h
                        VmSegmentTranslator.h
                        CodeWriter.h 
                        CodeWriter.cc)

target_link_libraries(CODE_WRITER STACK_SEGMENT_TRANSLATOR VM_SEGMENT_TRANSLATOR)