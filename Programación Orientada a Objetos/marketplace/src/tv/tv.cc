// tv.cc
// Para metodos de tv
#include "tv.h"
#include <string>


bool Tv::set_inch(float pulgadas){
    if(pulgadas>0){
        pulgadas_=pulgadas;
        return true;
    }else{
        return false;
    }
}