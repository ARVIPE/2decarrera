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
        if((valMaxRang == 0) && (valMaxRang = 1000)){
            if(valInicial > 0 && valInicial < 1000){
                valInicial_ = valInicial;
            }else{
                valInicial_ = 0;
            }
        }else{
             if((valInicial < valMinRang) || (valInicial > valMaxRang) || (valMaxRang < valMinRang)){
                    valInicial_ = 0;
                    valMinRang_ = 0;
                    valMaxRang_ = 1000;
             }
        }
    }
    //Getters
    inline int get(){ return valInicial_;}
    Contador operator=(const int &n);
    Contador operator=(const Contador &c);

};

#endif