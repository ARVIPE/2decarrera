// tv.cc
// Para metodos de tv

#include "tv.h"
#include "../product/product.h"
#include <string>

bool Tv::set_inch(float inch){
    if(inch>0){
        inch_=inch;
        return true;
    }else{
        return false;
    }
}