add_library(token_func 
                             TokenCall.cc
                             TokenFunction.cc
                             TokenReturn.cc
                             TokenFunc.cc)

                             target_include_directories(token_func PUBLIC ${CMAKE_SOURCE_DIR})

                             target_link_libraries(token_func token_base)