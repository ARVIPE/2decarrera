cmake_minimum_required (VERSION 3.1)
project (binary_tree)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)

add_executable(test_btree_node test_btree_node.cpp btree.hpp btree_imp.hpp)
add_executable(test_btree test_btree.cpp btree.hpp btree_imp.hpp
    btree_utils.hpp btree_utils_imp.hpp)
