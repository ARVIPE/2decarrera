cmake_minimum_required (VERSION 3.1)
project (packet_processor)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)

add_executable(test_slist test_slist.cpp slist.hpp slist_imp.hpp)
add_executable(test_stack test_stack.cpp stack.hpp stack_imp.hpp slist.hpp
    slist_imp.hpp)
add_executable(test_queue test_queue.cpp queue.hpp queue_imp.hpp
    stack.hpp stack_imp.hpp)
add_executable(test_packet_processor test_packet_processor.cpp
    packet_processor.cpp packet_processor.hpp
    slist.hpp slist_imp.hpp
    stack.hpp stack_imp.hpp
    queue.hpp queue_imp.hpp)

