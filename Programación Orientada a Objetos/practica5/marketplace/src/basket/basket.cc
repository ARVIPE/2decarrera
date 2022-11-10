// basket.cc
// A basket class

#include "basket.h"

bool Basket::delete_product(Product &p)
{
    for (auto i = product_list_.begin(); i != product_list_.end(); i++)
    {
        if (i->get_id() == p.get_id())
        {
            if (product_quantity_[p.get_id()] > 1)
            {
                product_quantity_[p.get_id()] -= 1;
            }
            else
            {
                product_list_.erase(i);
            }
            Basket::total_ -= p.get_price();
            return true;
        }
    }
    return false;
}

bool Basket::delete_product(std::string id)
{
    for (auto i = product_list_.begin(); i != product_list_.end(); i++)
    {
        if (i->get_id() == id)
        {
            if (product_quantity_[id] > 1)
            {
                product_quantity_[id] -= 1;
            }
            else
            {
                product_list_.erase(i);
            }
            Basket::total_ -= i->get_price();
            return true;
        }
    }
    return false;
}

void Basket::add_product(Product product)
{
    if (product_quantity_.count(product.get_id()) == 0)
    {
        product_list_.push_back(product);
        product_quantity_[product.get_id()] = 1;
    }
    else
    {
        product_quantity_[product.get_id()] += 1;
    }
    Basket::total_ += product.get_price();
}