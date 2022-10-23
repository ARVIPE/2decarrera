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
    std::list<Product> product_list;
    double total_;
public:
    Basket(std:: string id)
    {
        id_=id;
    }
    //Get id
    inline std::string get_id(){return id_;}
    //Set id
    inline void set_id(std::string id){id_=id;}

    inline void add_product(std::string idProducto){}


};


#endif