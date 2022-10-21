// person.cc
// Para metodos de productos
#include "product.h"
#include <string>

Product::Product(std::string id, std::string name,
                 std::string maker, float price, std::string seller)
{
    id_ = id;
    name_ = name;
    maker_ = maker;
    price_ = price;
    seller_ = seller;
}   