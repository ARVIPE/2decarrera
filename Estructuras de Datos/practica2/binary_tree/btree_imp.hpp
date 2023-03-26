/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once

#include "btree.hpp"

template<class T>
BTNode<T>::BTNode (T const& it, BTNode<T>::Ref l,
                   BTNode<T>::Ref r)
{
    //TODO
    _item = it;
    _left = l;
    _right = r;
    //
    assert(item()==it);
    assert(left()==l);
    assert(right()==r);
}

template<class T>
typename BTNode<T>::Ref BTNode<T>::create(T const& it,
                                          BTNode<T>::Ref left,
                                          BTNode<T>::Ref right)
{
    return std::make_shared<BTNode<T>> (it, left, right);
}

template<class T>
T BTNode<T>::item() const
{

    T ret_v;
    //TODO
    ret_v = _item;
    //
    return ret_v;
}



template<class T>
typename BTNode<T>::Ref BTNode<T>::left() const
{

    typename BTNode<T>::Ref child;
    //TODO
    child = _left;
    //
    return child;
}


template<class T>
typename BTNode<T>::Ref BTNode<T>::right() const
{

    typename BTNode<T>::Ref child;
    //TODO
    child = _right;
    //
    return child;
}

template<class T>
void BTNode<T>::set_item(const T& new_it)
{
    //TODO
    _item = new_it;
    //
    assert(item()==new_it);
}

template<class T>
void BTNode<T>::set_left(BTNode<T>::Ref new_child)
{
    //TODO
    _left = new_child;
    //
    assert(left()==new_child);
}

template<class T>
void BTNode<T>::set_right(BTNode<T>::Ref new_child)
{
    //TODO
    _right = new_child;
    //
    assert(right()==new_child);
}

/**
 * ADT BTree.
 * Models a BTree of T.
 */
template<class T>
BTree<T>::BTree ()
    {
        //TODO
        _root = nullptr;
        //
        assert(is_empty());
    }

    template<class T>
    BTree<T>::BTree (const T& it)
    {
        //TODO
        _root = BTNode<T>::create(it);
        //
        assert(!is_empty());
        assert(item()==it);
        assert(left()->is_empty());
        assert(right()->is_empty());
    }

template<class T>
typename BTree<T>::Ref BTree<T>::create()
  {
      return std::make_shared<BTree<T>> ();
  }

template<class T>
  typename BTree<T>::Ref BTree<T>::create(T const& item)
  {
      return std::make_shared<BTree<T>>(item);
  }

template<class T>
  typename BTree<T>::Ref BTree<T>::create (std::istream& in) noexcept(false)
  {
      auto tree = BTree<T>::create();
      std::string token;
      //TODO
      //Remenber: throw std:runtime_error exception with text
      //"Wrong input format." when an input format error is found.
      in >> token;
      if (!in)
          throw std::runtime_error("Wrong input format.");

      //TODO
      if(token=="[")
      {
        in >> token;

        //if(!isdigit(token[0]))
          //throw std::runtime_error("Wrong input format. 2");

        T it;
        std::istringstream convert_token(token);
        convert_token >> it;

        if(! convert_token){
          throw std::runtime_error("Wrong input format.");
        }

        tree->create_root(it);

        auto left_subtree = create(in);

        auto right_subtree = create(in);

        tree->set_left(left_subtree); 
        
        tree->set_right(right_subtree);

        in >> token;

        if(token!="]")
        {
          throw std::runtime_error("Wrong input format.");
        }
	    }
      else if (token!="[]")
      {
          throw std::runtime_error("Wrong input format.");
      }

      //
      return tree;
  }

template<class T>
  bool BTree<T>::is_empty () const
  {
      bool ret_v = false;
      //TODO
      ret_v = (_root == nullptr);
      //
      return ret_v;
  }

template<class T>
  T BTree<T>::item() const
  {
      assert(!is_empty());
      T ret_v;
      //TODO
      ret_v = _root->item();
      //
      return ret_v;
  }

template<class T>
  typename BTree<T>::Ref BTree<T>::left() const
  {
      assert(!is_empty());
      BTree<T>::Ref subtree = nullptr;
      //TODO
      //Hint: use the private constructor given a root node.
      subtree = BTree<T>::create();
      if(_root->left() != nullptr)
      {
        subtree->set_root(_root->left());
      }
      return subtree;
  }

template<class T>
  typename BTree<T>::Ref BTree<T>::right() const
  {
      assert(!is_empty());
      BTree<T>::Ref subtree = nullptr;
      //TODO
      //Hint: use the private constructor given a root node.
      subtree = BTree<T>::create();
      if(_root->right() != nullptr)
      {
        subtree->set_root(_root->right());
      }
      //
      return subtree;
  }

template<class T>
  std::ostream& BTree<T>::fold(std::ostream& out) const
  {
      //TODO
      if(is_empty())
	  	{
	  		out << "[]";
	  	}
	  	else
	  	{
	  		out << "[ ";
	  		out << item() << " ";
  			left()->fold(out);
  			out << " ";
	  		right()->fold(out);
	  		out << " ]";
	  	}
      //
      return out;
  }

  template<class T>
    void BTree<T>::create_root(const T& it)
    {
        assert(is_empty());
        //TODO
        _root = BTNode<T>::create(it,nullptr, nullptr);

        //
        assert(!is_empty());
        assert(item()==it);
        assert(left()->is_empty());
        assert(right()->is_empty());

    }

template<class T>
  void BTree<T>::set_item(const T& new_it)
  {
      assert(!is_empty());
      //TODO
      _root->set_item(new_it);
      //
      assert(item()==new_it);
  }

template<class T>
  void BTree<T>::set_left(typename BTree<T>::Ref new_left)
  {
      assert(!is_empty());
      //TODO
      _root->set_left(new_left->root());
      //
      assert(left()->root()==new_left->root());
  }

template<class T>
  void BTree<T>::set_right(typename BTree<T>::Ref new_right)
  {
      assert(!is_empty());
      //TODO
      _root->set_right(new_right->root());
      //
      assert(right()->root()==new_right->root());
  }

template<class T>
  BTree<T>::BTree (typename BTNode<T>::Ref n)
  {
      //TODO
      _root = n;
      //
      assert(root()==n);
  }

template<class T>
typename BTree<T>::Ref BTree<T>::create(typename BTNode<T>::Ref root)
  {
      //We cannot use std::make_shared here
      //because the constructor is protected.
      typename BTree<T>::Ref tree ( new BTree<T>(root) );
      return tree;
  }

template<class T>
  typename BTNode<T>::Ref BTree<T>::root() const
  {
      typename BTNode<T>::Ref node;
      //TODO
      node = _root;
      //
      return node;
  }

template<class T>
  void BTree<T>::set_root(typename BTNode<T>::Ref new_root)
  {
      //TODO
      _root = new_root;
      //
      assert(root()==new_root);
  }

