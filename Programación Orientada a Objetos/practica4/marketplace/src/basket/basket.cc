// basket.cc
// A basket class

#include "basket.h"

bool Basket::delete_product(Product &p)
{
    for (auto i = product_list_.begin(); i != product_list_.end(); i++)
    {
        if (i->get_id() == p.get_id())
        {
            product_list_.erase(i);
            return true;
        }
    }
    return false;
}

bool Basket::delete_product(std::string id)
{
    for (std::list<Product>::iterator i = product_list_.begin(); i != product_list_.end(); i++)
    {
        if (i->get_id() == id)
        {
            product_list_.erase(i);
            return true;
        }
    }
    return false;
}

