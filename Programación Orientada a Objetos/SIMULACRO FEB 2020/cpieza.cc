#include "cpieza.h"


bool CPieza::addPieza(Pieza pieza){
            for(auto i = pieza_list_.begin(); i != pieza_list_.end(); i++){
                if(pieza.getCodigo()==i->getCodigo()){
                    return false;
                }
            }
            pieza_list_.push_back(pieza);
            return true;
        }

bool CPieza::deletePieza(Pieza &pieza){
            for(auto i = pieza_list_.begin(); i != pieza_list_.end(); i++){
                if(pieza.getCodigo()==i->getCodigo()){
                    pieza_list_.erase(i);
                    return true;
                }
            }
            return false;
        }