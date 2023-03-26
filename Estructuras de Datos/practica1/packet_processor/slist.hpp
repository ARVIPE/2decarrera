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
#include <memory>

/** @brief a single link node.*/
template <class T>
class SNode
{
public:

    /** @brief Define a shared reference to a SNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< SNode<T> > Ref;

    /** @name Life cycle.*/
    /** @{*/

    /** @brief Create a node.
     *  @post it == item()
     *  @post !has_next()
     */
    SNode (T const& it);

    /** @brief Create a node.
     *  @post it == item()
     *  @post next == next()
    */
    SNode (T const& it, SNode<T>::Ref& next);

    /**
     * @brief Create a SNode using dynamic memory.
     * @param it the value save in the node.
     * @param next link to the next node.
     * @return a shared reference to the new node.
     */
    static typename SNode<T>::Ref create(T const& it,
                                         SNode<T>::Ref next=nullptr);

    /** @brief Destroy a SNode.**/
    ~SNode();

    /** @}*/

    /** @name Observers.*/
    /** @{*/

    /** @brief Get the data item.*/
    T item() const;

    /**
     * @brief Has it a next node?.
     * @return true if it has a next node.
    */
    bool has_next() const;

    /** @brief Get the link to next element.*/
    typename SNode<T>::Ref next() const;

    /** @}*/

    /** @name Modifiers.*/
    /** @{*/

    /** @brief Set the data item.*/
    void set_item(const T& new_it);

    /** @brief Set the link to the next node.*/
    void set_next(SNode<T>::Ref next);

    /** @}*/
protected:
    T _item;
    SNode<T>::Ref _next;
};

/**
 * @brief ADT SList.
 * Models a Single linked list[T].
 */
template<class T>
class SList
{
  public:

    /** @brief Define a shared reference to a SList.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< SList<T> > Ref;

  /** @name Life cycle.*/
  /** @{*/

  /** @brief Create an empty SList.
   * @post is_empty()
   */
  SList ();

  /** @brief Destroy a SList.**/
  ~SList();

  /**
   * @brief Create a SList using dynamic memory.
   * @return a shared reference to the new slist.
   */
  static typename SList<T>::Ref create();

  /**
   * @brief Create a SList unfolding from an input stream.
   *
   * The input format will be "[]" for the empty list
   * or "[" item1 item2 ... item_n "]" where item1 is the head.
   *
   * @param in is the input stream.
   * @warning if the input format is not correct a std::runtime_error with
   * what message "Wrong input format." will be raised.
   * @return A shared reference to the new slist.
   */
  static typename SList<T>::Ref create(std::istream& in) noexcept(false);

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the list empty?.*/
  bool is_empty () const;

  /** @brief Get the number of items in the list.*/
  size_t size() const;

  /**
   * @brief Get the head's item of the list.
   * @return the item at the head.
   * @pre !is_empty()
   */
  T front() const;

  /** @brief get the current item.
   * @pre not is_empty()
   */
  T current() const;

  /**
   * @brief Is there a next item?
   * @return true if there is.
   * @pre !is_empty()
   */
  bool has_next() const;

  /**
   * @brief Get the next item.
   * @return the next item data.
   * @pre has_next()
   */
  T next() const;

  /**
   * @brief Has it the item data?
   * @param[in] it is the item to find.
   * @return true if the item is into the list.
   */
  bool has(T const& it) const;

  /**
   * @brief Fold to an output stream.
   *
   * The format will be "[]" for the empty list or  '[' item1 item2 item3 ... item_n ']'
   * where item1 is the head.
   *
   * @param out is the output stream.
   * @return the output stream.
   */
  void fold(std::ostream& out) const;
  /**@}*/

  /** @name Modifiers*/

  /** @{*/

  /**
   * @brief Set a new value for current.
   * @param new_v is the new value.
   * @pre !is_empty()
   * @post item()==new_v
   */
  void set_current(T const& new_v);

  /**
   * @brief insert an item as the new list's head.
   * @param new_it is the item to insert.
   * @post front()==new_it
   * @post size()==(old.size()+1)
   */
  void push_front(T const& new_it);

  /**
   * @brief insert a new item after current.
   * @param new_it is the item to insert.
   * @post old.is_empty() implies front()==current()==new_it
   * @post !old.is_empty() implies current()==old.current() && has_next() && next()==new_it
   * @post size()==(old.size()+1)
   */
  void insert(T const& new_it);

  /**
   * @brief Remove the head.
   * @pre !is_empty()
   * @post is_empty() || front() == "next of old.front()".
   * @post size()==(old.size()-1)
   */
  void pop_front();

  /**
   * @brief Remove current item.
   * @pre !is_empty()
   * @post old.has_next() implies current()==old.next()
   * @post !old.has_next() implies is_empty() || current()=="old previous item."
   * @post size()==(old.size()-1)
   */
  void remove();

  /**
   * @brief Move the cursor to the next list's item.
   * @pre has_next()
   * @post old.next()==current()
   */
  void goto_next();

  /**
   * @brief Move the cursor to the list's head.
   * @pre !is_empty()
   * @post current()==front()
   */
  void goto_first();

  /**
   * @brief Move the cursor to the first occurrence of a value from the head of the list.
   * If the item is not found, the cursor will be at the end of the list.
   * @param it is the value to be found.
   * @return true if it is found.
   * @pre !is_empty()
   * @post !ret_val || item()==it
   * @post ret_value || !has_next()
   */
  bool find(T const& it);

  /**
   * @brief Move the cursor to the next occurrence of a value from current.
   * If the item is not found, the cursor will be at the end of the list.
   * @param it is the value to be found.
   * @return true if it is found.
   * @pre has_next()
   * @post !ret_val || item()==it
   * @post ret_value || !has_next()
   */
  bool find_next(T const& it);

  /** @}*/


protected:

  /**
   * @brief Get a reference to the head node.
   * @return a reference to the head node.
   */
  typename SNode<T>::Ref head() const;

  //TODO
  //Give a representation using a simple linked list of nodes.
  //We want a size() operation with O(1).
  typename SNode<T>::Ref _head;
  typename SNode<T>::Ref _cursor;
  int _size;
  //
};


#include "slist_imp.hpp"