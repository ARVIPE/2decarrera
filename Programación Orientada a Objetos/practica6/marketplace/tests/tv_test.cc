// tv_test.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include <tv.h>
#include "gtest/gtest.h"

TEST(Tv, ConstructorDefaultParam) {
  Tv t("33XX");
  
  EXPECT_EQ("33XX", t.get_id());
  EXPECT_EQ("empty", t.get_name());
  EXPECT_NEAR(0.0, t.get_price(), 0.001);
  EXPECT_EQ("empty", t.get_maker());
  EXPECT_EQ("empty", t.get_seller());
  EXPECT_NEAR(0.0, t.get_inch(), 0.001);
}

TEST(Tv, ConstructorParam) {
  Tv t("44XX", "Sun tv 100X1", 1244.55, 
            "Distribuciones A", "Distribuciones B",
            50);
  
  EXPECT_EQ("44XX", t.get_id());
  EXPECT_EQ("Sun tv 100X1", t.get_name());
  EXPECT_NEAR(1244.55, t.get_price(), 0.001);
  EXPECT_EQ("Distribuciones A", t.get_maker());
  EXPECT_EQ("Distribuciones B", t.get_seller());
  EXPECT_NEAR(50, t.get_inch(), 0.001);
}

TEST(Tv, TvSetters) {
  Tv t("44XX", "Tv", 44.55, 
            "Distribuciones A", "Distribuciones B");

  t.set_id("XX1");
  EXPECT_EQ("XX1", t.get_id());
  t.set_price(88.99);
  EXPECT_NEAR(88.99, t.get_price(), 0.001);
  t.set_maker("Maker 1");
  EXPECT_EQ("Maker 1", t.get_maker());
  t.set_seller("Seller 1");
  EXPECT_EQ("Seller 1", t.get_seller());
  EXPECT_NEAR(0.0, t.get_inch(), 0.001);
  EXPECT_TRUE(t.set_inch(60.6));
  EXPECT_NEAR(60.6, t.get_inch(), 0.001);
}

TEST(Tv, Tv_set_inch) {
  Tv t("44XX");    

  EXPECT_NEAR(0.0, t.get_inch(), 0.001);
  EXPECT_TRUE(t.set_inch(60.6));
  EXPECT_NEAR(60.6, t.get_inch(), 0.001);
  EXPECT_FALSE(t.set_inch(-100));
  EXPECT_NEAR(60.6, t.get_inch(), 0.001);
  EXPECT_FALSE(t.set_inch(0));
  EXPECT_NEAR(60.6, t.get_inch(), 0.001);  
  EXPECT_FALSE(t.set_inch(-0.001));
  EXPECT_NEAR(60.6, t.get_inch(), 0.001);  
  EXPECT_TRUE(t.set_inch(0.1));
  EXPECT_NEAR(0.1, t.get_inch(), 0.001);  
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}