#include "usuario.h"
#include "gtest/gtest.h"

TEST(Usuario, Constructor2) {
  Usuario a(11), b(22);
  EXPECT_EQ(11, a.getId());
  EXPECT_EQ(22, b.getId());
  EXPECT_EQ(2, a.getN());
  Usuario c(33), d(44);
  EXPECT_EQ(4, a.getN());
  Usuario e(55);
  EXPECT_EQ(5, a.getN());
}

