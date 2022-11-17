// tv.h
// A simple tv class

#ifndef TV_H
#define TV_H

#include <string>
#include "../product/product.h"

class Tv : public Product
{
private:
    double inch_;

public:
    Tv(std::string id, std::string name = "empty", double price = 0.0, std::string maker = "empty",
       std::string seller = "empty", double inch = 0.0):Product(id, name, price, maker, seller)
    {
        inch_ = inch;
    };
    // Getter
    inline float get_inch() { return inch_; }
    // Setter
    bool set_inch(float inch);
};

#endif