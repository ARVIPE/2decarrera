// tv.h
// A simple tv class

#ifndef TV_H
#define TV_H

#include <string>
#include "../product/product.h"

class Tv : public Product
{
    // Private atributes
private:
    float pulgadas_;
public:
    // Constructor's prototype
    Tv(std::string id,
       std::string name = "empty",
       std::string maker = "empty",
       float price = 0.0,
       int seller = 0,
       float pulgadas = 0.0) : Product(id, name, maker, price, seller){pulgadas_ = pulgadas;}
     // Getters
    inline float get_inch(){ return pulgadas_; }
    // Setters
    bool set_inch(float pulgadas);

};

#endif