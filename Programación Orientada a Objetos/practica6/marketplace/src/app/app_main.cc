#include <iostream>
#include <string>
#include "../market/market.h"
#include "../client/client.h"
#include "../seller/seller.h"
#include "../product/product.h"
using namespace std;

int main(void)
{

    Market m("Esto es un eslogan");
    Client c1("C1"), c2("C2"), c3("C3"), c4("C4"), c5("C5");
    Seller s1("S1"), s2("S2"), s3("S3"), s4("S4"), s5("S5");
    Product p1("P1"), p2("P2"), p3("P3"), p4("P4"), p5("P5");

    m.add_client(c1);
    m.add_client(c2);
    m.add_client(c3);
    m.add_client(c4);
    m.add_client(c5);

    m.add_seller(s1);
    m.add_seller(s2);
    m.add_seller(s3);
    m.add_seller(s4);
    m.add_seller(s5);

    m.add_product_seller(p1, "S1");
    m.add_product_seller(p2, "S1");
    m.add_product_seller(p3, "S1");
    m.add_product_seller(p4, "S1");
    m.add_product_seller(p5, "S1");

    m.add_product_seller(p1, "S2");
    m.add_product_seller(p2, "S2");
    m.add_product_seller(p3, "S2");
    m.add_product_seller(p4, "S2");
    m.add_product_seller(p5, "S2");

    m.add_product_seller(p1, "S3");
    m.add_product_seller(p2, "S3");
    m.add_product_seller(p3, "S3");
    m.add_product_seller(p4, "S3");
    m.add_product_seller(p5, "S3");

    m.add_product_seller(p1, "S4");
    m.add_product_seller(p2, "S4");
    m.add_product_seller(p3, "S4");
    m.add_product_seller(p4, "S4");
    m.add_product_seller(p5, "S4");

    m.add_product_seller(p1, "S5");
    m.add_product_seller(p2, "S5");
    m.add_product_seller(p3, "S5");
    m.add_product_seller(p4, "S5");
    m.add_product_seller(p5, "S5");

    int opcion;
    string idclient, idprod;
    cin >> opcion;
/**    switch (opcion)
    {
        case 1:
            cout << "Introduzca un id de cliente" << endl;
            getline(cin, idclient);
            cout << "Introduzca un id de producto" << endl;
            getline(cin, idprod);
            Product p6(idprod);
            m.add_product_client(p6, idprod);
            break;
        default:
            cout << "Opción no válida" << endl;
    }
    **/
}