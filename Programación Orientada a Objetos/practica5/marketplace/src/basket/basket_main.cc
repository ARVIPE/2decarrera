// basket_main.cc
// main de mi programa
#include <iostream>
#include <string>
#include "basket.h"

int main(void)
{
    Basket b("xx1");

    Product p("xx1", "Croquetas", 3);
    Product p2("xx1", "Croquetas", 3);
    Product p3("xx2", "lentejas", 2);
    Product p4("xx3", "salsa", 2);
    Product p5("xx2", "lentejas", 2);

    b.add_product(p);
    b.add_product(p2);
    b.add_product(p3);
    b.add_product(p4);
    b.add_product(p5);

    std::vector<std::string> ids;
    ids = b.get_ids();

    std::cout << "Numero de productos de la cesta: \n"
              << b.get_size() << std::endl;

    std::cout << "Identificadores: \n";
    for (int i = 0; i < b.get_size(); i++)
    {
        std::cout << ids[i] << ",";
    }

    std::cout << std::endl;

    std::vector<int> qs;
    qs = b.get_qs();

    std::cout << "Cantidades: \n";
    for (int i = 0; i < b.get_size(); i++)
    {
        std::cout << qs[i] << ",";
    }

    std::cout << std::endl;

    std::cout << "Precio total de la cesta: " << b.get_total() << std::endl;

    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Mas productos añadidos con id repetidos" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    Product p_1("xx1", "Croquetas", 3);
    Product p2_1("xx1", "Croquetas", 3);
    Product p3_1("xx2", "lentejas", 2);
    Product p5_1("xx2", "lentejas", 2);

    b.add_product(p_1);
    b.add_product(p2_1);
    b.add_product(p3_1);
    b.add_product(p5_1);

    std::vector<std::string> ids_1;
    ids_1 = b.get_ids();

    std::cout << "Numero de productos de la cesta: \n"
              << b.get_size() << std::endl;

    std::cout << "Identificadores: \n";
    for (int i = 0; i < b.get_size(); i++)
    {
        std::cout << ids_1[i] << ",";
    }

    std::cout << std::endl;

    std::vector<int> qs_1;
    qs_1 = b.get_qs();

    std::cout << "Cantidades: \n";
    for (int i = 0; i < b.get_size(); i++)
    {
        std::cout << qs_1[i] << ",";
    }

    std::cout << std::endl;

    std::cout << "Precio total de la cesta: " << b.get_total() << std::endl;

    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Producto con cantidad 1 eliminado y con > 1" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    b.delete_product(p4);
    b.delete_product("xx2");

    std::vector<std::string> ids_2;
    ids_2 = b.get_ids();

    std::cout << "Numero de productos de la cesta: \n"
              << b.get_size() << std::endl;

    std::cout << "Identificadores: \n";
    for (int i = 0; i < b.get_size(); i++)
    {
        std::cout << ids_2[i] << ",";
    }

    std::cout << std::endl;

    std::vector<int> qs_2;
    qs_2 = b.get_qs();

    std::cout << "Cantidades: \n";
    for (int i = 0; i < b.get_size(); i++)
    {
        std::cout << qs_2[i] << ",";
    }

    std::cout << std::endl;

    std::cout << "Precio total de la cesta: " << b.get_total() << std::endl;

    // b.delete_product(p);
    // std::cout << "Baket: " << b.get_id() << "\n";
    // std::cout << "Tamaño: " << b.get_size() << "\n";
    // std::cout << "Total precio: " << b.get_price() << "\n";
}
