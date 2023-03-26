/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#pragma once

#include <iostream>

#include "slist.hpp"

/**
 * @brief ADT Stack.
 * Models a Stack using a single linked list*
 */
template<class T>
class Stack
{
  public:
    /** @brief Define a shared reference to a Stack.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< Stack<T> > Ref;

  /** @name Life cycle.*/
  /** @{*/

  /** @brief Create an empty Stack.
   * @post is_empty()
   */
  Stack ();

  /**
   * @brief Create a Stack using dynamic memory.
   * @return a shared reference to the new stack.
   */
  static typename Stack<T>::Ref create();

  /**
   * @brief Create a Stack from an input stream.
   * The input format is the same of a single list.
   * @return a shared reference to the new stack.
   * @warning throw std::runtime_error if wrong input format.
   */
  static typename Stack<T>::Ref create(std::istream & in) noexcept(false);

  /** @brief Destroy a Stack.**/
  ~Stack()
  {}

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the list empty?.*/
  bool is_empty () const;

  /** @brief Get the number of items in the stack.*/
  size_t size() const;

  /** @brief get the top item.
   * @pre not is_empty()
   */
  T top() const;

  /**
   * @brief Fold the stack to an output stream.
   * The output format is like the slist.
   * @param out is the output stream.
   */
  void fold(std::ostream& out) const;

  /** @}*/

  /** @name Modifiers*/

  /** @{*/

  /** @brief Insert a new item.
   * @post top() == new_it
   * @post size() = old.size()+1
   */
  void push(const T& new_it);

  /** Remove the top item.
   * @pre not is_empty()
   * @post size() = old.size()-1
   */
  void pop();

  /** @} */

protected:

  typename SList<T>::Ref l_;

};

#include "stack_imp.hpp"

