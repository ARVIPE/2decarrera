#include "gtest/gtest.h"
#include <iostream>
using namespace std;
#include "intercambia.cc"

TEST(Intercambia, IntercambiaInt) {
    int a=5, b=77;
    intercambia(a,b);
    EXPECT_EQ(77, a);
    EXPECT_EQ(5, b);
}

TEST(Intercambia, IntercambiaFloat) {
    float a=5.5, b=7.7;
    intercambia(a,b);
    EXPECT_NEAR(7.7, a, 0.01);
    EXPECT_NEAR(5.5, b, 0.01);
}

TEST(Intercambia, IntercambiaString) {
    string a="hello", b="bye";
    intercambia(a,b);
    EXPECT_EQ("bye", a);
    EXPECT_EQ("hello", b);
}