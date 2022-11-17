add_library(market market.cc)
target_include_directories(market PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt

add_executable(market_main market_main.cc)
target_link_libraries(market_main market)