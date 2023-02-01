add_executable(main main.c)

set(PYTHON_INCLUDE_DIR "/usr/include/python3.10")

add_library(spam spammodule.c)
target_include_directories(spam PRIVATE ${PYTHON_INCLUDE_DIR})
target_link_libraries(spam PRIVATE ${PYTHON_LIBRARIES})
set_target_properties(spam PROPERTIES PREFIX "")

target_include_directories(main PRIVATE ${PYTHON_INCLUDE_DIR})
target_link_libraries(main PRIVATE ${PYTHON_LIBRARIES} spam)
