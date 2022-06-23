#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <vector>

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator 
{
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
};


template <class T>
class my_iterator
{
    private:
        T *_ptr;
    public:
        typedef typename iterator<std::random_access_iterator_tag, T>::T         value_type;
        typedef typename iterator<std::random_access_iterator_tag, T>::Distance  difference_type;
        typedef typename iterator<std::random_access_iterator_tag, T>::Pointer   pointer;
        typedef typename iterator<std::random_access_iterator_tag, T>::Reference reference;
        typedef typename iterator<std::random_access_iterator_tag, T>::Category  iterator_category;
        my_iterator() {};
        my_iterator(my_iterator const &to_copy) { _ptr = to_copy._ptr; };
        my_iterator(T *to_copy) { _ptr = to_copy;};
        
        ~my_iterator() {};

};


#endif
