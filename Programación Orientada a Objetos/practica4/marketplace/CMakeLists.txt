cmake_minimum_required(VERSION 3.16)

# The top-level CMakeLists.txt file must
project(Marketplace LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enables testing/add_test() for this directory and below
enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
