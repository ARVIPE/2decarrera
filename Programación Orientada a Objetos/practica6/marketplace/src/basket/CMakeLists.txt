add_library(basket basket.cc)
target_include_directories(basket PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt

add_executable(basket_main basket_main.cc)
target_link_libraries(basket_main basket)