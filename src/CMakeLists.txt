add_library(CODE_BLOCK CodeBlock.h 
                       CodeBlock.cc
                       CodeBlockBuilder.h
                       CodeBlockBuilder.cc)

add_library(CONTEXT Context.h
                    ContextHandler.h
                    ContextHandler.cc
                    FileContext.h
                    FileContext.cc
                    FunctionContext.h
                    FunctionContext.cc
                    CodeBlock.h
                    CodeBlock.cc)
                       
add_library(STACK_SEGMENT_TRANSLATOR StackSegmentTranslator.h StackSegmentTranslator.cc)
add_library(VM_SEGMENT_TRANSLATOR VmSegmentTranslator.h 
                                  VmSegmentTranslator.cc
                                  ConstantSegmentTranslator.h
                                  ConstantSegmentTranslator.cc
                                  StaticSegmentTranslator.h
                                  StaticSegmentTranslator.cc
                                  TempSegmentTranslator.h
                                  TempSegmentTranslator.cc
                                  PointerSegmentTranslator.h
                                  PointerSegmentTranslator.cc)

add_library(CODE_WRITER CodeWriter.h 
                        CodeWriter.cc)

target_link_libraries(CODE_WRITER STACK_SEGMENT_TRANSLATOR VM_SEGMENT_TRANSLATOR CODE_BLOCK CONTEXT)

add_library(LINE_READER LineReader.h LineReader.cc)
add_library(PARSER Parser.h Parser.cc)
