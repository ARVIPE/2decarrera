add_library(computer computer.cc)
target_include_directories(computer PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt

add_executable(computer_main computer_main.cc)
target_link_libraries(computer_main computer)
