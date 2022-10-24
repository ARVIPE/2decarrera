// product.h
// A simple product class

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
private:
    std::string id_, name_, maker_, seller_;
    double price_;

public:
    // Constructor
    Product(std::string id,
            std::string name = "empty",
            double price = 0.0,
            std::string maker = "empty",
            std::string seller = "empty")
    {
        id_ = id;
        name_ = name;
        price_ = price;
        maker_ = maker;
        seller_ = seller;
    }
    // Getters
    inline std::string get_id() { return id_; }
    inline std::string get_name() { return name_; }
    inline double get_price() { return price_; }
    inline std::string get_maker() { return maker_; }
    inline std::string get_seller() { return seller_; }
    // Setters
    inline void set_id(std::string id) { id_ = id; }
    inline void set_name(std::string name) { name_ = name; }
    inline void set_price(double price) { price_ = price; }
    inline void set_maker(std::string maker) { maker_ = maker; }
    inline void set_seller(std::string seller) { seller_ = seller; }
};

#endif