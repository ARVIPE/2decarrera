// basket.h
// A simple basket class

#ifndef BASKET_H
#define BASKET_H

#include <string>
#include <list>
#include <map>
#include <iostream>
#include <vector>
#include <iterator>
#include "../product/product.h"

class Basket
{

private:
    std::list<Product> product_list_;
    float total_;

    std::map<std::string, int> product_quantity_;

public:
    Basket(float total = 0.0)
    {
        total_ = total;
    }
    // Get id
    inline int get_size() { return product_list_.size(); }
    inline double get_total() { return total_; }
    
    std::vector<std::string> get_ids()
    {
        std::vector<std::string> vector;
        vector.reserve(product_list_.size());
        for (std::list<Product>::iterator i = product_list_.begin(); i != product_list_.end(); i++)
        {
            vector.push_back(i->get_id());
        }
        return vector;
    }
    std::vector<int> get_qs()
    {
        std::vector<int> vector;
        vector.reserve(product_list_.size());
        for (std::list<Product>::iterator i = product_list_.begin(); i != product_list_.end(); i++)
        {
            vector.push_back(product_quantity_[i->get_id()]);
        }
        return vector;
    }
    // Setters
    void add_product(Product p);
    bool delete_product(Product &p);
    bool delete_product(std::string id);
    inline void delete_basket() { product_list_.clear(); }
};

#endif