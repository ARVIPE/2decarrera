//tv_main.cc
//main de mi programa
#include <iostream>
#include <string>
#include "tv.h"

int main(void){
    Tv t("12312", "Pepe", "Samsung", 5.3, 3453, 2.3);

    std::cout<<t.get_id()<<std::endl;
}