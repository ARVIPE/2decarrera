add_library(person person.cc)
target_include_directories(person PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt

add_executable(person_main person_main.cc)
target_link_libraries(person_main person)
