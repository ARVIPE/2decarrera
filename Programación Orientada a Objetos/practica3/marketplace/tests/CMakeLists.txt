# GTest include code 
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)
# End GTest include code 

# Testing persona library
add_executable(person_test person_test.cc)
target_link_libraries(person_test
 PRIVATE
  GTest::GTest
  person)
add_test(person_gtests person_test)