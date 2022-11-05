// computer_tesc.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include <computer.h>
#include "gtest/gtest.h"

TEST(Computer, ConstructorDefaultParam) {
  Computer c("33XX", ComputerType::Desktop);
  
  EXPECT_EQ("33XX", c.get_id());
  EXPECT_EQ(ComputerType::Desktop, c.get_type());
  EXPECT_EQ("empty", c.get_name());
  EXPECT_NEAR(0.0, c.get_price(), 0.001);
  EXPECT_EQ("empty", c.get_maker());
  EXPECT_EQ("empty", c.get_seller());
}


TEST(Computer, ConstructorParam) {
  Computer c("44XX", ComputerType::Tablet, "Sun Computer 100X1", 1244.55, 
            "Distribuciones A", "Distribuciones B");
  
  EXPECT_EQ("44XX", c.get_id());
  EXPECT_EQ(ComputerType::Tablet, c.get_type());
  EXPECT_EQ("Sun Computer 100X1", c.get_name());
  EXPECT_NEAR(1244.55, c.get_price(), 0.001);
  EXPECT_EQ("Distribuciones A", c.get_maker());
  EXPECT_EQ("Distribuciones B", c.get_seller());
}

TEST(Computer, ComputerSetters) {
  Computer c("44XX", ComputerType::Tablet, "Sun Computer 100X1", 1244.55, 
            "Distribuciones A", "Distribuciones B");

  c.set_id("XX1");
  EXPECT_EQ("XX1", c.get_id());
  c.set_price(88.99);
  EXPECT_NEAR(88.99, c.get_price(), 0.001);
  c.set_maker("Maker 1");
  EXPECT_EQ("Maker 1", c.get_maker());
  c.set_seller("Seller 1");
  EXPECT_EQ("Seller 1", c.get_seller());
  c.set_type(ComputerType::Gaming);
  EXPECT_EQ(ComputerType::Gaming, c.get_type());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}