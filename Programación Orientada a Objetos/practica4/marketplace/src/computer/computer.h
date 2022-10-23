// computer.h
// A simple computer class

#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include "../product/product.h"

enum ComputerType
{
    Desktop,
    Laptop,
    Server,
    Tablet,
    Gaming
};

class Computer : public Product
{
private:
    ComputerType type_;

public:
    Computer(std::string id, ComputerType type, std::string name = "empty", double price = 0.0, std::string maker = "empty",
             std::string seller = "empty") : Product(id, name, price, maker, seller){type_=type;}
    
    inline ComputerType get_type(){return type_;}
    inline void set_type(ComputerType type){type_=type;}
    
};

#endif