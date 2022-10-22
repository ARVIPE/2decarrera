// computer.h
// A simple computer class

#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include "../product/product.h"

enum class ComputerType
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
    // Computer(std::string id, std::string name = "empty", double price = 0.0, std::string maker = "empty",
    //          std::string seller = "empty", ComputerType type_) : Product(id, name, price, maker, seller){};
   
    // inline float get_type(){return type_;}
   



};

#endif