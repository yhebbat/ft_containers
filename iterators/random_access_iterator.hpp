#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
    template <typename T>
    class my_random_iterator
    {
        private:
            T   *_ptr;
        public:
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type	difference_type;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type		value_type;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer			pointer;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference			reference;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;

            //////////////////////////////////////////////////////////////////////////////////////////
            ////////////--------------------CONSTRACTORS && DESTRACTOS--------------------////////////
            //////////////////////////////////////////////////////////////////////////////////////////
            my_random_iterator(): _ptr(nullptr) {};
            my_random_iterator(const my_random_iterator &to_copy) { this->_ptr = to_copy._ptr; };
            my_random_iterator(T *to_copy) { this->_ptr = to_copy;};
            ~my_random_iterator() {};
            //////////////////////////////////////////////////////////////////////////
            ////////////--------------------ASSIGNMENT--------------------////////////
            //////////////////////////////////////////////////////////////////////////
            my_random_iterator& operator=(my_random_iterator const & rhs)
            {
                if (this != &rhs)
                    this->_ptr = rhs.base();
                return (*this);
            };
            //////////////////////////////////////////////////////////////////////////
            ////////////--------------------COMPARAISON--------------------///////////
            //////////////////////////////////////////////////////////////////////////
            bool operator==(my_random_iterator const& a) const
            {
                if (this->_ptr == a.base())
                    return true;
                else
                    return false;
            }
            bool operator!=(my_random_iterator const& a) const 
            {
                if (this->_ptr == a.base())
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
            my_random_iterator operator++(int) {my_random_iterator tmp(*this); ++_ptr; return tmp;};
            ////////////////////////////////////////////////////////////////////////////////////////////
            ////////////---Can be decremented (if a dereferenceable iterator value precedes it)---//////
            ////////////////////////////////////////////////////////////////////////////////////////////
            my_random_iterator& operator--() {--_ptr; return *this;};
            my_random_iterator operator--(int) {my_random_iterator tmp(*this); --_ptr; return tmp;};
            ///////////////////////////////////////////////////////////////
            ////////////---Supports the arithmetic operators---////////////
            ///////////////////////////////////////////////////////////////
            difference_type operator-(const my_random_iterator& rhs) const {return (_ptr - rhs.base());};
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

            //////// BASE /////////
            pointer base() const {return _ptr;};

            operator my_random_iterator<const T>() const {
                return my_random_iterator<const T>(_ptr);
            }
    };
}

#endif
