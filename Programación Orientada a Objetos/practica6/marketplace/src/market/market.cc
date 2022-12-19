// market.cc
// A simple market class

#include "market.h"

bool Market::add_client(Client client)
{

    for (auto i = client_list_.begin(); i != client_list_.end(); i++)
    {
        if (i->get_id() == client.get_id())
        {
            return false;
        }
    }

    client_list_.push_back(client);
    return true;
}

bool Market::add_seller(Seller seller)
{
    for (auto i = seller_list_.begin(); i != seller_list_.end(); i++)
    {
        if (i->get_id() == seller.get_id())
        {
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

bool Market::add_product_seller(Product product, std::string idVendedor)
{
    for (auto i = seller_list_.begin(); i != seller_list_.end(); i++)
    {
        if (idVendedor == i->get_id())
        {
            i->add_product(product);
            return true;
        }
    }
    return false;
}

bool Market::add_product_client(Product product, std::string id_client)
{
    for (auto i = seller_list_.begin(); i != seller_list_.end(); i++)
    {
        if (i->delete_product(product.get_id()))
        {
            for (auto j = client_list_.begin(); j != client_list_.end(); j++)
            {
                if (id_client == j->get_id())
                {
                    j->add_product(product);
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}

bool Market::delete_product_seller(Product product, std::string idVendedor)
{
    for (auto i = seller_list_.begin(); i != seller_list_.end(); i++)
    {
        if (idVendedor == i->get_id())
        {
            std::vector<std::string> mult = i->get_ids();
            for (int j = 0; j < mult.size(); j++)
            {
                if (mult[j] == product.get_id())
                {
                    return i->delete_product(product);
                }
            }
        }
    }
    return false;
}

bool Market::delete_product_client(Product product, std::string id_client)
{
    for (std::list<Client>::iterator j = client_list_.begin(); j != client_list_.end(); j++)
    {
        if (id_client == j->get_id())
        {
            std::vector<std::string> mult = j->get_ids();
            for (int k = 0; k < mult.size(); k++)
            {
                if (mult[k] == product.get_id())
                {
                    return j->delete_product(product);
                }
            }
        }
    }
    return false;
}

double Market::get_money_in_basket()
{
    int total = 0;
    for (std::list<Client>::iterator j = client_list_.begin(); j != client_list_.end(); j++)
    {
        total += j->get_total();
    }
    return total;
}

void Market::dump_market()
{
    std::ofstream fich("ventas.txt");

    if (!fich)
    {
        std::cout << "Error al abrir el fichero\n";
        exit(EXIT_FAILURE);
    }

    fich << "CLIENT ID | PRODUCT_ID | PRODUCT QTY \n";
    for (auto i = client_list_.begin(); i != client_list_.end(); i++)
    {
        for (int j = 0; j < i->get_ids().size(); j++)
        {
            fich << i->get_id();
            fich << "\t|\t";
            fich << i->get_ids()[j];
            fich << "\t|\t";
            fich << i->get_qs()[j];
        }
    }
    fich << "-------------------------------\n";
    fich << "TOTAL:";
    fich << get_money_in_basket();
    fich << "€\n";
    fich.close();
}