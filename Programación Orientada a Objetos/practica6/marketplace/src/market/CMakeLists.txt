add_library(market market.cc market.h)
target_link_libraries(market PUBLIC client)
target_include_directories(basket PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt
add_executable(market_main market_main.cc)
target_link_libraries(market_main PUBLIC market client)