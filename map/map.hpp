#ifndef MAP_HPP
#define MAP_HPP

#include "../utilities/utilities.hpp"
#include "../iterators/bidirectional_iterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/random_access_iterator.hpp"
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
        typedef ft::pair<const Key,T>                           value_type;
        typedef Key                                             key_type;
        typedef T                                               mapped_type;
        typedef Compare                                         key_compare;
        typedef class value_compare: public std::binary_function<value_type, value_type, bool>
        {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            friend class map;
            protected:
            Compare comp;
            value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
            public:
                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;
                bool operator() (const value_type& x, const value_type& y) const
                {
                    return comp(x.first, y.first);
                }
        } value_compare;
        typedef Alloc											                allocator_type;
        typedef typename allocator_type::reference                              reference;
        typedef typename allocator_type::const_reference                        const_reference;
        typedef typename allocator_type::pointer                                pointer;
        typedef typename allocator_type::const_pointer                          const_pointer;
        typedef typename ft::bidirectional_iterator<value_type, key_compare>    iterator;
        typedef typename ft::bidirectional_iterator< const value_type,const key_compare> const_iterator;
        typedef typename ft::reverse_iterator<iterator>                         reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator>                   const_reverse_iterator;
        typedef ptrdiff_t                                                       difference_type;
        typedef size_t                                                          size_type;
    private:
        typedef ft::node<value_type>                                            node_type;
        typedef ft::avl_tree<value_type, key_compare, allocator_type>           tree_type;
        key_compare		_comp;
        allocator_type	_alloc;
        tree_type		_tree;
    public:
        explicit map (const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type()):
                    _comp(comp), _alloc(alloc), _tree() {};
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
             const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type()):
             _comp(comp), _alloc(alloc), _tree()
        {
            while (first != last)
            {
                _tree.insert_(*first);
                ++first;
            }
        };
        map (const map& x) { *this = x; };
        ~map(){};
        map& operator= (const map& x)
        {
            this->_tree.clear();
            this->_tree = x._tree;
            this->_comp = x._comp;
            this->_alloc = x._alloc;
            return *this;
        };
        /*
                                            ********* Iterators ***********
        */
        //************************ Return iterator to beginning of map.
        iterator begin()
        {
            node_type* p = _tree.find_min();
            return iterator(p, &_tree);
        }
        const_iterator begin() const
        {
            node_type* p = _tree.find_min();
            return const_iterator(p, &_tree);
        }
        //************************ Return iterator to end of map.
        iterator end() {return iterator(NULL, &_tree);}
        const_iterator end() const {return const_iterator(NULL, &_tree);}
        //************************ Return reverse iterator to reverse beginning of map.
        reverse_iterator rbegin() {return reverse_iterator(end());}
        const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
        //************************ Return reverse iterator to reverse end of map.
        reverse_iterator rend() {return reverse_iterator(begin());}
        const_reverse_iterator rend() const {return const_reverse_iterator(begin());}
        /*
                                            ********* Capacity ***********
        */
        //************************ Test whether container is empty.
        bool empty() const {return _tree.empty();}
        //************************ Return container size.
        size_type size() const {return _tree.size();}
        //************************ Return container max size.
        size_type max_size() const {return _alloc.max_size();}
        /*
                                            ********* Element access ***********
        */
        //************************ Return reference to element at specified position.
        mapped_type& operator[] (const key_type& k)
        {
            node_type* p = ft::make_pair(k, mapped_type());
            _tree.insert_(p);
            node_type *node = _tree.search(p.first);
            return (node->_data.second);
        }
        /*
                                            *********  Modifiers ***********
        */
        pair<iterator,bool> insert (const value_type& val)
        {
            if (_tree.exist(val.first))
                return ft::pair<iterator,bool>(iterator(_tree.search(val.first), &_tree), false);
            return ft::pair<iterator,bool>(iterator(_tree.insert_(val), &_tree), true);
        }
        iterator insert (iterator position, const value_type& val)
        {
            (void)position;
            if (_tree.exist(val.first))
                return iterator(_tree.search(val.first), &_tree);
            return iterator(_tree.insert_(val), &_tree);
        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                insert(*first);
                ++first;
            }
        }
        void erase(iterator position)
        {
            _tree.delete_(position.node()->_data.first);
        }
        size_type erase (const key_type& k)
        {
            return _tree.delete_(k);
        }
        void erase(iterator first, iterator last)//to check look at fct li lta7t
        {
            while (first != last)
            {
                erase(first);
                ++first;
            }
        }
        // void erase(iterator first, iterator last)
        // {
        //     ft::vector<int> v;
        //     for(; first != last; ++first)
        //         v.push_back(first.node()->_data.first);
        //     for(ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        //         erase(*it);
        // }
        void swap (map& x)
        {
            _tree.swap(x._tree);
            std::swap(_comp, x._comp);
            std::swap(_alloc, x._alloc);
        }
        void clear() {_tree.clear();}
        /*
                                            ********* Observers ***********
        */
        key_compare key_comp() const {return _comp;}
        value_compare value_comp() const {return value_compare(_comp);}
        /*
                                            ********* Operations ***********
        */
        iterator find (const key_type& k)
        {
            node_type* p = _tree.search(k);
            return iterator(p, &_tree);
        }
        size_type count (const key_type& k) const
        {
            if (_tree.exist(k))
                return 1;
            return 0;
        }
    };
}
#endif