// client_test.cc: Juan A. Romero
// Testing Client class

#include "gtest/gtest.h"
#include "client.h"


TEST(Client, ConstructorDefaultParam) {
  Client p("33XX");
  
  EXPECT_EQ("33XX", p.get_id());
  EXPECT_EQ("empty", p.get_name());
  EXPECT_EQ("empty", p.get_surname());
  EXPECT_EQ("empty", p.get_address());
  EXPECT_EQ("empty", p.get_town());
  EXPECT_EQ("empty", p.get_province());
  EXPECT_EQ("empty", p.get_country());
  EXPECT_EQ(0, p.get_entry_year());
}

TEST(Client, ConstructorParam) {
  Client p("44XX", "Carlos", "Gutierrez", 
           "C/ Mesa 1", "Aguilar", "Sevilla", 
           "España", 2021);
  
  EXPECT_EQ("44XX", p.get_id());
  EXPECT_EQ("Carlos", p.get_name());
  EXPECT_EQ("Gutierrez", p.get_surname());
  EXPECT_EQ("C/ Mesa 1", p.get_address());
  EXPECT_EQ("Aguilar", p.get_town());
  EXPECT_EQ("Sevilla", p.get_province());
  EXPECT_EQ("España", p.get_country());
  EXPECT_EQ(2021, p.get_entry_year());
}

TEST(Client, TestGetNameSurname) {
  Client p("44XX", "Carlos", "Gutierrez", 
           "C/ Mesa 1", "Aguilar", "Sevilla", 
           "España", 2021);
  EXPECT_EQ("Carlos Gutierrez", p.get_name_surname());

  p.set_name("Ana");
  p.set_surname("Romero");
  std::string s=p.get_name()+" "+p.get_surname();
  EXPECT_EQ(s, p.get_name_surname());
  Client q("XX");
  EXPECT_EQ("empty empty", q.get_name_surname());
}

TEST(Client, Entry_year_test) {
  Client p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España", -8);
  EXPECT_EQ(0, p.get_entry_year());
  EXPECT_TRUE(p.set_entry_year(2021));
  EXPECT_EQ(2021, p.get_entry_year());
  EXPECT_FALSE(p.set_entry_year(2000));
  EXPECT_EQ(2021, p.get_entry_year());
  EXPECT_FALSE(p.set_entry_year(1999));
  EXPECT_EQ(2021, p.get_entry_year());
  EXPECT_TRUE(p.set_entry_year(2001));
  EXPECT_EQ(2001, p.get_entry_year());
}

TEST(Client, Function_get_full_address) {
  Client p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", 
           "Aguilar", "Sevilla", "España", 2021);
  EXPECT_EQ("Carlos Gutierrez\nC/ Mesa 1\nAguilar, Sevilla\nEspaña\n", p.get_full_address());
}


TEST(Client, DefaultCopyConstructor) {
  Client p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España", 2021);
  Client q(p);
  Client r=q;
  EXPECT_EQ("44XX", q.get_id());
  EXPECT_EQ("Carlos", q.get_name());
  EXPECT_EQ("Gutierrez", q.get_surname());
  EXPECT_EQ("C/ Mesa 1", q.get_address());
  EXPECT_EQ("Aguilar", q.get_town());
  EXPECT_EQ("Sevilla", q.get_province());
  EXPECT_EQ("España", q.get_country());
  EXPECT_EQ(2021, q.get_entry_year());
  
  EXPECT_EQ("44XX", r.get_id());
  EXPECT_EQ("Carlos", r.get_name());
  EXPECT_EQ("Gutierrez", r.get_surname());
  EXPECT_EQ("C/ Mesa 1", r.get_address());
  EXPECT_EQ("Aguilar", r.get_town());
  EXPECT_EQ("Sevilla", r.get_province());
  EXPECT_EQ("España", r.get_country());
  EXPECT_EQ(2021, r.get_entry_year());
}

TEST(Client, DefaultEqualOperator) {
  Client p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España", 2021);
  Client q("66FF");
  q=p;
  EXPECT_EQ("44XX", q.get_id());
  EXPECT_EQ("Carlos", q.get_name());
  EXPECT_EQ("Gutierrez", q.get_surname());
  EXPECT_EQ("C/ Mesa 1", q.get_address());
  EXPECT_EQ("Aguilar", q.get_town());
  EXPECT_EQ("Sevilla", q.get_province());
  EXPECT_EQ("España", q.get_country());
  EXPECT_EQ(2021, q.get_entry_year());
}

TEST(Client, Premium) {
  Client p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España", 2021,5);
  EXPECT_EQ(5,p.get_premium());
  Client q("66FF");
  EXPECT_EQ(0,q.get_premium());
  q.set_premium(1);
  EXPECT_EQ(1,q.get_premium());
  q.set_premium(6);
  EXPECT_EQ(6,q.get_premium());
  p.set_premium(6);
  EXPECT_EQ(6,q.get_premium());
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}