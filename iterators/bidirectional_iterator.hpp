#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include <memory>
#include <iostream>
#include "iterator_traits.hpp"
#include "../utilities/utilities.hpp"
#include "../map/avl_tree.hpp"

namespace ft
{
    template < typename Category, typename Tree, typename Node, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
    class bidirectional_iterator
    {
        public: 
            typedef Category 	iterator_category;
            typedef T			value_type;
            typedef Distance	difference_type;
            typedef Pointer		pointer;
            typedef Reference	reference;
            typedef Node		node_type;
            typedef Tree		tree_type;
        private:
			node_type		    *_node;
			tree_type			*_tree;
        public:
            bidirectional_iterator() : _node(), _tree() {}
            bidirectional_iterator(  node_type *n, tree_type *t) :  _node(n),  _tree(t) { };

            bidirectional_iterator(const bidirectional_iterator &other) {*this = other;};
            // template < typename C, typename TT, typename N, typename TTT >
            // bidirectional_iterator(const bidirectional_iterator<C, TT, N, TTT > &other)
            // {
            //     *this = other;
            // };
            ~bidirectional_iterator() {};

            bidirectional_iterator &operator=(const bidirectional_iterator &other)
            { 

                this->_node = other._node;
                this->_tree = other._tree;
                return *this;
            };

		    bool operator==(const bidirectional_iterator & a) const
            {
                if (this->_node == a._node)
                    return true;
                else
                    return false;
            }

            bool operator!=(const bidirectional_iterator & a) const
            {
                if (this->_node == a._node)
                    return false;
                else
                    return true;
            }
            reference operator*() const{ return _node->data; };
            pointer operator->() const{ return &(_node->data); };

            bidirectional_iterator &operator++()//to do
            {
                if (_node == NULL){
                    _node = _tree->_root;
                    while (_node != NULL && _node->left != NULL) // min value in the tree
                        _node = _node->left;
                }
                if(_node->right)
                {
                    _node = _node->right;
                    while (_node->left != NULL)
                        _node = _node->left;
                }
                else if(_node->parent)
                {
                    node_type *dad = _node->parent;
                    if (dad->left == _node)
                        _node = dad;
                    else if(dad->right == _node)
                    {
                        while(dad && dad->right == _node)
                        {
                            _node = dad;
                            dad = _node->parent;
                        }
                        _node = dad;
                    }
                }
                else if (_node == _tree->find_max())
                    _node = NULL;
                return (*this);
            };
            bidirectional_iterator operator++(int)//TO check
            {
                bidirectional_iterator tmp(*this);
                ++(*this);
                return tmp;
            };
            bidirectional_iterator &operator--()//to do
            {
                // // _node = _tree->find_prev(_node);
                // // return *this;
                if (_node == NULL){
                    _node = _tree->_root;
                    while (_node != NULL && _node->right != NULL) // max value in the tree
                        _node = _node->right;
                }
                else if(_node->left)
                {
                    _node = _node->left;
                    while (_node->right != NULL)
                        _node = _node->right;
                }
                else if(_node->parent)
                {
                    node_type *dad = _node->parent;
                    if (dad->right == _node)
                        _node = dad;
                    else if(dad->left == _node)
                    {
                        while(dad && dad->left == _node)
                        {
                            _node = dad;
                            dad = _node->parent;
                        }
                        _node = dad;
                    }
                }
                else if (_node == _tree->find_min())
                    _node = NULL;
                return (*this);
            };
            bidirectional_iterator operator--(int)//to check
            {
                bidirectional_iterator tmp(*this);
                --(*this);
                return tmp;
            };

            node_type *get_node() const { return _node; };
            
            operator bidirectional_iterator<iterator_category, const tree_type, const node_type, const T>()
            {
			    return bidirectional_iterator<iterator_category, const tree_type, const node_type, const T>(_node, _tree);
		    }
            
    };

    
}

#endif