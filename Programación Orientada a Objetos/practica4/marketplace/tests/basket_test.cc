// basket_tesc.cc: Juan A. Romero
// Testing class Basket

#include <basket.h>
#include "gtest/gtest.h"

TEST(Basket, ConstructorDefaultParam) {
  Basket c("X7j");
  
  EXPECT_EQ("X7j", c.get_id());
}


TEST(Basket, Basket_set_id) {
  Basket c("X7j");
  
  EXPECT_EQ("X7j", c.get_id());
  c.set_id("Y9k");
  EXPECT_EQ("Y9k", c.get_id());
}

TEST(Basket, Basket_add_product) {
  Basket b("X7j");
  Product p1("11XX"), p2("22XX"), p3("33XX");
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  Product p4("44XX"), p5("55XX");
  b.add_product(p4);
  b.add_product(p5);
  EXPECT_EQ(5, b.get_size());
}


TEST(Basket, Basket_delete_product1) {
  Basket b("X7j");
  Product p1("11XX"), p2("22XX"), p3("33XX");
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  EXPECT_EQ(3, b.get_size());
  EXPECT_TRUE(b.delete_product(p1));
  EXPECT_EQ(2, b.get_size());
  Product p4("44XX"), p5("55XX");
  b.add_product(p4);
  EXPECT_EQ(3, b.get_size());
  EXPECT_FALSE(b.delete_product(p5));
  EXPECT_EQ(3, b.get_size());
  b.add_product(p1);
  EXPECT_EQ(4, b.get_size());
  EXPECT_FALSE(b.delete_product(p5));
  EXPECT_EQ(4, b.get_size());
  EXPECT_TRUE(b.delete_product(p1));
  EXPECT_TRUE(b.delete_product(p2));
  EXPECT_TRUE(b.delete_product(p3));
  EXPECT_TRUE(b.delete_product(p4));
  EXPECT_EQ(0, b.get_size());
}

TEST(Basket, Basket_delete_product2) {
  Basket b("X7j");
  Product p1("11XX"), p2("22XX"), p3("33XX");
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  EXPECT_EQ(3, b.get_size());
  EXPECT_TRUE(b.delete_product(p1.get_id()));
  EXPECT_EQ(2, b.get_size());
  Product p4("44XX"), p5("55XX");
  b.add_product(p4);
  EXPECT_EQ(3, b.get_size());
  EXPECT_FALSE(b.delete_product(p5.get_id()));
  EXPECT_EQ(3, b.get_size());
  b.add_product(p1);
  EXPECT_EQ(4, b.get_size());
  EXPECT_FALSE(b.delete_product(p5));
  EXPECT_EQ(4, b.get_size());
  EXPECT_TRUE(b.delete_product(p1.get_id()));
  EXPECT_TRUE(b.delete_product(p2.get_id()));
  EXPECT_TRUE(b.delete_product(p3.get_id()));
  EXPECT_TRUE(b.delete_product(p4.get_id()));
  EXPECT_EQ(0, b.get_size());
}


TEST(Basket, Basket_delete_basket) {
  Basket b("X7j");
  Product p1("11XX"), p2("22XX"), p3("33XX");
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  EXPECT_EQ(3, b.get_size());
  EXPECT_TRUE(b.delete_product(p1.get_id()));
  EXPECT_EQ(2, b.get_size());
  Product p4("44XX"), p5("55XX");
  b.add_product(p4);
  EXPECT_EQ(3, b.get_size());
  EXPECT_FALSE(b.delete_product(p5.get_id()));
  EXPECT_EQ(3, b.get_size());
  b.add_product(p1);
  EXPECT_EQ(4, b.get_size());
  EXPECT_FALSE(b.delete_product(p5));
  EXPECT_EQ(4, b.get_size());
  b.delete_basket();
  EXPECT_EQ(0, b.get_size());
  b.add_product(p5);
  b.add_product(p4);
  b.add_product(p3);
  EXPECT_EQ(3, b.get_size());
  b.delete_basket();
  EXPECT_EQ(0, b.get_size());  
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}