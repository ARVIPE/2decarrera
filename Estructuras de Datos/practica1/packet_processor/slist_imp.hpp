/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once

#include <sstream>
#include <stdexcept>
#include <cassert>

#include "slist.hpp"

template <class T>
SNode<T>::SNode(T const &it)
{
    // TODO
    _item = it;
    _next = nullptr;
    //
    assert(!has_next());
}

template <class T>
SNode<T>::SNode(T const &it, SNode<T>::Ref &next)
{
    // TODO
    _item = it;
    _next = next;
    //
}

template <class T>
SNode<T>::~SNode()
{
    // TODO
    // hint: if std::shared_ptr is used for the references, nothing todo.

    //
}

template <class T>
typename SNode<T>::Ref SNode<T>::create(T const &it, SNode<T>::Ref next)
{
    return std::make_shared<SNode<T>>(it, next);
}

template <class T>
T SNode<T>::item() const
{
    T it;
    // TODO
    it = _item;
    //
    return it;
}

template <class T>
bool SNode<T>::has_next() const
{
    bool has = false;
    // TODO
    has = (_next != nullptr);
    //
    return has;
}

template <class T>
typename SNode<T>::Ref SNode<T>::next() const
{
    SNode<T>::Ref n;
    // TODO
    n = _next;
    //
    return n;
}

template <class T>
void SNode<T>::set_item(const T &new_it)
{
    // TODO
    _item = new_it;
    //
    assert(item() == new_it);
}

template <class T>
void SNode<T>::set_next(SNode<T>::Ref n)
{
    // TODO
    _next = n;
    //
    assert(n == next());
}

template <class T>
SList<T>::SList()
{
    // TODO
    _head = _cursor = nullptr;
    _size = 0;
    //
    assert(is_empty());
}

template <class T>
SList<T>::~SList()
{
    // TODO

    //
}

template <class T>
typename SNode<T>::Ref SList<T>::head() const
{
    typename SNode<T>::Ref h;
    // TODO
    h = _head;
    //
    return h;
}

template <class T>
typename SList<T>::Ref SList<T>::create()
{
    return std::make_shared<SList<T>>();
}

template <class T>
typename SList<T>::Ref SList<T>::create(std::istream &in) noexcept(false)
{
    auto list = SList<T>::create();
    std::string token;
    in >> token;

    // TODO
    // Hint: use std::istringstream to convert from "string" to template
    //  parameter T type.
    //  Throw std::runtime_error("Wrong input format.") exception when an input
    //  format error was found.

    if (token == "[]")
    {
        return list;
    }
    else if (token == "[")
    {
        while (in >> token and token != "]")
        {
            std::istringstream convert(token);
            T new_item;
            convert >> new_item;

            for (size_t i = 0; i < token.size(); i++)
            {
                if (not std::isdigit(token[i]))
                {
                    std::cout << "Wrong input format." << std::endl;
                    return list;
                }
            }

            if (list->is_empty())
            {
                list->insert(new_item);
            }
            else
            {
                if (list->has_next())
                    list->goto_next();
                list->insert(new_item);
            }
        }

        if (token != "]")
        {
            std::cout << "Wrong input format." << std::endl;
        }
    }
    else
    {
        std::cout << "Wrong input format." << std::endl;
    }

    //
    return list;
}

template <class T>
bool SList<T>::is_empty() const
{
    bool ret_val = true;
    // TODO
    ret_val = (_head == nullptr);
    //
    return ret_val;
}

template <class T>
size_t SList<T>::size() const
{
    size_t ret_val = 0;
    // TODO
    ret_val = _size;
    //
    return ret_val;
}

template <class T>
T SList<T>::front() const
{
    assert(!is_empty());
    T f;
    // TODO
    f = _head->item();
    //
    return f;
}

template <class T>
T SList<T>::current() const
{
    assert(!is_empty());
    T c;
    // TODO
    c = _cursor->item();
    //
    return c;
}

template <class T>
bool SList<T>::has_next() const
{
    assert(!is_empty());
    bool ret_val = false;
    // TODO
    ret_val = _cursor->has_next();
    //
    return ret_val;
}

template <class T>
T SList<T>::next() const
{
    assert(has_next());
    T ret_val = false;
    // TODO
    ret_val = _cursor->next()->item();
    //
    return ret_val;
}

template <class T>
bool SList<T>::has(T const &it) const
{
    bool found = false;
    // TODO
    // Hint: you can reuse SList::find() but you must remember to restore
    //  the old the cursor position. In this way we assure not modify the state of the list.
    // Hint: use const_cast<> to remove constness of this.
    auto aux = _head;

    while (aux != nullptr and aux->item() != it)
    {
        aux = aux->next();
    }

    if (aux != nullptr)
    {
        found = true;
    }
    //
    return found;
}

template <class T>
void SList<T>::fold(std::ostream &out) const
{
    // TODO
    if (is_empty())
    {
        out << "[]";
    }
    else
    {

        out << "[ ";

        auto ptr_aux = _head;

        while (ptr_aux != nullptr)
        {
            out << ptr_aux->item();

            out << " ";

            ptr_aux = ptr_aux->next();
        }

        out << "]";
    }
    //
}

template <class T>
void SList<T>::set_current(T const &new_v)
{
    assert(!is_empty());
    // TODO
    _cursor->set_item(new_v);
    //
    assert(current() == new_v);
}

template <class T>
void SList<T>::push_front(T const &new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
#endif
    // TODO
    // Remeber to update current if current is in the head.
    if (is_empty())
    {
        _head = SNode<T>::create(new_it, nullptr);
        _cursor = _head;
    }
    else
    {
        auto nuevo = SNode<T>::create(new_it, _head);
        _head = nuevo;
        _cursor = _head;
    }
    _size++;
    //
    assert(front() == new_it);
    assert(size() == (old_size + 1));
}

template <class T>
void SList<T>::insert(T const &new_it)
{
#ifndef NDEBUG
    bool old_is_empty = is_empty();
    size_t old_size = size();
    T old_item;
    if (!old_is_empty)
        old_item = current();
#endif
    // TODO
    if (is_empty())
    {
        push_front(new_it);
    }
    else
    {
        auto nuevo = SNode<T>::create(new_it, _cursor->next());
        _cursor->set_next(nuevo);
        _size++;
    }
    //
    assert(!old_is_empty || (front() == new_it && current() == new_it));
    assert(old_is_empty || (old_item == current() && has_next() && next() == new_it));
    assert(size() == (old_size + 1));
}

template <class T>
void SList<T>::pop_front()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
    auto old_head_next = head()->next();
#endif
    // TODO
    _head = _head->next();
    _size--;
    //
    assert(is_empty() || head() == old_head_next);
    assert(size() == (old_size - 1));
}

template <class T>
void SList<T>::remove()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
    bool old_has_next = has_next();
    T old_next;
    if (has_next())
        old_next = next();
#endif
    // TODO
    // Case 1: current is the head.
    if (_cursor == _head)
    {
        _head = _head->next();
        _cursor = _head;
    }
    // Case 2: remove in a middle position.
    else if (_cursor->next() != nullptr)
    {
        auto ptr_anterior = _head;
        while (ptr_anterior->next() != _cursor)
        {
            ptr_anterior = ptr_anterior->next();
        }
        ptr_anterior->set_next(_cursor->next());
        _cursor = ptr_anterior->next();
    }
    // Case 3: remove the last element.
    // Remenber to locate previous of prev_.
    else
    {
        auto ptr_anterior = _head;
        while (ptr_anterior->next() != _cursor)
        {
            ptr_anterior = ptr_anterior->next();
        }
        ptr_anterior->set_next(nullptr);
        _cursor = ptr_anterior;
    }
    _size--;
    //
    assert(!old_has_next || current() == old_next);
    assert(size() == (old_size - 1));
}

template <class T>
void SList<T>::goto_next()
{
    assert(has_next());
#ifndef NDEBUG
    auto old_next = next();
#endif
    // TODO
    _cursor = _cursor->next();
    //
    assert(current() == old_next);
}

template <class T>
void SList<T>::goto_first()
{
    assert(!is_empty());
    // TODO
    _cursor = _head;
    //
    assert(current() == front());
}

template <class T>
bool SList<T>::find(T const &it)
{
    assert(!is_empty());
    bool found = false;
    // TODO
    auto anterior = _head;
    _cursor = _head;

    while (_cursor != nullptr and current() != it)
    {
        anterior = _cursor;
        _cursor = _cursor->next();
    }

    if (_cursor != nullptr)
    {
        found = true;
    }
    else
    {
        _cursor = anterior;
    }
    //
    assert(!found || current() == it);
    assert(found || !has_next());
    return found;
}

template <class T>
bool SList<T>::find_next(T const &it)
{
    assert(has_next());
    bool found = false;
    // TODO
    _cursor = _cursor->next();

    while (_cursor != nullptr and current() != it)
    {
        _cursor = _cursor->next();
    }

    if (_cursor != nullptr)
    {
        found = true;
    }
    //
    assert(!found || current() == it);
    assert(found || !has_next());
    return found;
}
