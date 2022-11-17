// market_test.cc: Juan A. Romero
// Testing class Market

#include "gtest/gtest.h"
#include "market.h"

TEST(Basket, Constructor) {
  Market m("Sell it again, Sam!");
  
  EXPECT_EQ("Sell it again, Sam!", m.get_slogan());
}

TEST(Basket, get_slogan) {
  Market m("Sell it");
  
  EXPECT_EQ("Sell it", m.get_slogan());
}

TEST(Basket, set_slogan) {
  Market m("Sell it");
  EXPECT_EQ("Sell it", m.get_slogan());
  m.set_slogan("");
  EXPECT_EQ("", m.get_slogan());
  m.set_slogan("Yes");
  EXPECT_EQ("Yes", m.get_slogan());
}

TEST(Basket, add_client) {
  Market m("Sell it");
  EXPECT_EQ(0, m.n_clients());
  Client c1("C1"), c2("C2");
  EXPECT_TRUE(m.add_client(c1));
  EXPECT_EQ(1, m.n_clients());
  EXPECT_TRUE(m.add_client(c2));
  EXPECT_EQ(2, m.n_clients());
  EXPECT_FALSE(m.add_client(c2));
  EXPECT_FALSE(m.add_client(c1));
}

TEST(Basket, add_seller) {
  Market m("Sell it");
  EXPECT_EQ(0, m.n_sellers());
  Seller s1("S1"), s2("S2");
  EXPECT_TRUE(m.add_seller(s1));
  EXPECT_EQ(1, m.n_sellers());
  EXPECT_TRUE(m.add_seller(s2));
  EXPECT_EQ(2, m.n_sellers());
  EXPECT_FALSE(m.add_seller(s2));
  EXPECT_FALSE(m.add_seller(s1));
}

TEST(Basket, delete_client) {
  Market m("Sell it");
  EXPECT_EQ(0, m.n_clients());
  Client c1("C1"), c2("C2");
  EXPECT_TRUE(m.add_client(c1));
  EXPECT_EQ(1, m.n_clients());
  EXPECT_TRUE(m.add_client(c2));
  EXPECT_EQ(2, m.n_clients());
  EXPECT_TRUE(m.delete_client(c2));
  EXPECT_EQ(1, m.n_clients());
  EXPECT_TRUE(m.delete_client(c1));
  EXPECT_EQ(0, m.n_clients());
  EXPECT_FALSE(m.delete_client(c1));
  EXPECT_FALSE(m.delete_client(c2));
}

TEST(Basket, delete_seller) {
  Market m("Sell it");
  EXPECT_EQ(0, m.n_sellers());
  Seller s1("S1"), s2("S2");
  EXPECT_TRUE(m.add_seller(s1));
  EXPECT_EQ(1, m.n_sellers());
  EXPECT_TRUE(m.add_seller(s2));
  EXPECT_EQ(2, m.n_sellers());
  EXPECT_TRUE(m.delete_seller(s1));
  EXPECT_EQ(1, m.n_sellers());
  EXPECT_TRUE(m.delete_seller(s2));
  EXPECT_EQ(0, m.n_sellers());
  EXPECT_FALSE(m.delete_seller(s1));
  EXPECT_FALSE(m.delete_seller(s2));
}

TEST(Basket, del_add_client_seller) {
  Market m("Sell it");
  EXPECT_EQ(0, m.n_clients());
  EXPECT_EQ(0, m.n_sellers());
  Seller s1("S1"), s2("S2");
  Client c1("C1"), c2("C2"), c3("C3");
  EXPECT_TRUE(m.add_seller(s1));
  EXPECT_TRUE(m.add_client(c1));
  EXPECT_EQ(1, m.n_clients());
  EXPECT_EQ(1, m.n_sellers());
  EXPECT_TRUE(m.delete_seller(s1));
  EXPECT_EQ(1, m.n_clients());
  EXPECT_EQ(0, m.n_sellers());
  EXPECT_TRUE(m.add_client(c2));
  EXPECT_EQ(2, m.n_clients());
  EXPECT_EQ(0, m.n_sellers());
  EXPECT_FALSE(m.delete_seller(s1));
  EXPECT_FALSE(m.delete_seller(s2));
  EXPECT_FALSE(m.delete_client(c3));
}

TEST(Basket, add_product_seller) {
  Market m("Sell it");
  Seller s1("S1"), s2("S2");
  Client c1("C1"), c2("C2");
  Product p1("P1", "tv", 2345.9);
  Product p2("P2", "PC", 1378.5);
  EXPECT_TRUE(m.add_seller(s1));
  EXPECT_TRUE(m.add_seller(s2));
  EXPECT_TRUE(m.add_client(c1));
  EXPECT_TRUE(m.add_client(c2));
  EXPECT_TRUE(m.add_product_seller(p1, "S1"));
  EXPECT_TRUE(m.add_product_seller(p2, "S1"));
  EXPECT_FALSE(m.add_product_seller(p2, "XX"));
}

TEST(Basket, add_product_client) {
  Market m("Sell it");
  Seller s1("S1"), s2("S2");
  Client c1("C1"), c2("C2");
  Product p1("P1", "tv", 2345.9);
  Product p2("P2", "PC", 1378.5);
  Product p3("P3", "Laptop", 1378.5);
  EXPECT_TRUE(m.add_seller(s1));
  EXPECT_TRUE(m.add_seller(s2));
  EXPECT_TRUE(m.add_client(c1));
  EXPECT_TRUE(m.add_client(c2));

  EXPECT_TRUE(m.add_product_seller(p1, "S1"));
  EXPECT_TRUE(m.add_product_seller(p2, "S1"));

  EXPECT_TRUE(m.add_product_client(p1, "C1"));
  EXPECT_TRUE(m.add_product_client(p2, "C1"));
  EXPECT_FALSE(m.add_product_client(p2, "XX")); // client doesn't exists
  EXPECT_FALSE(m.add_product_client(p3, "C1")); // product not on sale
}

TEST(Basket, delete_product_seller) {
  Market m("Sell it");
  Seller s1("S1"), s2("S2");
  Client c1("C1"), c2("C2");
  Product p1("P1", "tv", 10);
  Product p2("P2", "PC", 20);
  Product p3("P3", "Laptop", 30);
  Product p4("P4", "Tv", 40);
  EXPECT_TRUE(m.add_seller(s1));
  EXPECT_TRUE(m.add_seller(s2));
  EXPECT_TRUE(m.add_client(c1));
  EXPECT_TRUE(m.add_client(c2));

  EXPECT_TRUE(m.add_product_seller(p1, "S1"));
  EXPECT_TRUE(m.add_product_seller(p2, "S1"));

  EXPECT_TRUE(m.add_product_seller(p3, "S2"));
  
  EXPECT_TRUE(m.delete_product_seller(p1, "S1"));
  EXPECT_FALSE(m.delete_product_seller(p3, "S1"));
  EXPECT_FALSE(m.delete_product_seller(p4, "S1"));

  EXPECT_TRUE(m.delete_product_seller(p3, "S2"));
  EXPECT_FALSE(m.delete_product_seller(p3, "S2"));
}

TEST(Basket, delete_product_client) {
  Market m("Sell it");
  Seller s1("S1"), s2("S2");
  Client c1("C1"), c2("C2");
  Product p1("P1", "tv", 10);
  Product p2("P2", "PC", 20);
  Product p3("P3", "Laptop", 30);
  Product p4("P4", "Tv", 40);
  EXPECT_TRUE(m.add_seller(s1));
  EXPECT_TRUE(m.add_seller(s2));
  EXPECT_TRUE(m.add_client(c1));
  EXPECT_TRUE(m.add_client(c2));

  EXPECT_TRUE(m.add_product_seller(p1, "S1"));
  EXPECT_TRUE(m.add_product_seller(p2, "S1"));
  EXPECT_TRUE(m.add_product_seller(p3, "S2"));
  
  EXPECT_TRUE(m.add_product_client(p1, "C1"));
  EXPECT_TRUE(m.add_product_client(p2, "C1"));
  EXPECT_TRUE(m.add_product_client(p3, "C1"));

  EXPECT_FALSE(m.delete_product_seller(p4, "S1"));
  EXPECT_FALSE(m.delete_product_client(p4, "C1"));

  EXPECT_NEAR(60.0, m.get_money_in_basket(), 0.1);
  EXPECT_TRUE(m.delete_product_client(p3, "C1"));
  EXPECT_NEAR(30.0, m.get_money_in_basket(), 0.1);

  EXPECT_TRUE(m.delete_product_client(p2, "C1"));
  EXPECT_NEAR(10.0, m.get_money_in_basket(), 0.1);

  EXPECT_FALSE(m.add_product_client(p2, "C1"));
  EXPECT_NEAR(10.0, m.get_money_in_basket(), 0.1);
}

TEST(Basket, get_money_in_basket) {
  Market m("Sell it");
  Seller s1("S1"), s2("S2");
  Client c1("C1"), c2("C2");
  Product p1("P1", "tv", 10);
  Product p2("P2", "PC", 20);
  Product p3("P3", "Laptop", 30);
  Product p4("P4", "Laptop", 5);
  EXPECT_TRUE(m.add_seller(s1));
  EXPECT_TRUE(m.add_seller(s2));
  EXPECT_TRUE(m.add_client(c1));
  EXPECT_TRUE(m.add_client(c2));

  EXPECT_TRUE(m.add_product_seller(p1, "S1"));
  EXPECT_TRUE(m.add_product_seller(p1, "S1"));
  EXPECT_TRUE(m.add_product_seller(p2, "S1"));
  EXPECT_TRUE(m.add_product_seller(p2, "S1"));
  EXPECT_TRUE(m.add_product_seller(p3, "S1"));

  EXPECT_TRUE(m.add_product_seller(p4, "S2"));
  
  EXPECT_TRUE(m.add_product_client(p1, "C1"));
  EXPECT_TRUE(m.add_product_client(p2, "C1"));
  EXPECT_TRUE(m.add_product_client(p3, "C1"));
  EXPECT_NEAR(60.0, m.get_money_in_basket(), 0.1);

  EXPECT_TRUE(m.add_product_client(p1, "C1"));
  EXPECT_NEAR(70.0, m.get_money_in_basket(), 0.1);

  EXPECT_FALSE(m.add_product_client(p1, "C1"));
  EXPECT_NEAR(70.0, m.get_money_in_basket(), 0.1);

  EXPECT_FALSE(m.add_product_client(p1, "C2"));
  EXPECT_NEAR(70.0, m.get_money_in_basket(), 0.1);

  EXPECT_TRUE(m.add_product_client(p4, "C2"));
  EXPECT_NEAR(75.0, m.get_money_in_basket(), 0.1);

  EXPECT_TRUE(m.add_product_client(p2, "C2"));
  EXPECT_NEAR(95.0, m.get_money_in_basket(), 0.1);

  EXPECT_FALSE(m.add_product_client(p1, "C2"));
  EXPECT_NEAR(95.0, m.get_money_in_basket(), 0.1);
}

TEST(Basket, dump_market) {
  Market m("Sell it");
  Seller s1("S1"), s2("S2");
  Client c1("C1"), c2("C2");
  Product p1("P1", "tv", 10);
  Product p2("P2", "PC", 20);
  Product p3("P3", "Laptop", 30);
  Product p4("P4", "Laptop", 5);
  Product p5("P5", "Laptop", 15);
  EXPECT_TRUE(m.add_seller(s1));
  EXPECT_TRUE(m.add_seller(s2));
  EXPECT_TRUE(m.add_client(c1));
  EXPECT_TRUE(m.add_client(c2));

  EXPECT_TRUE(m.add_product_seller(p1, "S1"));
  EXPECT_TRUE(m.add_product_seller(p1, "S1"));
  EXPECT_TRUE(m.add_product_seller(p1, "S1"));
  EXPECT_TRUE(m.add_product_seller(p2, "S1"));
  EXPECT_TRUE(m.add_product_seller(p2, "S1"));
  EXPECT_TRUE(m.add_product_seller(p3, "S1"));
  EXPECT_TRUE(m.add_product_seller(p4, "S2"));
  EXPECT_TRUE(m.add_product_seller(p4, "S2"));
  EXPECT_TRUE(m.add_product_seller(p5, "S2"));

  
  EXPECT_TRUE(m.add_product_client(p1, "C1"));
  EXPECT_TRUE(m.add_product_client(p2, "C1"));
  EXPECT_TRUE(m.add_product_client(p2, "C1"));
  EXPECT_TRUE(m.add_product_client(p3, "C1"));

  EXPECT_TRUE(m.add_product_client(p5, "C2"));
  EXPECT_TRUE(m.add_product_client(p1, "C2"));
  EXPECT_TRUE(m.add_product_client(p4, "C2"));
  m.dump_market();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}