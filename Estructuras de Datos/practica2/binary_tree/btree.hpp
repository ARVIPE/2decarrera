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
#include <sstream>

/** @brief a BTree's Node.*/
template <class T>
class BTNode
{
public:

    /** @brief Define a shared reference to a BTNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< BTNode<T> > Ref;

    /** @name Life cycle.*/
    /** @{*/

    /**
     *  @brief Create a BTNode.
     * @param it the value save in the node.
     * @param l links to the left child.
     * @param r links to the right child.
     * @post item()==it
     * @post left()==l
     * @post right()==r
    */
    BTNode (T const& it=T(), BTNode<T>::Ref l=nullptr,
            BTNode<T>::Ref r=nullptr);

    /**
     * @brief Create a BTNode using dynamic memory.
     * @param it the value save in the node.
     * @param left links to the left child.
     * @param right links to the right child.
     * @return a shared reference to the new node.
     */
    static typename BTNode<T>::Ref create(T const& it,
                                          BTNode<T>::Ref left=nullptr,
                                          BTNode<T>::Ref right=nullptr);

    /** @brief Destroy a BTNode. **/
    ~BTNode()
    {}

    /** @}*/

    /** @name Observers.*/
    /** @{*/

    /** @brief Get the data item.*/
    T item() const;

    /** @brief get the left child.*/
    typename BTNode<T>::Ref left() const;

    /** @brief get the right child.*/
    typename BTNode<T>::Ref right() const;
    /** @}*/

    /** @name Modifiers.*/
    /** @{*/

    /** @brief Set the data item.
     *  @post item()==new_it
     */
    void set_item(const T& new_it);

    /** @brief Set the left child.*/
    void set_left(BTNode<T>::Ref new_child);

    /** @brief Set the right child. */
    void set_right(BTNode<T>::Ref new_child);

    /** }*/
protected:
    //TODO
    //Specify a representation.
    //Hint: use typename BTNode<T>::Ref for the link to other nodes.
    typename BTNode<T>::Ref _left;
    typename BTNode<T>::Ref _right;
    T _item;
    //
};

/**
 * @brief ADT BTree.
 * Models a BTree of T.
 */
template<class T>
class BTree
{
  public:

    /** @brief Define a shared reference to a BTNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< BTree<T> > Ref;

  /** @name Life cycle.*/
  /** @{*/

    /** @brief Create an empty BTree.
     * @post is_empty()
     */
    BTree ();

  /** @brief Create Leaf BTree.
   * @post not is_empty()
   * @post left()->is_emtpy()
   * @post right()->is_emtpy()
   */
  BTree (const T& item);

  /**
   * @brief Create an empty BTree.
   * @return a shared reference to the new tree.
   */
  static typename BTree<T>::Ref create();

  /**
   * @brief Create a leaf BTree.
   * @param item is the root's item.   
   * @return a shared reference to the new tree.
   */
  static typename BTree<T>::Ref create(T const& item);

  /**
   * @brief Load a tree from a input stream.
   *
   * The input format will be:
   * '[]' for the empty tree.
   * '[ <item> <left-subtree> <right-subtree> ']'
   *
   * For example a tree with three nodes:
   * "[ 2 [ 1 [] [] ] [ 3 [] [] ] ]"
   *
   * @return a reference to the tree created.
   * @warning runtime_error will throw if wrong input format was found.
   */
  static typename BTree<T>::Ref create (std::istream& in) noexcept(false);

  /** @brief Destroy a BTree.**/
  ~BTree()
  {}

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the tree empty?.*/
  bool is_empty () const;

  /** @brief Get the root item.
   * @pre not is_empty();
   */
  T item() const;

  /**
   * @brief Get the left subtree.
   * @return a reference to the left subtree.
   * @pre !is_empty()
   */
  typename BTree<T>::Ref left() const;

  /**
   * @brief Get the right subtree.
   * @return a reference to the right subtree.
   * @pre !is_empty()   
   */
  typename BTree<T>::Ref right() const;

  /**
   * @brief Fold a binary tree.
   *
   * The output format will be:
   * '[]' for the empty tree.
   * '[ <item> <left-subtree> <right-subtree> ']'
   *
   * For example a tree with three nodes:
   * "[ 2 [ 1 [] [] ] [ 3 [] [] ] ]"
   *
   * @param out is the output stream.
   * @param tree is the tree.
   * @return the output stream.
   * @pre tree!=nullptr
   */
  std::ostream& fold(std::ostream& out) const;

  /** @}*/

  /** @name Modifiers*/

  /** @{*/

  /**
   * @brief create the root node.
   * @arg it is the item to be stored.
   * @pre is_empty()
   * @post !is_empty()
   * @post item()==it
   * @post left()->is_empty()
   * @post right()->is_empty()
   */
  void create_root(T const& it);

  /**
   * @brief set the root's item.
   * @pre not is_empty()
   */
  void set_item(const T& new_it);

  /**
   * @brief Attach a new subtree as left child of root.
   * @param new_left is the new left subtree.
   * @pre !is_empty()
   */
  void set_left(typename BTree<T>::Ref new_left);

  /**
   * @brief Attach a new subtree as right child of root.
   * @param new_right is the new right subtree.
   */
  void set_right(typename BTree<T>::Ref new_right);

  /** @}*/

protected:

  /** @brief Create a BTree using a given node as root.*/
  BTree (typename BTNode<T>::Ref root);

  /**
   * @brief Create a BTree.
   * @param root is the root node.
   * @post root!=nullptr or is_empty()
   * @return a shared reference to the new tree.
   */
  static typename BTree<T>::Ref create(typename BTNode<T>::Ref root);

  /**
   * @brief Get the root node.
   * @return a reference to the root node or nullptr if it is empty.
   */
  typename BTNode<T>::Ref root() const;

  /**
   * @brief set a new root node.
   */
  void set_root(typename BTNode<T>::Ref new_root);
 
  //TODO
   typename BTNode<T>::Ref _root;
  //Give a representation.

};

#include "btree_imp.hpp"