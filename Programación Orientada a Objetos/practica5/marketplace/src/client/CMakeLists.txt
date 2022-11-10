add_library(client client.cc client.h)
target_link_libraries(client PUBLIC person basket)
target_include_directories(client PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt

add_executable(client_main client_main.cc)
target_link_libraries(client_main client)
