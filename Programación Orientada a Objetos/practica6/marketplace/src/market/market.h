// market.h
// A simple market class

#ifndef MARKET_H
#define MARKET_H

#include <string>
#include <list>
#include <map>
#include <iostream>
#include <vector>
#include <iterator>
#include "../client/client.h"
#include "../seller/seller.h"


class Market{

private:
    std::list<Client> client_list_;
    std::list<Seller> seller_list_;
    std::string slogan_;

public:
    Market(std::string slogan){
        slogan_=slogan;
    }

    inline std::string get_slogan(){return slogan_;}
    inline void set_slogan(std::string slogan){slogan_=slogan;}

    bool add_client(Client c);
    bool add_seller(Seller c);
    inline int n_clients() { return client_list_.size(); }
    inline int n_sellers() {return seller_list_.size(); }
    bool delete_client(Client &c);
    bool delete_seller(Seller &s);
    bool add_product_seller(Product p, std::string idVendedor);



};


#endif