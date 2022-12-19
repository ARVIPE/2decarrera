// contador.h
// A simple contador class

#ifndef CONTADOR_H
#define CONTADOR_H

#include <string>
#include <list>
#include <map>
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

class Contador
{
private:
    int valInicial_, valMinRang_, valMaxRang_;

public:
    Contador(int valInicial = 0,
             int valMinRang = 0,
             int valMaxRang = 1000)
    {
        if((valInicial < valMinRang) || (valInicial > valMaxRang))
        {
            valInicial = 0;
        }else{
            valInicial_ = valInicial;
        }
        valMinRang_ = valMinRang;
        valMaxRang_ = valMaxRang;
    }
    //Getters
    //inline int get_contador(){ return val_}

};

#endif