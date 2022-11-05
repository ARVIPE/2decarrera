add_library(product product.cc)
target_include_directories(product PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt

add_executable(product_main product_main.cc)
target_link_libraries(product_main product)
