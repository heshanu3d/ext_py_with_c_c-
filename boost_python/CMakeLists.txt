set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

add_py_module(test test.cpp -lboost_python310)
add_py_module(hello hello.cpp -lboost_python310)
