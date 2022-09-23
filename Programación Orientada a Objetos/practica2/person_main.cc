#include <iostream>
#include <string>
#include "person.h"

int main(void){
    Person persona("XXX35", "Arturo", "Vicente", "Escriba Lubna", "Cordoba", "Cordoba", "España", 2050);
   
    std::cout<<"id="<<persona.get_id();
   // std::cout<<"id: " << persona.get_id();
}