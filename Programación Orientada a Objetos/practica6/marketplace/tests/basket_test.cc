// basket_test.cc: Juan A. Romero
// Testing class Basket

#include "gtest/gtest.h"
#include "../basket/basket.h"
#include "../product/product.h"
#include "../tv/tv.h"
#include "../computer/computer.h"

TEST(Basket, ZeroProducts) {
  Basket b;
  EXPECT_EQ(0, b.get_size());
}

TEST(Basket, AddProduct) {
  Basket b;
  Product p1("P1"), p2("P2"), p3("P3");
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  Product *p= new Product("XX1");
  b.add_product(*p);
  delete p;
  EXPECT_EQ(4, b.get_size());
}

TEST(Basket, AddMoreProducts) {
  Basket b;
  Product p1("P1"), p2("P2"), p3("P3");
  Tv t1("Tv1");
  Computer c1("C1", ComputerType::Server);
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  b.add_product(t1);
  b.add_product(c1);
  b.add_product(p2);
  b.add_product(p3);
  Product *p= new Product("XX1");
  b.add_product(*p);
  delete p;
  EXPECT_EQ(6, b.get_size());
}

TEST(Basket, DeleteProductsP) {
  Basket b;
  Product p1("P1"), p2("P2"), p3("P3");
  Tv t1("Tv1");
  Computer c1("C1", ComputerType::Server);
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  b.add_product(t1);
  b.add_product(c1);
  b.add_product(p2);
  b.add_product(p3);
  Product *p= new Product("XX1");
  b.add_product(*p);
  delete p;
  EXPECT_EQ(6, b.get_size());
  b.delete_product(p3); // decrementa en 1 catidad de p3 (queda 1)
  EXPECT_EQ(6, b.get_size());
  b.delete_product(p3); // Ahora p3 ya sale de la cesta
  EXPECT_EQ(5, b.get_size());
  b.delete_product(t1); 
  EXPECT_EQ(4, b.get_size());
}

TEST(Basket, DeleteProductsId) {
  Basket b;
  Product p1("P1"), p2("P2"), p3("P3");
  Tv t1("Tv1");
  Computer c1("C1", ComputerType::Server);
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  b.add_product(t1);
  b.add_product(c1);
  b.add_product(p2);
  b.add_product(p3);
  Product *p= new Product("XX1");
  b.add_product(*p);
  delete p;
  EXPECT_EQ(6, b.get_size());
  b.delete_product("P3"); // decrementa en 1 catidad de p3 (queda 1)
  EXPECT_EQ(6, b.get_size());
  b.delete_product("P3"); // Ahora p3 ya sale de la cesta
  EXPECT_EQ(5, b.get_size());
  b.delete_product("Tv1"); 
  EXPECT_EQ(4, b.get_size());
}

TEST(Basket, DeleteProductsNoId) {
  Basket b;
  Product p1("P1"), p2("P2"), p3("P3");
  b.add_product(p1);
  b.add_product(p2);
  EXPECT_EQ(2, b.get_size());
  EXPECT_FALSE(b.delete_product(p3));
  EXPECT_EQ(2, b.get_size());
  EXPECT_FALSE(b.delete_product("P5"));
  EXPECT_EQ(2, b.get_size());
  EXPECT_FALSE(b.delete_product("XX"));
  EXPECT_EQ(2, b.get_size());  
  EXPECT_TRUE(b.delete_product("P1"));
  EXPECT_EQ(1, b.get_size());  
  EXPECT_TRUE(b.delete_product("P2"));
  EXPECT_EQ(0, b.get_size()); 
}

TEST(Basket, AddAndDeleteProducts) {
  Basket b;
  Product p1("P1"), p2("P2"), p3("P3");
  Tv t1("Tv1");
  Computer c1("C1", ComputerType::Server);
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  EXPECT_EQ(3, b.get_size());
  b.delete_product(p3);
  EXPECT_EQ(2, b.get_size());
  b.add_product(t1);
  b.add_product(c1);
  EXPECT_EQ(4, b.get_size());
  b.delete_product(t1);
  b.delete_product(c1);
  EXPECT_EQ(2, b.get_size());
  b.delete_product(p1);
  b.delete_product(p2);
  EXPECT_EQ(0, b.get_size());
}

TEST(Basket, BasketTotalZero) {
  Basket b;
  Product p1("P1"), p2("P2"), p3("P3");
  EXPECT_FLOAT_EQ(0.0,b.get_total());
}

TEST(Basket, BasketTotal) {
  Basket b;
  Product p1("P1", "Product 1", 100.5);
  Product p2("P2", "Product 2", 200.5);
  Product p3("P3", "Product 3", 300.5);
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  EXPECT_FLOAT_EQ(601.5,b.get_total());
}

TEST(Basket, BasketTotalDelete) {
  Basket b;
  Product p1("P1", "Product 1", 100.5);
  Product p2("P2", "Product 2", 200.5);
  Product p3("P3", "Product 3", 300.5);
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  EXPECT_FLOAT_EQ(601.5,b.get_total());
  b.delete_product(p3);
  EXPECT_FLOAT_EQ(301.0,b.get_total());
  b.delete_product(p2);
  EXPECT_FLOAT_EQ(100.5,b.get_total());
  b.delete_product(p1);
  EXPECT_FLOAT_EQ(0.0,b.get_total());
}

TEST(Basket, BasketTotalDeleteQuantities) {
  Basket b;
  Product p1("P1", "Product 1", 100.5);
  Product p2("P2", "Product 2", 200.5);
  Product p3("P3", "Product 3", 300.5);
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  EXPECT_FLOAT_EQ(601.5,b.get_total());

  b.add_product(p1);
  EXPECT_FLOAT_EQ(702.0,b.get_total());
  b.add_product(p1);
  EXPECT_FLOAT_EQ(802.5,b.get_total());


  b.delete_product(p1);
  EXPECT_FLOAT_EQ(702.0,b.get_total());
  b.delete_product(p1);
  EXPECT_FLOAT_EQ(601.5,b.get_total());
  b.delete_product(p1);
  EXPECT_FLOAT_EQ(501.0,b.get_total());
}

TEST(Basket, Basket_get_ids_empty) {
  Basket b;
  std::vector<std::string> vs;
  vs=b.get_ids();
  EXPECT_EQ(0, vs.size());
}
TEST(Basket, Basket_get_ids) {
  Basket b;
  Product p1("P1", "Product 1", 100.5);
  Product p2("P2", "Product 2", 200.5);
  Product p3("P3", "Product 3", 300.5);
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  std::vector<std::string> vs;
  vs=b.get_ids();
  EXPECT_EQ(3, vs.size());
  EXPECT_EQ(vs[0], "P1");
  EXPECT_EQ(vs[1], "P2");
  EXPECT_EQ(vs[2], "P3");
  b.delete_product(p3);
  vs=b.get_ids();
  EXPECT_EQ(2, vs.size());
  EXPECT_EQ(vs[0], "P1");
  EXPECT_EQ(vs[1], "P2");
  b.add_product(p1);
  vs=b.get_ids();
  EXPECT_EQ(2, vs.size());
  EXPECT_EQ(vs[0], "P1");
  EXPECT_EQ(vs[1], "P2");
  b.delete_product(p1);
  vs=b.get_ids();
  EXPECT_EQ(2, vs.size());
  EXPECT_EQ(vs[0], "P1");
  EXPECT_EQ(vs[1], "P2");
  b.delete_product(p1);
  b.delete_product(p2);
  vs=b.get_ids();
  EXPECT_EQ(0, vs.size());
}
TEST(Basket, Basket_get_qs_empty) {
  Basket b;
  std::vector<int> v;
  v=b.get_qs();
  EXPECT_EQ(0, v.size());
}
TEST(Basket, Basket_get_qs) {
  Basket b;
  Product p1("P1", "Product 1", 100.5);
  Product p2("P2", "Product 2", 200.5);
  Product p3("P3", "Product 3", 300.5);
  b.add_product(p1);
  b.add_product(p2);
  b.add_product(p3);
  std::vector<int> v;
  v=b.get_qs();
  EXPECT_EQ(3, v.size());
  EXPECT_EQ(1, v[0]);
  EXPECT_EQ(1, v[1]);
  EXPECT_EQ(1, v[2]);
  b.add_product(p3);
  v=b.get_qs();
  EXPECT_EQ(1, v[0]);
  EXPECT_EQ(1, v[1]);
  EXPECT_EQ(2, v[2]);
  b.add_product(p1);
  v=b.get_qs();
  EXPECT_EQ(2, v[0]);
  EXPECT_EQ(1, v[1]);
  EXPECT_EQ(2, v[2]);
  b.delete_product(p1);
  b.delete_product(p3);
  v=b.get_qs();
  EXPECT_EQ(1, v[0]);
  EXPECT_EQ(1, v[1]);
  EXPECT_EQ(1, v[2]);
}
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}