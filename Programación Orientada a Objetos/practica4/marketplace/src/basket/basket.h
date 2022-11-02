// basket.h
// A simple basket class

#ifndef BASKET_H
#define BASKET_H

#include <string>
#include <list>
#include "../product/product.h"


class Basket {

private:
    std::string id_;
    std::list<Product> product_list_;
    float total_;
public:
    Basket(std::string id, float total = 0.0)
    {
        id_=id;
        total_=total;
    }
    //Get id
    inline std::string get_id(){return id_;}
    //Setters
    inline void set_id(std::string id){id_=id;}
    inline void add_product(Product p){product_list_.push_back(p); Basket::total_+=p.get_price();}
    bool delete_product(Product &p);
    bool delete_product(std:: string id);
    inline void delete_basket(){product_list_.clear();}
    inline int get_size(){return product_list_.size();}
    inline int get_price(){return total_;}


};


#endif