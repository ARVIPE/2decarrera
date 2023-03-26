#include "gtest/gtest.h"
#include <string>
#include "cpieza.h"
using namespace std;

TEST(CPieza, Constructor_vacio)
{
	CPieza p;
	EXPECT_EQ(0,p.get().size());
}

TEST(CPieza,Metodo_size)
{
	CPieza p;
	EXPECT_EQ(0,p.size());
}

TEST(CPieza, Metodo_addPieza)
{
	CPieza cp;

	Pieza p(1,"Tornillo");
	Pieza p2(2,"Tuerca");
	Pieza p3(3,"Arandela");

	EXPECT_TRUE(cp.addPieza(p));
	EXPECT_TRUE(cp.addPieza(p2));
	EXPECT_TRUE(cp.addPieza(p3));
	EXPECT_EQ(3,cp.size());

	EXPECT_FALSE(cp.addPieza(p2));
	EXPECT_EQ(3,cp.size());
}

TEST(CPieza, Metodo_deletePieza)
{
	CPieza cp;

	Pieza p(1,"Tornillo");
	Pieza p2(2,"Tuerca");
	Pieza p3(3,"Arandela");

	EXPECT_TRUE(cp.addPieza(p));
	EXPECT_TRUE(cp.addPieza(p2));
	EXPECT_EQ(2,cp.size());

	EXPECT_TRUE(cp.deletePieza(p2));
	EXPECT_EQ(1,cp.size());

	EXPECT_FALSE(cp.deletePieza(p3));
	EXPECT_EQ(1,cp.size());
}

// TEST(CPieza,write_read)
// {
// 	CPieza cp;

// 	Pieza p(1,"Tornillo");
// 	Pieza p2(2,"Tuerca");
// 	Pieza p3(3,"Arandela");

// 	EXPECT_TRUE(cp.addPieza(p));
// 	EXPECT_TRUE(cp.addPieza(p2));
// 	EXPECT_TRUE(cp.addPieza(p3));

// 	cp.write("piezas.txt");

// 	cp.read("piezas.txt");

// 	EXPECT_EQ(3,cp.size());

// }