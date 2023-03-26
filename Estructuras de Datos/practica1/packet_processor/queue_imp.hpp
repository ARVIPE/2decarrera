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
#include "queue.hpp"

template <class T>
Queue<T>::Queue()
{
    // TODO
    input_ = Stack<T>::create();
    output_ = Stack<T>::create();
    //
    assert(is_empty());
}

template <class T>
bool Queue<T>::is_empty() const
{
    bool ret_val = true;
    // TODO
    ret_val = (input_->is_empty() and output_->is_empty());
    //
    return ret_val;
}

template <class T>
size_t
Queue<T>::size() const
{
    size_t ret_val = 0;
    // TODO
    ret_val = (input_->size() + output_->size());
    //
    return ret_val;
}

template <class T>
T Queue<T>::front() const
{
    assert(!is_empty());
    T ret_val;
    // TODO
    if (const_cast<Queue<T> *>(this)->output_->is_empty())
    {
        const_cast<Queue<T> *>(this)->flush_input_to_output();
    }
    ret_val = const_cast<Queue<T> *>(this)->output_->top();
    //
    return ret_val;
}

template <class T>
T Queue<T>::back() const
{
    assert(!is_empty());
    T ret_val;
    // TODO
    if (input_->is_empty())
    {
        ret_val = back_;
    }
    else
    {
        ret_val = input_->top();
    }
    //
    return ret_val;
}

template <class T>
void Queue<T>::enque(const T &new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
#endif
    // TODO
    // Remember: we enque into the input stack.
    // Hint: maybe you need to update the back item.
    input_->push(new_it);
    //
    assert(back() == new_it);
    assert(size() == (old_size + 1));
}

template <class T>
void Queue<T>::deque()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
#endif
    // TODO
    // Remember: we deque from the output stack and if the output stack is empty,
    // we need to flush the input stack into the output stack first.
    if (output_->is_empty())
    {
        flush_input_to_output();
    }
    output_->pop();
    //
    assert(size() == (old_size - 1));
}

template <class T>
void Queue<T>::flush_input_to_output()
{
    assert(!input_->is_empty());
#ifndef NDEBUG
    T old_back = back();
#endif
    // TODO
    // Remember: the first item pushed into output is
    //  the new back() of the queue.
    back_ = back();
    while (not input_->is_empty())
    {
        output_->push(input_->top());
        input_->pop();
    }
    //
    assert(old_back == back());
}
