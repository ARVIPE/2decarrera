add_library(seller seller.cc seller.h)
target_link_libraries(seller PUBLIC person basket)
target_include_directories(seller PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt

add_executable(seller_main seller_main.cc)
target_link_libraries(seller_main seller)
