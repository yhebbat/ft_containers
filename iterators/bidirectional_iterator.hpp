#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include <memory>
#include <iostream>
#include "iterator_traits.hpp"
#include "../utilities/utilities.hpp"
#include "../map/avl_tree.hpp"

namespace ft
{
    template < typename Value_type, typename node_type>
    class bidirectional_iterator
    {
        public: 
            typedef typename std::bidirectional_iterator_tag	       iterator_category;
            typedef Value_type			                                 value_type;
            typedef ptrdiff_t	                                        difference_type;
            typedef value_type*		                                        pointer;
            typedef value_type&	                                        reference;
            // typedef Node		                                        node_type;
            // typedef Tree		                                        tree_type;
            // typedef typename ft::node<T, typename Tree::allocator_type> Node;
        private:
			node_type		    _node;
			node_type			_root;
        public:
            bidirectional_iterator() : _node(), _root() {}
            bidirectional_iterator( node_type n, node_type t) :  _node(n),  _root(t) { };

            bidirectional_iterator(const bidirectional_iterator &other) {*this = other;};
            template <typename U, typename V>
            bidirectional_iterator(const bidirectional_iterator<U, V> &other)
            {
                this->_node = other.get_node();
                this->_root = other.get_root();
            };

            ~bidirectional_iterator() {};

            bidirectional_iterator &operator=(const bidirectional_iterator &other)
            { 

                this->_node = other.get_node();
                this->_root = other.get_root();
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
                    _node = _root;
                    while (_node != NULL && _node->left != NULL) // min value
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
                    node_type dad = _node->parent;
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
                else if (_node == max(_root))
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
                    _node = _root;
                    while (_node != NULL && _node->right != NULL) // max value
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
                    node_type dad = _node->parent;
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
                else if (_node == min(_root))
                    _node = NULL;
                return (*this);
            };
            bidirectional_iterator operator--(int)//to check
            {
                bidirectional_iterator tmp(*this);
                --(*this);
                return tmp;
            };

            node_type get_node() const { return _node; };
            
            operator bidirectional_iterator<const value_type, node_type>()
            {
			    return bidirectional_iterator<const value_type, node_type>(_node, _root);
		    }
            
            node_type get_root()const{
                return _root;
            }

            private:
            node_type max(node_type root){
                node_type tmp = root;
                while (tmp != NULL && tmp->right != NULL) // max value
                        tmp = tmp->right;
                return tmp;
            }

            node_type min(node_type root){
                node_type tmp = root;
                while (tmp != NULL && tmp->left != NULL) // min value
                        tmp = tmp->left;
                return tmp;
            }

            
    };

    
}

#endif