#ifndef MAP_HPP
#define MAP_HPP

#include "../utilities/utilities.hpp"
#include "../iterator/biderectional_iterator.hpp"
#include "../iterator/iterator.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../iterator/random_access_iterator.hpp"
#include "avl_tree.hpp"

namespace ft
{

    template <class Key,                                           // map::key_type
              class T,                                             // map::mapped_type
              class Compare = std::less<Key>,                      // map::key_compare
              class Alloc = std::allocator<ft::pair<const Key, T> > // map::allocator_type
              >
    class map
    {
    public:
        typedef Key                                                     key_type;
        typedef T                                                       mapped_type;
        typedef typename ft::pair<const key_type, mapped_type>          value_type;
        typedef Compare                                                 key_compare;
        typedef Alloc                                                   allocator_type;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;
        // typedef typename ft::avl_tree<Key, mapped_type, Compare, Alloc> tree;
        // typedef ft::node<value_type> node_type;
        typedef ft::bidirectional_iterator<node_type, value_type>       iterator;
        typedef ft::const_bidirectional_iterator<node_type, value_type> const_iterator;
        typedef ft::reverse_iterator<iterator>                          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
        typedef ptrdiff_t                                               difference_type;
        typedef size_t                                                  size_type;
        typedef class value_compare : public std::binary_function<value_type, value_type, bool>
        {
        protected:
            key_compare _compare;

        public:
            value_compare(key_compare c) : _compare(c) {}
            bool operator()(const value_type &x, const value_type &y) const
            {
                return _compare(x.first, y.first);
            }
        } value_compare;

    private:
        tree _tree;
        key_compare _compare;
        allocator_type _allocator;
    };
}
#endif