#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class my_random_iterator
    {
        private:
            T   *_ptr;
        public:
            typedef typename iterator_traits<std::random_access_iterator_tag, T>::T         value_type;
            typedef typename iterator_traits<std::random_access_iterator_tag, T>::Distance  difference_type;
            typedef typename iterator_traits<std::random_access_iterator_tag, T>::Pointer   pointer;
            typedef typename iterator_traits<std::random_access_iterator_tag, T>::Reference reference;
            typedef typename iterator_traits<std::random_access_iterator_tag, T>::Category  iterator_category;

            //////////////////////////////////////////////////////////////////////////////////////////
            ////////////--------------------CONSTRACTORS && DESTRACTOS--------------------////////////
            //////////////////////////////////////////////////////////////////////////////////////////
            my_random_iterator(): _ptr(nullptr) {};
            my_random_iterator(my_random_iterator const &to_copy) { _ptr = to_copy._ptr; };
            my_random_iterator(T *to_copy)
            {
                if (this != &rhs)
                    this->_ptr = to_copy;
            };
            ~my_random_iterator() {};
            //////////////////////////////////////////////////////////////////////////
            ////////////--------------------ASSIGNMENT--------------------////////////
            //////////////////////////////////////////////////////////////////////////
            my_random_iterator& operator=(my_random_iterator const & rhs)
            {
                if (this != &rhs)
                    this->_ptr = rhs._ptr;
                return (*this);
            };
            //////////////////////////////////////////////////////////////////////////
            ////////////--------------------COMPARAISON--------------------///////////
            //////////////////////////////////////////////////////////////////////////
            bool operator==(my_random_iterator const& a)
            {
                if (this->_ptr == a._ptr)
                    return true;
                else
                    return false;
            }
            bool operator!=(my_random_iterator const& a)
            {
                if (this->_ptr == a._ptr)
                    return false;
                else
                    return true;
            }
            //////////////////////////////////////////////////////////////////////////
            ////////////---------Can be dereferenced as an rvalue----------///////////
            //////////////////////////////////////////////////////////////////////////	
            T& operator*() const {return *_ptr;};
            T* operator->() const {return _ptr;};
            //////////////////////////////////////////////////////////////////////////
            ////////////---For mutable iterators (non-constant iterators)-----////////
            //////////////////////////////////////////////////////////////////////////
            //*a = t TO DO
            //////////////////////////////////////////////////////////////////////////
            ////////////---Can be incremented (if in a dereferenceable state)---//////
            //////////////////////////////////////////////////////////////////////////
            my_random_iterator& operator++() {++_ptr; return *this;};
            my_random_iterator operator++(int) const {my_random_iterator tmp(*this); ++_ptr; return tmp;};
            //*a++ TO DO
            ////////////////////////////////////////////////////////////////////////////////////////////
            ////////////---Can be decremented (if a dereferenceable iterator value precedes it)---//////
            ////////////////////////////////////////////////////////////////////////////////////////////
            my_random_iterator& operator--() {--_ptr; return *this;};
            my_random_iterator operator--(int) const {my_random_iterator tmp(*this); --_ptr; return tmp;};
            //*a-- TO DO
            ///////////////////////////////////////////////////////////////
            ////////////---Supports the arithmetic operators---////////////
            ///////////////////////////////////////////////////////////////
            difference_type operator-(const my_random_iterator& rhs) const {return (_ptr - rhs.ptr);};
            my_random_iterator operator+(difference_type rhs) const {return my_random_iterator(_ptr+rhs);};
            my_random_iterator operator-(difference_type rhs) const {return my_random_iterator(_ptr-rhs);};
            friend my_random_iterator operator+(difference_type lhs, const my_random_iterator& rhs) {return my_random_iterator(lhs+rhs._ptr);};
            friend my_random_iterator operator-(difference_type lhs, const my_random_iterator& rhs) {return my_random_iterator(lhs-rhs._ptr);};
            ////////////////////////////////////////////////////////////////////////////////////////
            ///////---Can be compared with inequality relational operators (<, >, <= and >=)---/////
            ////////////////////////////////////////////////////////////////////////////////////////
            bool operator>(const my_random_iterator& rhs) const {return _ptr > rhs._ptr;}
            bool operator<(const my_random_iterator& rhs) const {return _ptr < rhs._ptr;}
            bool operator>=(const my_random_iterator& rhs) const {return _ptr >= rhs._ptr;}
            bool operator<=(const my_random_iterator& rhs) const {return _ptr <= rhs._ptr;}
            ///////////////////////////////////////////////////////////////////
            ///////---Supports compound assignment operations += and -=---/////
            ///////////////////////////////////////////////////////////////////
            my_random_iterator& operator+=(difference_type rhs) {_ptr += rhs; return *this;}
            my_random_iterator& operator-=(difference_type rhs) {_ptr -= rhs; return *this;}
            ///////////////////////////////////////////////////////////////////
            ///////-----Supports the offset dereference operator ([])-----/////
            ///////////////////////////////////////////////////////////////////
            T& operator[](difference_type rhs) const {return (_ptr[rhs]);}
    };
}


#endif
