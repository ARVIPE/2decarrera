// person_test.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include <person.h>
#include "gtest/gtest.h"

TEST(Person, ConstructorDefaultParam) {
  Person p("33XX");
  
  EXPECT_EQ("33XX", p.get_id());
  EXPECT_EQ("empty", p.get_name());
  EXPECT_EQ("empty", p.get_surname());
  EXPECT_EQ("empty", p.get_address());
  EXPECT_EQ("empty", p.get_town());
  EXPECT_EQ("empty", p.get_province());
  EXPECT_EQ("empty", p.get_country());
  EXPECT_EQ(0, p.get_entry_year());
}

TEST(Person, ConstructorParam) {
  Person p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España", 2021);
  
  EXPECT_EQ("44XX", p.get_id());
  EXPECT_EQ("Carlos", p.get_name());
  EXPECT_EQ("Gutierrez", p.get_surname());
  EXPECT_EQ("C/ Mesa 1", p.get_address());
  EXPECT_EQ("Aguilar", p.get_town());
  EXPECT_EQ("Sevilla", p.get_province());
  EXPECT_EQ("España", p.get_country());
  EXPECT_EQ(2021, p.get_entry_year());
}

TEST(Person, Entry_year_test) {
  Person p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España", -8);
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

TEST(Person, Function_get_full_address) {
  Person p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España", 2021);
  EXPECT_EQ("Carlos Gutierrez\nC/ Mesa 1\nAguilar, Sevilla\nEspaña\n", p.get_full_address());
}


TEST(Person, DefaultCopyConstructor) {
  Person p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España", 2021);
  Person q(p);
  Person r=q;
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

TEST(Person, DefaultEqualOperator) {
  Person p("44XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España", 2021);
  Person q("66FF");
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


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}