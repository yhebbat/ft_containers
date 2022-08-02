#ifndef MAP_HPP
#define MAP_HPP

#include "../utilities/utilities.hpp"
#include "../vector/vector.hpp"
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
        typedef T                                               mapped_type;
        typedef Key                                             key_type;
        typedef typename ft::pair< const Key,T>                 value_type;
        typedef Compare                                         key_compare;
        typedef class value_compare: public std::binary_function<value_type, value_type, bool>
        {
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
        typedef typename ft::avl_tree<value_type, key_compare, allocator_type>  tree_type;
        typedef ft::node<value_type, allocator_type>                            node_type;
        typedef typename ft::bidirectional_iterator<std::bidirectional_iterator_tag, tree_type, node_type, value_type>                       iterator;
        typedef typename ft::bidirectional_iterator<std::bidirectional_iterator_tag, const tree_type, const node_type, const value_type>     const_iterator;
        typedef  ft::reverse_iterator<iterator>                         reverse_iterator;
        typedef  ft::reverse_iterator<const_iterator>                   const_reverse_iterator;
        typedef ptrdiff_t                                               difference_type;
        typedef size_t                                                  size_type;
        
    private:
        key_compare		_cmp;
        allocator_type	_alloc;
        tree_type		_tree;
    public:
        explicit map (const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type()):
                    _cmp(comp), _alloc(alloc), _tree() {};
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
             const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type()):
             _cmp(comp), _alloc(alloc), _tree()
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
            this->_cmp = x._cmp;
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
            node_type* p = _tree.insert(ft::make_pair(k, mapped_type()));
            node_type *node = _tree.search(p->data.first);
            return (node->data.second);
        }
        /*
                                            *********  Modifiers ***********
        */

        // void    insert (const value_type& val){
        //     _tree.insert(val);
        // }
        pair<iterator,bool> insert (const value_type& val)
        {
           if (_tree.exist(val.first))
               return ft::pair<iterator,bool>(iterator(_tree.search(val.first), &_tree), false);
           ft::pair<iterator,bool>(iterator(_tree.insert(val), &_tree), true);
        //    _tree.print_tree();
           return ft::pair<iterator,bool>(iterator(_tree.insert(val), &_tree), true);
        }
        iterator insert (iterator position, const value_type& val)
        {
            (void)position;
            if (_tree.exist(val.first))
                return iterator(_tree.search(val.first), &_tree);
            return iterator(_tree.insert(val), &_tree);
        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                _tree.insert(*first);
                ++first;
            }
        }
        void erase(iterator position)
        {
            _tree.delete_(position.get_node()->data.first);
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
        //         v.push_back(first.node()->data.first);
        //     for(ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        //         erase(*it);
        // }
        void swap (map& x)
        {
            _tree.swap(x._tree);
            std::swap(_cmp, x._cmp);
            std::swap(_alloc, x._alloc);
        }
        void clear() {_tree.clear();}
        /*
                                            ********* Observers ***********
        */
        key_compare key_comp() const {return _cmp;}
        value_compare value_comp() const {return value_compare(_cmp);}
        /*
                                            ********* Operations ***********
        */
        iterator find (const key_type& k)
        {
            node_type* p = _tree.search(k);
            return iterator(p, &_tree);
        }
        const_iterator find (const key_type& k) const
        {
            node_type* p = _tree.search(k);
            return const_iterator(p, &_tree);
        }
        size_type count (const key_type& k) const
        {
            if (_tree.exist(k))
                return 1;
            return 0;
        }
        iterator lower_bound (const key_type& k)
        {
            if (_tree.exist(k))
                return iterator(_tree.search(k), &_tree);
            else if (_cmp(k, _tree.find_min()->data.first))
                return this->begin();
            else if (_cmp(_tree.find_max()->data.first, k))
                return this->end();
            else
            {
                iterator it = this->begin();
                for(; it != this->end(); ++it)
                {
                    if (_cmp(it->first, k))
                        it++;
                    else
                        break;
                }
                return (it);
            }
        }
        const_iterator lower_bound (const key_type& k) const
        {
            if (_tree.exist(k))
                return const_iterator(_tree.search(k), &_tree);
            else if (_cmp(k, _tree.find_min()->data.first))
                return this->begin();
            else if (_cmp(_tree.find_max()->data.first, k))
                return this->end();
            else
            {
                const_iterator it = this->begin();
                for(; it != this->end(); ++it)
                {
                    if (_cmp(it->first, k))
                        it++;
                    else
                        break;
                }
                return (it);
            }
        }
        iterator upper_bound (const key_type& k)
        {
            if (_tree.exist(k))
            {
                iterator it = this->find(k);
                it++;
                return it;
            }
            else if (_cmp(k, _tree.find_min()->data.first))
                return this->begin();
            else if (_cmp(_tree.find_max()->data.first, k))
                return this->end();
            else
            {
                iterator it = this->begin();
                for(; it != this->end(); ++it)
                {
                    if (_cmp(it->first, k))
                        it++;
                    else
                        break;
                }
                return (it);
            }
        }
        const_iterator upper_bound (const key_type& k) const
        {
            if (_tree.exist(k))
            {
                const_iterator it = this->find(k);
                it++;
                return it;
            }
            else if (_cmp(k, _tree.find_min()->data.first))
                return this->begin();
            else if (_cmp(_tree.find_max()->data.first, k))
                return this->end();
            else
            {
                const_iterator it = this->begin();
                for(; it != this->end(); ++it)
                {
                    if (_cmp(it->first, k))
                        it++;
                    else
                        break;
                }
                return (it);
            }
        }
        pair<iterator,iterator> equal_range (const key_type& k)
        {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        }
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        }
        /*
                                            ********* Allocator ***********
        */
        allocator_type get_allocator() const {return _alloc;}

        void Test(){
            _tree.print_tree();
        }
    };
    template <class Key, class T, class Compare, class Alloc>
    bool operator== (  const map<Key,T,Compare,Alloc>& lhs,
                     const map<Key,T,Compare,Alloc>& rhs )
                    {
                        if (lhs.size() != rhs.size())
                            return false;
                        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
                    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator!= (  const map<Key,T,Compare,Alloc>& lhs,
                         const map<Key,T,Compare,Alloc>& rhs )
                    {
                        return !(lhs == rhs);
                    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator< (  const map<Key,T,Compare,Alloc>& lhs,
                     const map<Key,T,Compare,Alloc>& rhs )
                    {
                        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
                    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<= (  const map<Key,T,Compare,Alloc>& lhs,
                     const map<Key,T,Compare,Alloc>& rhs )
                    {
                        return !(rhs < lhs);
                    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator> (  const map<Key,T,Compare,Alloc>& lhs,
                     const map<Key,T,Compare,Alloc>& rhs )
                    {
                        return (rhs < lhs);
                    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>= (  const map<Key,T,Compare,Alloc>& lhs,
                     const map<Key,T,Compare,Alloc>& rhs )
                    {
                        return !(lhs < rhs);
                    }
    template <class Key, class T, class Compare, class Alloc>
      void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y){x.swap(y);}
}
#endif