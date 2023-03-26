//refpieza.h

#ifndef REFPIEZA_H
#define REFPIEZA_H

#include<iostream>
#include"pieza.h"

class Refpieza: public Pieza
{
    private:
        std::string Referencia_;
    public:
    //constructor por parametros obligatorios todos
        Refpieza(std::string Referencia, int codigo, std::string nombre): Pieza(codigo, nombre){
            Referencia_=Referencia;
        }
    //constructor de copia
        Refpieza(Refpieza const &r, Refpieza const &p): Pieza(p){
            Referencia_=r.Referencia_;
            
        }

    //observadores
        inline std::string getReferencia(){return Referencia_;}
    //modificadores
        inline void setReferencia(std::string Referencia){Referencia_=Referencia;}
};






#endif