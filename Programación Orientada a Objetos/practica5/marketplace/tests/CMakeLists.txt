# GTest include code for fetch content over the internet 
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

# Testing person library
add_executable(person_test person_test.cc)
target_link_libraries(person_test
PRIVATE GTest::GTest person)
add_test(person_gtests person_test)

# Testing product library
add_executable(product_test product_test.cc)
target_link_libraries(product_test
PRIVATE GTest::GTest product)
add_test(product_gtests product_test)

# Testing tv library
add_executable(tv_test tv_test.cc)
target_link_libraries(tv_test
PRIVATE GTest::GTest tv)
add_test(tv_gtests tv_test)

# Testing computer library
add_executable(computer_test computer_test.cc)
target_link_libraries(computer_test
PRIVATE GTest::GTest computer)
add_test(computer_gtests computer_test)

# Testing basket library
add_executable(basket_test basket_test.cc)
target_link_libraries(basket_test
PRIVATE GTest::GTest basket)
add_test(basket_gtests basket_test)