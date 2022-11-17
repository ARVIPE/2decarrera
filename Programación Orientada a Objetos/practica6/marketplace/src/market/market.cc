//market.cc
//A simple market class

#include "market.h"

bool Market::add_client(Client client){

    for(auto i = client_list_.begin(); i != client_list_.end(); i++){
        if(i->get_id() == client.get_id()){
            return false;
        }
    }

    client_list_.push_back(client);
    return true;

}

bool Market::add_seller(Seller seller){
    for(auto i = seller_list_.begin(); i != seller_list_.end(); i++){
        if(i->get_id() == seller.get_id()){
            return false;
        }   
    }
    seller_list_.push_back(seller);
    return true;
}

bool Market::delete_client(Client &c)
{
    for (auto i = client_list_.begin(); i != client_list_.end(); i++)
    {
        if (i->get_id() == c.get_id())
        {
            client_list_.erase(i);
            return true;
        }
    }
    return false;
}

bool Market::delete_seller(Seller &s)
{
    for (auto i = seller_list_.begin(); i != seller_list_.end(); i++)
    {
        if (i->get_id() == s.get_id())
        {
            seller_list_.erase(i);
            return true;
        }
    }
    return false;
}

bool Market::add_product_seller(Product p, std::string idVendedor){
    for(auto i = seller_list_.begin(); i != client_list.end(); i++){
        
    }
}