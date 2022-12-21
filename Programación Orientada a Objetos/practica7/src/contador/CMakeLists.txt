add_library(contador contador.cc)
target_include_directories(contador PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt

add_executable(contador_main contador_main.cc)
target_link_libraries(contador_main contador)
