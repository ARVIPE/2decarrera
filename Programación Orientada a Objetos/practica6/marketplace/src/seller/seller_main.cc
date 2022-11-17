// seller_main.cc
// main de mi programa
#include <iostream>
#include <string>
#include "../person/person.h"
#include "../basket/basket.h"
#include "seller.h"

int main(){
    
    Seller s("XXX3", "Arturo", "Vicente", "Periodista quesada chacon", "Cordoba", "Cordoba", "España", 2001, "Informática");

    std::cout << s.get_id();

}