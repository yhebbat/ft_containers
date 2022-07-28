#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include <memory>
#include <iostream>
#include "iterator_traits.hpp"
#include "../utilities/utilities.hpp"
#include "../map/avl_tree.hpp"

namespace ft
{
    template < typename T , typename Compare = std::less< typename T::first_type > >
    class bidirectional_iterator
    {
        public:
            typedef typename iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
            typedef	typename iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
            typedef typename iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
            typedef	typename iterator<std::bidirectional_iterator_tag, T>::reference			reference;
            typedef	typename iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
            typedef	Compare                                                                         compare;
            typedef avl_tree<T, Compare>                                               tree_type;
            typedef node<T>                                                            node_type;
        private:
			node_type		    *_node;
			tree_type			*_tree;
        public:
            bidirectional_iterator() : _node(NULL), _tree(NULL) {}
            bidirectional_iterator(node_type *node, tree_type *tree) : _node(node), _tree(tree) {};
            bidirectional_iterator(const bidirectional_iterator &other) {*this = other;};
            ~bidirectional_iterator() {};
            bidirectional_iterator &operator=(const bidirectional_iterator &other)
            { 

                this->_node = other._node;
                this->_tree = other._tree;
                return *this;
            };

            bool operator==(const bidirectional_iterator &other) const { return (_node == other._node); };
            bool operator!=(const bidirectional_iterator &other) const { return (_node != other._node); };

            reference operator*() const{ return _node->data; };
            pointer operator->() const{ return &(_node->data); };

            bidirectional_iterator &operator++()
            {
                _node = _tree->find_next(_node);
                return *this;
            };
            bidirectional_iterator operator++(int)
            {
                bidirectional_iterator tmp(*this);
                ++(*this);
                return tmp;
            };
            bidirectional_iterator &operator--()
            {
                _node = _tree->find_prev(_node);
                return *this;
            };
            bidirectional_iterator operator--(int)
            {
                bidirectional_iterator tmp(*this);
                --(*this);
                return tmp;
            };

            node_type *node() const { return _node; };

            operator bidirectional_iterator< const T, compare>() const//to check
            {
                return bidirectional_iterator< const T, compare>(this->_node, this->_tree);
            };
    };
}

#endif