#include <iostream>
#include <string>
#include "person.h"

int main(void){
    Person persona("XXX35", "Arturo", "Vicente", "Escriba Lubna", "Cordoba", "Cordoba", "España", 2050);
   
    std::cout<<persona.get_full_address();
   // std::cout<<"id: " << persona.get_id();
}