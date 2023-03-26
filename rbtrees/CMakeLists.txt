cmake_minimum_required (VERSION 3.1)
project (rbtrees VERSION 1.0 LANGUAGES CXX)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb3")

add_executable(test_bstree test_bstree.cpp rbtree.hpp rbtree_imp.hpp)
add_executable(test_rbtree test_rbtree.cpp rbtree.hpp rbtree_imp.hpp)
