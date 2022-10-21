//product_main.cc
//main de mi programa
#include <iostream>
#include <string>
#include "product.h"

int main(void){
    Product producto("XXX35", "croquetas", "hacendado", 3.25, 3);
    

    std::cout<<producto.get_id()<<std::endl;

}       