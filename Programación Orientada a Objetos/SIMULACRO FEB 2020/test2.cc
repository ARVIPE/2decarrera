#include "gtest/gtest.h"
#include "refpieza.h"
#include <string>
using namespace std;

TEST(Refpieza,Constructores)
{
	string nombre;
	
	Refpieza p3("XXX",2,"Tuerca");
	EXPECT_EQ("XXX",p3.getReferencia());
	EXPECT_EQ(2,p3.getCodigo());
	EXPECT_NEAR(0,p3.getPrecio(),0.01);
	EXPECT_EQ(0,p3.getCantidad());
	p3.getNombre(nombre);
	EXPECT_EQ("Tuerca",nombre);

	Refpieza p4(p3);
	EXPECT_EQ("XXX",p4.getReferencia());
	EXPECT_EQ(2,p4.getCodigo());
	EXPECT_NEAR(0,p4.getPrecio(),0.01);
	EXPECT_EQ(0,p4.getCantidad());
	p4.getNombre(nombre);
	EXPECT_EQ("Tuerca",nombre);
}