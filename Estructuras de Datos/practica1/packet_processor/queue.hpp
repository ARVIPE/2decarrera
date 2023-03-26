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
#include <cstdlib>

#include "stack.hpp"

/**
 * @brief ADT Queue.
 * Models a queue of T.
 */
template<class T>
class Queue
{
  public:

  /** @name Life cycle.*/
  /** @{*/

  /** @brief Create an empty Queue.
   * @post is_empty()
   */
  Queue ();

  /** @brief Destroy a Queue.**/
  ~Queue()
  {}

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the list empty?.*/
  bool is_empty () const;

  /** @brief Get the number of items in the queue.*/
  size_t size() const;

  /** @brief get the front item (the oldest one).
   * @pre not is_empty()
   */
  T front() const;

  /** @brief get the back item (the newest one).
   * @pre not is_empty()
   */
  T back() const;

  /**@}*/

  /** @name Modifiers*/

  /** @{*/

  /** @brief Insert a new item.
   * @post back() == new_it
   * @post size()==(old.size()+1)
   */
  void enque(const T& new_it);

  /** @brief Remove the front item.
   * @pre not is_empty()
   * @post size()==(old.size()-1)
   */
  void deque();

  /** @} */

private:

  /** @brief Copy constructor.
   * @warning we don't want a copy constructor.
   */
  Queue(const Queue<T>& other)
  {}

  /** @brief Assign operator.
   * @warning we don't want the assign operator.
   */
  Queue<T>& operator=(const Queue<T>& other)
  {
      return *this;
  }

protected:

   /**
    * @brief Flush input stack into the output stack.
    * @pre !is_empty()
    */
   void flush_input_to_output();

  typename Stack<T>::Ref input_;
  typename Stack<T>::Ref output_;
  T back_; //Allow access to the queue's back item with O(1).
  //
};

#include "queue_imp.hpp"

