//basket_main.cc
//main de mi programa
#include<iostream>
#include<string>
#include "basket.h"
#

int main(void){
    Basket basket("XXX1");
    Product p("xxx3", "Nombre", 5.2);
    Product p2("xxx4", "Nombre2", 0.8);

    basket.add_product(p);
    basket.add_product(p2);

    std::cout<<basket.get_price();
    
    
}
