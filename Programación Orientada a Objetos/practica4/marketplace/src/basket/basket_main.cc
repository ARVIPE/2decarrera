// basket_main.cc
// main de mi programa
#include <iostream>
#include <string>
#include "basket.h"

int main(void)
{
    Basket b("xx1");

    Product p("xx1", "Nombre", 5.75, "Fabricante", "Vendedor");
    Product p2("xx2", "Nombre 2", 0.25);
    Product p3("xx3", "nombre3", 4.86);

    b.add_product(p);
    b.add_product(p2);
    b.add_product(p3);
    std::cout << "Baket: " << b.get_id() << "\n";
    std::cout << "Tamaño: " << b.get_size() << "\n";
    std::cout << "Total precio: " << b.get_price() << "\n";

    
    b.delete_product(p);
    std::cout << "Baket: " << b.get_id() << "\n";
    std::cout << "Tamaño: " << b.get_size() << "\n";
    std::cout << "Total precio: " << b.get_price() << "\n";


}
