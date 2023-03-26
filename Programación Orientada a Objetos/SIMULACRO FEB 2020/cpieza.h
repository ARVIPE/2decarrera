#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include "pieza.h"

#ifndef CPIEZA_H
#define CPIEZA_H

using namespace std;

class CPieza{
    private:
        std::list<Pieza> pieza_list_;
    public:
        CPieza(){
            if(pieza_list_.size()!=0){
                pieza_list_.clear();
            }
        }
      
        CPieza(CPieza const &cp){
            pieza_list_=cp.pieza_list_;
        }

        std::list<Pieza> get(){return pieza_list_;}
        int size(){return pieza_list_.size();}

        bool addPieza(Pieza pieza);

        bool deletePieza(Pieza &pieza);
};






#endif