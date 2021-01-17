cmake_minimum_required(VERSION 3.10)

project(vm_translator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(src)
add_subdirectory(tests)

#add_executable(vm_translator src/main.cc
#                             src/CodeWriter.h
#                             src/LineReader.h
#                             src/Parser.h)
#target_include_directories(vm_translator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
#target_link_directories(vm_translator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
#target_link_libraries(vm_translator CODE_WRITER
#                                    LINE_READER
#                                    PARSER)
