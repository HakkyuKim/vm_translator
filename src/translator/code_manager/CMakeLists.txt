add_library(code_manager 
CodeFile.cc
CodeFunction.cc
CodeManager.cc)

target_link_libraries(code_manager codeblock)
target_include_directories(code_manager PUBLIC ${CMAKE_SOURCE_DIR})