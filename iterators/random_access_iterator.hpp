#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
    template <typename T>
    class random_access_iterator
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
            random_access_iterator(): _ptr(nullptr) {};
            random_access_iterator(const random_access_iterator &to_copy) { this->_ptr = to_copy._ptr; };
            random_access_iterator(T *to_copy) { this->_ptr = to_copy;};
            ~random_access_iterator() {};
            //////////////////////////////////////////////////////////////////////////
            ////////////--------------------ASSIGNMENT--------------------////////////
            //////////////////////////////////////////////////////////////////////////
            random_access_iterator& operator=(random_access_iterator const & rhs)
            {
                if (this != &rhs)
                    this->_ptr = rhs.base();
                return (*this);
            };
            //////////////////////////////////////////////////////////////////////////
            ////////////--------------------COMPARAISON--------------------///////////
            //////////////////////////////////////////////////////////////////////////
            bool operator==(random_access_iterator const& a) const
            {
                if (this->_ptr == a.base())
                    return true;
                else
                    return false;
            }
            bool operator!=(random_access_iterator const& a) const 
            {
                if (this->_ptr == a.base())
                    return false;
                else
                    return true;
            }
            //////////////////////////////////////////////////////////////////////////
            ////////////---------Can be dereferenced as an rvalue----------///////////
            //////////////////////////////////////////////////////////////////////////	
            T& operator*() const {return (*_ptr);};
            T* operator->() const {return &(operator*());};
            //////////////////////////////////////////////////////////////////////////
            ////////////---For mutable iterators (non-constant iterators)-----////////
            //////////////////////////////////////////////////////////////////////////
            //*a = t TO DO
            //////////////////////////////////////////////////////////////////////////
            ////////////---Can be incremented (if in a dereferenceable state)---//////
            //////////////////////////////////////////////////////////////////////////
            random_access_iterator& operator++() {++_ptr; return *this;};
            random_access_iterator operator++(int) {random_access_iterator tmp(*this); ++_ptr; return tmp;};
            ////////////////////////////////////////////////////////////////////////////////////////////
            ////////////---Can be decremented (if a dereferenceable iterator value precedes it)---//////
            ////////////////////////////////////////////////////////////////////////////////////////////
            random_access_iterator& operator--() {--_ptr; return *this;};
            random_access_iterator operator--(int) {random_access_iterator tmp(*this); --_ptr; return tmp;};
            ///////////////////////////////////////////////////////////////
            ////////////---Supports the arithmetic operators---////////////
            ///////////////////////////////////////////////////////////////
            difference_type operator-(const random_access_iterator& rhs) const {return (_ptr - rhs.base());};
            random_access_iterator operator+(difference_type rhs) const {return random_access_iterator(_ptr+rhs);};
            random_access_iterator operator-(difference_type rhs) const {return random_access_iterator(_ptr-rhs);};
            friend random_access_iterator operator+(difference_type lhs, const random_access_iterator& rhs) {return random_access_iterator(lhs+rhs._ptr);};
            friend random_access_iterator operator-(difference_type lhs, const random_access_iterator& rhs) {return random_access_iterator(lhs-rhs._ptr);};
            ////////////////////////////////////////////////////////////////////////////////////////
            ///////---Can be compared with inequality relational operators (<, >, <= and >=)---/////
            ////////////////////////////////////////////////////////////////////////////////////////
            bool operator>(const random_access_iterator& rhs) const {return _ptr > rhs._ptr;}
            bool operator<(const random_access_iterator& rhs) const {return _ptr < rhs._ptr;}
            bool operator>=(const random_access_iterator& rhs) const {return _ptr >= rhs._ptr;}
            bool operator<=(const random_access_iterator& rhs) const {return _ptr <= rhs._ptr;}
            ///////////////////////////////////////////////////////////////////
            ///////---Supports compound assignment operations += and -=---/////
            ///////////////////////////////////////////////////////////////////
            random_access_iterator& operator+=(difference_type rhs) {_ptr += rhs; return *this;}
            random_access_iterator& operator-=(difference_type rhs) {_ptr -= rhs; return *this;}
            ///////////////////////////////////////////////////////////////////
            ///////-----Supports the offset dereference operator ([])-----/////
            ///////////////////////////////////////////////////////////////////
            T& operator[](difference_type rhs) const {return (_ptr[rhs]);}

            //////// BASE /////////
            pointer base() const {return _ptr;};

            operator random_access_iterator<const T>() const {
                return random_access_iterator<const T>(_ptr);
            }
    };
}

#endif
