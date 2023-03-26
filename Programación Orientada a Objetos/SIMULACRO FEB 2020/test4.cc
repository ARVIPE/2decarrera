#include "gtest/gtest.h"
#include <string>
#include "cpieza2.h"
using namespace std;

TEST(CPieza2, operador_asignacion)
{
	CPieza cp;

	Pieza p(1,"Tornillo");
	Pieza p2(2,"Tuerca");
	Pieza p3(3,"Arandela");

	EXPECT_TRUE(cp.addPieza(p));
	EXPECT_TRUE(cp.addPieza(p2));
	EXPECT_TRUE(cp.addPieza(p3));
	EXPECT_EQ(3,cp.size());

	CPieza cp2;
	EXPECT_EQ(0,cp2.size());
	cp2=cp;
	EXPECT_EQ(3,cp2.size());
}

TEST(CPieza2, operador_corchetes)
{
	CPieza cp;

	Pieza p(1,"Tornillo");
	Pieza p2(2,"Tuerca");
	Pieza p3(3,"Arandela");

	EXPECT_TRUE(cp.addPieza(p));
	EXPECT_TRUE(cp.addPieza(p2));
	EXPECT_TRUE(cp.addPieza(p3));
	EXPECT_EQ(3,cp.size());

	EXPECT_EQ(1,cp[0].getCodigo());
	EXPECT_EQ(2,cp[1].getCodigo());
	EXPECT_EQ(3,cp[2].getCodigo());
}