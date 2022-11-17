add_library(tv tv.cc)
target_include_directories(tv PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt

add_executable(tv_main tv_main.cc)
target_link_libraries(tv_main tv)
