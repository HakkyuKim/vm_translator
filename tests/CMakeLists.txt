add_executable(TEST main.cc)

add_subdirectory(unittest)

target_include_directories(TEST PUBLIC unittest)
target_link_directories(TEST PUBLIC unittest)
target_link_libraries(TEST STACK_SEGMENT_TRANSLATOR_TEST)