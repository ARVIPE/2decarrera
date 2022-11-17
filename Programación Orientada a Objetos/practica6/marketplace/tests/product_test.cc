// product_test.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include <product.h>
#include "gtest/gtest.h"

TEST(Product, ConstructorDefaultParam) {
  Product p("33XX");
  
  EXPECT_EQ("33XX", p.get_id());
  EXPECT_EQ("empty", p.get_name());
  EXPECT_NEAR(0.0, p.get_price(), 0.001);
  EXPECT_EQ("empty", p.get_maker());
  EXPECT_EQ("empty", p.get_seller());
}

TEST(Product, ConstructorParam) {
  Product p("44XX", "Tv", 44.55, 
            "Distribuciones A", "Distribuciones B");
  
  EXPECT_EQ("44XX", p.get_id());
  EXPECT_EQ("Tv", p.get_name());
  EXPECT_NEAR(44.55, p.get_price(), 0.001);
  EXPECT_EQ("Distribuciones A", p.get_maker());
  EXPECT_EQ("Distribuciones B", p.get_seller());
}

TEST(Product, ProductSetters) {
  Product p("44XX", "Tv", 44.55, 
            "Distribuciones A", "Distribuciones B");    

  p.set_id("XX1");
  EXPECT_EQ("XX1", p.get_id());
  p.set_price(88.99);
  EXPECT_NEAR(88.99, p.get_price(), 0.001);
  p.set_maker("Maker 1");
  EXPECT_EQ("Maker 1", p.get_maker());
  p.set_seller("Seller 1");
  EXPECT_EQ("Seller 1", p.get_seller());
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}