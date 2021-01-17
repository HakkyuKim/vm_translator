add_subdirectory(code_manager)
add_subdirectory(decoder)
add_subdirectory(segment)
add_subdirectory(code_block)

add_library(translator Translator.cc)

target_link_libraries(translator code_manager segment codeblock decoder)
target_link_directories(translator PUBLIC ${CMAKE_SOURCE_DIR})