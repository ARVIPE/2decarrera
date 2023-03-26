/**
 * @file rbtree.hpp
 *
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
#include <functional>
#include <memory>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

/**
 * @brief a RBTree's Node.
 * Models a node of RBTree.
 */
template <class T>
class RBTNode
{
public:
  /** @brief Define a shared reference to a RBTNode.
   * Manages the storage of a pointer, providing a limited garbage-collection
   * facility, possibly sharing that management with other objects.
   * @see http://www.cplusplus.com/reference/memory/shared_ptr/
   */
  typedef std::shared_ptr<RBTNode<T>> Ref;

  /**
   * @brief Colors for a node of the RBTree.
   */
  typedef enum
  {
    BLACK = 0,
    RED = 1
  } Color;

  /** @name Life cicle.*/
  /** @{*/

  /**
   * @brief Create a RBTNode.
   * @param it is the node's item value.
   * @param parent is a link to the parent node of this.
   * @param left is a link to the left child node.
   * @param right is a link to the right child node.
   * @return a shared reference to node created.
   */
  static typename RBTNode<T>::Ref create(T const &it = T(),
                                         RBTNode<T>::Color color = RED,
                                         RBTNode<T>::Ref parent = nullptr,
                                         RBTNode<T>::Ref left = nullptr,
                                         RBTNode<T>::Ref right = nullptr);
  /** @brief Destroy a RBTNode. **/
  ~RBTNode();

  /** @}*/

  /** @name Observers.*/
  /** @{*/

  /** @brief Get the data item.*/
  T item() const;

  /** @brief get the parent.*/
  RBTNode<T>::Ref parent() const;

  /** @brief get the left child.*/
  RBTNode<T>::Ref left() const;

  /** @brief get the right child.*/
  RBTNode<T>::Ref right() const;

  /**
   * @brief get one of the two childs.
   * @param idx specifies the what child: 0->left, 1->right.
   * @pre idx in {0,1}
   * @post idx==0 || child(idx)==right()
   * @post idx==1 || child(idx)==left()
   */
  RBTNode<T>::Ref child(int idx) const;

  /** @brief get node's color. */
  RBTNode<T>::Color color() const;

  /** 
   * @brief Return "this" as a reference.   
   * @return a const reference to this node.
  */
  const Ref& This() const;

  /** 
   * @brief Return "this" as a reference.   
   * @return a reference to this node.
  */
  Ref This();

  /** @}*/

  /** @name Modifiers.*/
  /** @{*/

  /**
   * @brief Set the data item.
   * @post item() == new_it
   */
  void set_item(const T &new_it);

  /**
   * @brief Set the parent.
   * @post parent()==new_parent
   * @post !new_parent || (new_parent->left()==This() || new_parent->right()==This())
   */
  void set_parent(Ref new_parent);

  /**
   * @brief Set the left child.
   * @post left()==new_child
   * @post !new_child || new_child.parent()==This()
   * @warning collateral effect: change new_child parent link to this.
   */
  void set_left(Ref new_child);

  /**
   * @brief Set the right child.
   * @post right()==new_child
   * @post !new_child || new_child.parent()==This()
   * @warning collateral effect: change new_child parent link to this.
   */
  void set_right(Ref new_child);

  /**
   * @brief Set one of the two childs.
   * @param idx specifies what child: 0->left, 1->right.
   * @param new_child is the new to child to attach.
   * @pre idx in {0,1}
   * @post idx==0 || new_child==right()
   * @post idx==1 || new_child==left()
   * @post !new_child || new_child.parent()==This()
   * @warning collateral effect: change new_child parent link to this.
   */
  void set_child(int idx, RBTNode<T>::Ref new_child);

  /**
   * @brief Set the color of the node.
   * @param[in] new_color.
   * @post color()==new_color
   */
  void set_color(Color new_color);

protected:

/**
   * @brief Create a RBTNode.
   * @param it is the node's item value.
   * @param color is the color of the node.
   * @param parent is a link to the parent node of this.
   * @param left is a link to the left child node.
   * @param right is a link to the right child node.
   * @return a shared reference to node created.
   */
  RBTNode(T const &it = T(), RBTNode<T>::Color color = RED, RBTNode<T>::Ref parent = nullptr,
          RBTNode<T>::Ref left = nullptr, RBTNode<T>::Ref right = nullptr);

  // TODO
  // Give a representation.
    T item_;
    typename RBTNode<T>::Color color_;
    typename RBTNode<T>::Ref parent_;
    typename RBTNode<T>::Ref left_;
    typename RBTNode<T>::Ref right_;
  
  //
  RBTNode<T>::Ref this_; //"this" like a shared reference.
};

/**
 * @brief ADT RBTree.
 * A RBTree (red/black tree) is a self-balanced binary search tree that meets
 * the next properties:
 * @invariant is_a_binary_search_tree()
 * @invariant the red condition.
 * @invariant the black condition.
 */
template <class T>
class RBTree
{
public:
  /** @brief Define a shared reference to a RBTNode.
   * Manages the storage of a pointer, providing a limited garbage-collection
   * facility, possibly sharing that management with other objects.
   * @see http://www.cplusplus.com/reference/memory/shared_ptr/
   */
  typedef std::shared_ptr<RBTree<T>> Ref;

  /** @name Life cicle.*/
  /** @{*/

  /**
   * @brief Create an empty RBTree.
   * @return a shared reference to the new tree.
   */
  static typename RBTree<T>::Ref create();

  /**
   * @brief Create a leaf tree.
   * @post is_empty()
   */
  static typename RBTree<T>::Ref create(T const &item);

  /**
   * @brief Unfold an RBTree from an input stream.
   * The input format will be:
   * '[]' for the empty tree.
   * '[ '<item>' '<R|B>' '<left-subtree>' '<right-subtree>' ]'
   *
   * For example a tree with three nodes:
   * "[ 2 B [ 1 R [] [] ] [ 3 R [] [] ] ]"
   *
   * @param in is the input stream.
   * @param parent is the parent node of the node to be unfolded.
   * @return The node unfolded on success.
   * @warning std::runtime_error("Wrong input format"),
   * std::runtime_error("It is not a binary search tree") or
   * std::runtime_error("It is not an rbtree") will throw if an error
   * happened.
   */
  static typename RBTree<T>::Ref create(std::istream &in) noexcept(false);

  /** @brief Destroy a RBTree.**/
  ~RBTree();

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is it empty?.*/
  bool is_empty() const;

  /** @brief Get the root item.
   * @pre not is_empty();
   */
  T item() const;

  /**
   * @brief Fold an RBTree into an output stream.
   *  * The output format will be:
   * [ <item> <left> <right> ] or [] if it is a empty tree.
   * @param out is the output stream.
   * @return the output stream.
   */
  std::ostream &fold(std::ostream &out) const;

  /** @brief Is the cursor at a valid position?*/
  bool current_exists() const;

  /**
   * @brief Get the current's item.
   * @return The item save in current node.
   * @pre current_exist()
   */
  T current() const;

  /**
   * @brief Computes the current's level (depth) in the tree.
   * @return the level (depth) of current in the tree.
   * @pre current_exist()
   * @post Time analysis: O(N)
   */
  int current_level() const;

  /**
   * @brief Get the left subtree.
   * @pre !is_empty()
   */
  typename RBTree<T>::Ref left() const;

  /**
   * @brief Get the right subtree.
   * @pre !is_empty()
   */
  typename RBTree<T>::Ref right() const;

  /**
   * @brief Has the tree this key?
   * @post !is_empty() || has==false;
   * @post !old.current_exists() || old.current()==current()
   */
  bool has(const T &k) const;

  /**
   * @brief Get a reference to "this" tree.
   * @return a const reference to this tree.
   */
  const Ref& This() const;

  /**
   * @brief Get a reference to "this" tree.
   * @return a reference to this tree.
   */
  Ref This();

  /**
   * @brief Output a Dot representation of the tree.
   * @param out is the output stream.
   * @return the output stream.
   */
  std::ostream& draw_rbtree(std::ostream &out) const;

  /** @}*/

  /** @name Modifiers*/

  /** @{*/

  /**
   * @brief Create the Root node.
   * @param item is value of the root's item.
   * @pre is_empty()
   * @post !is_empty()
   * @post item()==item
   */
  void create_root(T const &item);

  /**
   * @brief Search a key moving the cursor.
   * @post search==false || current()==k
   * @post search==true || !current_exits()
   */
  bool search(T const &k);

  /**
   * @brief Insert a new key in the tree.
   * @warning if k is already in the tree, only it is updated.
   * @post current_exists()
   * @post current()==k
   */
  void insert(T const &k);

  /**
   * @brief remove current from the tree.
   * @pre current_exists()
   * @post not current_exists()
   */
  void remove();

  /** @}*/

protected:

  /**
   * @brief Create an empty RBTree.
   * We only want to create References using "create" methods.
   * @post is_empty()
   */
  RBTree();

  /**
   * @brief Create a leaf tree.
   * We only want to create References using "create" methods.
   * @post !is_empty()
   */
  RBTree(T const &item);

  /** 
   * @brief Create a RBTree using a given node as root.
   * We only want to create References using "create" methods.
   */
  RBTree(typename RBTNode<T>::Ref root_node);

  /**
   * @brief Create a RBTree given a node as root.
   * Use this method to generate the left/right subtrees rooted on node.
   * @param root is the root node of the new sub-tree.
   * @return a shared reference to the new sub-tree.
   */
  static typename RBTree<T>::Ref create(typename RBTNode<T>::Ref root);

  /**
   * @brief Check the binary search tree invariant.
   * @return true if in-order traversal follow an ordered key sequence.
   * @post Time Analysis: O(N)
   */
  bool is_a_binary_search_tree() const;

  /**
   * @brief Check the Red tree invariant.
   * A Red node must not have a red child.
   * @return true if the invariant is met.
   */
  bool meet_red_invariant() const;

  /**
   * @brief Check the Red tree invariant.
   * All paths from root node to any leaf must have the same black length.
   * @return true if the invariant is met.
   */
  bool meet_black_invariant() const;

  /**
   * @brief Check if the tree is a rbtree.
   * A rbtree is a colored bstree that meet both the red and black invariants.
   * @return true if the invariant is met.
   */
  bool is_a_rbtree() const;
  
  /**
   * @brief Attach a new subtree as left child.
   * @param subtree is the tree to be attached.
   * @post (subtree->is_empty() || left()->item()==subtree->item())
   * @post (!subtree->is_empty() || left()->is_empty())
   * @warning this method does not check invariants.
   */
  void set_left(Ref subtree);

  /**
   * @brief Attach a new subtree as right child.
   * @param subtree is the tree to be attached.
   * @post (subtree->is_empty()|| right()->item()==subtree->item())
   * @post (!subtree->is_empty()|| right()->is_empty())
   * @warning this method does not check invariants.
   */
  void set_right(Ref subtree);

  /**
   * @brief find the in order successor of current.
   * @pre current_exist()
   * @post current_exist() && !current_->has_left()
   * @post current()>old.current()
   */
  void find_inorder_successor();

  /**
   * @brief rotate to re-balanced a subtree.
   *
   * Rotate left (@a dir == 0)
   *
   *               P      ->    S
   *              / \          / \
   *             N   S        P   D
   *                /  \     / \
   *               C    D   N   C
   *
   * Rotate right (@a dir == 1)
   *
   *               P      ->    S
   *              / \          / \
   *             S   N        D   P
   *           /  \              / \
   *          D    C            C   N
   *
   * @param P is the root node of the subtree.
   * @param dir is the direction (0->left, 1->right) to rotate.
   * @return S, the new root node of the rotated subtree.
   * @pre P!=nullptr
   * @pre dir in {0,1}
   * @pre S==P->child(1-dir) != nullptr
   */
  typename RBTNode<T>::Ref rotate(typename RBTNode<T>::Ref P, int dir);

  /**
   * @brief Restore the red and black conditions after inserting.
   */
  void make_red_black_after_inserting();

  /**
   * @brief Restore the red and black conditions after removing.
   * @param V is the root of the subtree that replaced the removed node.
   */
  void make_red_black_after_removing(typename RBTNode<T>::Ref V);
  
  /**
   * @brief get the root node.
   * @return the root node.
   */
  typename RBTNode<T>::Ref root_node() const;

  /**
   * @brief set a new root node.
   * @param new_root is the new tree's root node.
   * @post root_node()==new_root
   */
  void set_root_node(typename RBTNode<T>::Ref new_root);

  /**
   * @brief get the current node.
   * @return the current node.
   */
  typename RBTNode<T>::Ref current_node() const;

  /**
   * @brief set a new current node.
   * @param new_root is the new current node.
   * @post current_node()==new_curr
   */
  void set_current_node(typename RBTNode<T>::Ref new_curr);

  /**
   * @brief get the parent node.
   * @return the parent node.
   */
  typename RBTNode<T>::Ref parent_node() const;

  /**
   * @brief Check the chains from leaf nodes to the root node are ok.
   */
  bool check_parent_chains();

  /**
   * @brief Check Red-Black tree property.
   * 
   * Number of nodes from a node to its farthest descendant leaf is no more 
   * than twice as the number of nodes to the nearest descendant leaf.
   * We test this from the root node only.
   *    
   * @return true if the property is meet.   
   */    
  bool check_min_max_branch_length() const;


  int prefix_draw_node(std::ostream &out, typename RBTNode<T>::Ref const &node) const;
  

  // TODO
  // Give a representation.
    typename RBTNode<T>::Ref current_;
   typename RBTNode<T>::Ref parent_;
   typename RBTNode<T>::Ref root_;
  
  //
  Ref this_;
};

#ifdef __ONLY_BSTREE__
/**
 * @brief create a perfectly balanced BSTree.
 * @param data are the keys to be stored.
 * @return the created tree.
 * @pre data.size()>0
 * @post for each subtree: |right()->size() - left()->size()|<=1
 */
template <class T>
typename RBTree<T>::Ref create_perfectly_balanced_bstree(std::vector<T> &data);
#endif //__ONLY_BSTREE__

/**
 * @brief Return the number of keys stored in the tree.
 * @param tree is the tree.
 * @return the tree's size.
 */
template <class T>
size_t compute_size(typename RBTree<T>::Ref const& tree);

/**
 * @brief Return the tree's height.
 * @param tree is the tree.
 * @return the tree's height.
 */
template <class T>
int compute_height(typename RBTree<T>::Ref const& tree);

#include "rbtree_imp.hpp"
