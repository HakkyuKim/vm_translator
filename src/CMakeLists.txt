add_subdirectory(parser)
add_subdirectory(token)
add_subdirectory(translator)

add_executable(driver main.cc)

target_link_libraries(driver parser translator token)
target_include_directories(driver PUBLIC ${CMAKE_SOURCE_DIR})