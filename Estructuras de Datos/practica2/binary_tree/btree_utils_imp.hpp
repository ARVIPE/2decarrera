/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once

#include <cassert>
#include <exception>
#include <memory>
#include <iostream>
#include <queue>
#include <algorithm>

#include "btree_utils.hpp"

template<class T>
int compute_height (typename BTree<T>::Ref t)
{
    assert(t != nullptr);
    int height = 0;
    //TODO
    height = -1;
    if(not t->is_empty())
    {
        int height_left = -1, height_right = -1;
        //Calculo la altura del subarbol izquierda
        height_left = compute_height<T>(t->left());
        //Calculo la altura del subarbol derecha
        height_right = compute_height<T>(t->right());
        //Calculo la más grande
        height = std::max(height_left,height_right)+1;
    }
    //
    return height;
}

template<class T>
size_t compute_size (typename BTree<T>::Ref t)
{
    assert(t != nullptr);
    size_t ret_val = 0;
    //TODO
    //Hint: when you call a template into other template maybe you need
    // to specialize the call.
    if(not t->is_empty())
    {
        ret_val = 1 + compute_size<T>(t->left()) + compute_size<T>(t->right());
    }
    //
    return ret_val;
}

template <class T, typename Processor>
bool
prefix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;
    //TODO
    //Hint: when you call a template into other template maybe you need
    // to specialize the call.
    if(not tree->is_empty())
    {
        retVal = retVal && p(tree->item());

        retVal = retVal && prefix_process<T>(tree->left(),p);

        retVal = retVal && prefix_process<T>(tree->right(),p);
    }
    //
    return retVal;
}

template <class T, class Processor>
bool
infix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;
    //TODO
    //Hint: when you call a template into other template maybe you need
    // to specialize the call.
    if(not tree->is_empty())
    {
        retVal = retVal && infix_process<T>(tree->left(),p);

        retVal = retVal && p(tree->item());

        retVal = retVal && infix_process<T>(tree->right(),p);
    }
    //
    return retVal;
}

template <class T, class Processor>
bool
postfix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;
    //TODO
    //Hint: when you call a template into other template maybe you need
    // to specialize the call.
    if(not tree->is_empty())
    {
        retVal = retVal && postfix_process<T>(tree->left(),p);

        retVal = retVal && postfix_process<T>(tree->right(),p);

        retVal = retVal && p(tree->item());
    }
    //
    return retVal;
}


template <class T, class Processor>
bool
breadth_first_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool go_on = true;
    //TODO
    //Hint: think about which data structure can help you to do this kind 
    //  of traversal.
    std::queue< typename BTree<T>::Ref > q;
    q.push(tree);
    while(not q.empty() && go_on==true)
    {
        auto subtree = q.front();

        if(not subtree->is_empty())
        {
            q.push(subtree->left());
            q.push(subtree->right());
            go_on = go_on && p(subtree->item());
        }

        q.pop();
    }
    //
    return go_on;
}

template <class T>
std::ostream&
print_prefix(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use a prefix_process to process the tree with this lambda.
    //Remember: the lambda must return true.
    auto p = [&out](T data)
    {
        out << data << " ";
        return true;
    };
    prefix_process<T>(tree,p);
    //
    return out;
}

template <class T>
std::ostream&
print_infix(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use an infix_process to process the tree with this lambda.
    //Remember: the lambda must return true.
    auto p = [&out](T data)
    {
        out << data << " ";
        return true;
    };
    infix_process<T>(tree,p);
    //
    return out;
}

template <class T>
std::ostream&
print_postfix(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use a postfix_process to process the tree with this lambda.
    //Remember: the lambda must return true.
    auto p = [&out](T data)
    {
        out << data << " ";
        return true;
    };
    postfix_process<T>(tree,p);
    //
    return out;
}

template <class T>
std::ostream&
print_breadth_first(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use a breadth_first_process to process the tree with this lambda.
    //Remember: the lambda must return true.
    auto p = [&out](T data)
    {
        out << data << " ";
        return true;
    };
    breadth_first_process<T>(tree,p);
    //
    return out;
}

template <class T>
bool search_prefix(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with the prefix_process.
    //Remember: Also, the lambda must update the count variable and
    //must return True/False.
    auto p =[&it,&count](T data)
    {
        count++;
        return data!=it;
    };
    found = not prefix_process<T>(tree,p);
    //
    return found;
}

template <class T>
bool search_infix(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with the infix_process.
    //Remember: Also, the lambda must update the count variable and
    //must return True/False.
    auto p =[&it,&count](T data)
    {
        count++;
        return data!=it;
    };
    found = not infix_process<T>(tree,p);
    //
    return found;
}

template <class T>
bool search_postfix(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with the postfix_process.
    //Remember: Also, the lambda must update the count variable and
    //must return True/False.
    auto p =[&it,&count](T data)
    {
        count++;
        return data!=it;
    };
    found = not postfix_process<T>(tree,p);
    //
    return found;
}

template <class T>
bool search_breadth_first(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with the breadth_first_process.
    //Remember: Also, the lambda must update the count variable and
    //must return True/False.
    auto p =[&it,&count](T data)
    {
        count++;
        return data!=it;
    };
    found = not breadth_first_process<T>(tree,p);
    //
    return found;
}


template<class T>
bool check_btree_in_order(typename BTree<T>::Ref const& tree)
{
    bool ret_val = true;
    //TODO
    //Hint: You can create a lambda function with a parameter to compare it with
    // the last the value seen.
    // Use the lambda with the infix_process.
    if(tree->is_empty())
    {
        return true;
    }

    auto left_subtree=tree->left();

    if(not left_subtree->is_empty())
    {
        T maximo = tree->item();

        auto p = [&maximo](T data_item){return data_item < maximo;};

        bool retVal = breadth_first_process<T>(left_subtree,p);

        if(retVal == false)
        {
            return false;
        }

        ret_val = ret_val && check_btree_in_order<T>(left_subtree);
    }

    auto right_subtree=tree->right();

    if(not right_subtree->is_empty())
    {
        T min = tree->item();

        auto p = [&min](T data_item){return data_item > min;};

        bool retVal = breadth_first_process<T>(right_subtree,p);

        if(retVal == false)
        {
            return false;
        }
        ret_val = ret_val && check_btree_in_order<T>(right_subtree);
    }
    //
    return ret_val;
}

template<class T>
bool has_in_order(typename BTree<T>::Ref tree, T const& v)
{
    assert(check_btree_in_order<T>(tree));    
    bool ret_val = false;
    //TODO
    if(not tree->is_empty())
    {
        if(v < tree->item())
        {
            auto left_subtree = tree->left();
            if(not left_subtree->is_empty())
            {
                ret_val = has_in_order<T>(left_subtree,v);
            }
        }
        else if(v > tree->item())
        {
            auto right_subtree = tree->right();
            if(not right_subtree->is_empty())
            {
                ret_val = has_in_order<T>(right_subtree,v);
            }
        }
        else
        {
            ret_val = true;
        }
    }
    //
    return ret_val;
}

template <class T>
void insert_in_order(typename BTree<T>::Ref tree, T const& v)
{
    assert(check_btree_in_order<T>(tree));
    //TODO
    if(tree->is_empty())
    {
        tree->create_root(v);
    }
    else if(v < tree->item())
    {
        if(tree->left()->is_empty())
        {
            auto left_subtree = BTree<T>::create();
            left_subtree->create_root(v);
            tree->set_left(left_subtree);  
        }
        else
        {
            auto aux = tree->left();
            insert_in_order<T>(aux,v);
            tree->set_left(aux);
        }
    }
    else if(v > tree->item())
    {
        if(tree->right()->is_empty())
        {
            auto right_subtree = BTree<T>::create();
            right_subtree->create_root(v);
            tree->set_right(right_subtree); 
        }
        else
        {
            auto aux = tree->right();
            insert_in_order<T>(aux,v);
            tree->set_right(aux);
        }
    }
    //
    assert(has_in_order<T>(tree, v));
}
