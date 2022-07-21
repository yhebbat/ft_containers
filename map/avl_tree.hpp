#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>
#include "../utilities/utilities.hpp"

namespace ft
{
    template <typename T>
    class node
    {
        public:            
            T           data;
            node<T>     *left;
            node<T>     *right;
            node<T>     *parent;
            int			height;
            // int			balance_factor;
			node(): left(nullptr), right(nullptr), parent(nullptr), height(0), balance_factor(0) {};
			~node(){};
	};

    template <class Key,                                           // map::key_type
              class T,                                             // map::mapped_type
              class Compare = std::less<Key>,                      // map::key_compare
              class Alloc = std::allocator<ft::pair<const Key, T> > // map::allocator_type
              >

    class avl_tree
    {
        public:
            // typedef Key                                   key_type;
            // typedef T                                     mapped_type;
            // typedef ft::pair<const key_type, mapped_type> value_type;
            // typedef node<value_type>                      node_type;
            // typedef Alloc                                 allocator_type;
            // typedef typename Alloc::template rebind<node_type>::other node_allocator;
            // typedef ptrdiff_t                             difference_type;
            // typedef size_t                                size_type;
            // node_type                                     *_root;
            // typedef bidirectional_iterator<node_type, value_type> iterator;
        // public:
        //     avl_tree();
        //     ~avl_tree();
        //     void insert(int key);
        //     void remove(int key);
        //     bool contains(int key);
        //     void print();
    }
}
#endif