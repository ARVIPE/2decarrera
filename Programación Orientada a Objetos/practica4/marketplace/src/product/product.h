// product.h
// A simple product class

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
    // Private atributes
private:
    std::string id_, name_, maker_, seller_;
    float price_;

public:
    // Constructor's protoypes
    Product(std::string id,
            std::string name = "empty",
            std::string maker = "empty",
            float price = 0.0,
            std::string seller = "empty");
    // Getters-
    inline std::string get_id() { return id_; }
    inline std::string get_name() { return name_; }
    inline std::string get_maker() { return maker_; }
    inline float get_price() { return price_; }
    inline std::string get_seller() { return seller_; }
    // Setters
    inline void set_id(std::string id) { id_ = id; }
    inline void set_name(std::string name) { name_ = name; }
    inline void set_maker(std::string maker) { maker_ = maker; }
    inline float set_price(float price) { price_ = price; }
    inline void set_seller(std::string seller) { seller_ = seller; }
};

#endif