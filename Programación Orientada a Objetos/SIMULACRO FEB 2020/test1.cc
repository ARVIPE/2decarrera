#include "pieza.h"
#include "gtest/gtest.h"
#include <string>
using namespace std;

TEST(Pieza, Constructores)
{
	Pieza p;
	string nombre;
	EXPECT_EQ(0,p.getCodigo());
	EXPECT_NEAR(0.0,p.getPrecio(),0.01);
	EXPECT_EQ(0,p.getCantidad());
	p.getNombre(nombre);
	EXPECT_EQ("Sin Nombre",nombre);

	Pieza p2(1,"Tornillo");
	EXPECT_EQ(1,p2.getCodigo());
	EXPECT_NEAR(0,p2.getPrecio(),0.01);
	EXPECT_EQ(0,p2.getCantidad());
	p2.getNombre(nombre);
	EXPECT_EQ("Tornillo",nombre);

	Pieza p3(2,"Tuerca",0.2,500);
	EXPECT_EQ(2,p3.getCodigo());
	EXPECT_NEAR(0.2,p3.getPrecio(),0.01);
	EXPECT_EQ(500,p3.getCantidad());
	p3.getNombre(nombre);
	EXPECT_EQ("Tuerca",nombre);

	Pieza p4(p3);
	EXPECT_EQ(2,p4.getCodigo());
	EXPECT_NEAR(0.2,p4.getPrecio(),0.01);
	EXPECT_EQ(500,p4.getCantidad());
	p4.getNombre(nombre);
	EXPECT_EQ("Tuerca",nombre);
}

TEST(Pieza,getPieza)
{
	Pieza p(2,"Tornillo",0.2,200);
	Pieza p2(2,"Tuerca",0.2,500);

	EXPECT_EQ("Hay 200 unidades de la pieza Tornillo.",p.getPieza());
	EXPECT_EQ("Hay 500 unidades de la pieza Tuerca.",p2.getPieza());
}