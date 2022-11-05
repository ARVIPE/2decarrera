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
    std::string id_;
    std::list<Product> product_list_;
    float total_;

    std::map<std::string, int> product_quantity_;

public:
    Basket(std::string id, float total = 0.0)
    {
        id_ = id;
        total_ = total;
    }
    // Get id
    inline std::string get_id() { return id_; }
    inline int get_size() { return product_list_.size(); }
    inline double get_total() { return total_; }
    std::vector<std::string> get_ids()
    {
        std::vector<std::string> mult;
        mult.reserve(product_list_.size());
        for (std::list<Product>::iterator i = product_list_.begin(); i != product_list_.end(); i++)
        {
            mult.push_back(i->get_id());
        }
        return mult;
    }
    std::vector<int> get_qs()
    {
        std::vector<int> mult;
        mult.reserve(product_list_.size());
        for (std::list<Product>::iterator i = product_list_.begin(); i != product_list_.end(); i++)
        {
            mult.push_back(product_quantity_[i->get_id()]);
        }
        return mult;
    }
    // Setters
    inline void set_id(std::string id) { id_ = id; }
    void add_product(Product p);
    bool delete_product(Product &p);
    bool delete_product(std::string id);
    inline void delete_basket() { product_list_.clear(); }
};

#endif