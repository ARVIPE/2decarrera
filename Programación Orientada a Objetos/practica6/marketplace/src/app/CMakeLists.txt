add_library(app app_main.cc)
target_link_libraries(app PUBLIC market product)
target_include_directories(app PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/product
                          ${PROJECT_SOURCE_DIR}/src/market)
add_executable(app_main app_main.cc)
target_link_libraries(app_main PUBLIC market product)