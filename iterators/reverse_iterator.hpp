#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{
    template <class iterator>
    class my_reverse_iterator
    {
    public:
        typedef iterator                                                    iterator_type;
        typedef	typename iterator_traits<iterator>::difference_type    difference_type;
        typedef typename iterator_traits<iterator>::value_type         value_type;
        typedef typename iterator_traits<iterator>::pointer            pointer;
        typedef typename iterator_traits<iterator>::reference          reference;
        typedef	typename iterator_traits<iterator>::iterator_category	iterator_category;
    private:
        iterator_type   _it;
    public:
        // typedef iterator                                                    iterator_type;
        // typedef	typename iterator_traits<iterator>::difference_type    difference_type;
        // typedef typename iterator_traits<iterator>::value_type         value_type;
        // typedef typename iterator_traits<iterator>::pointer            pointer;
        // typedef typename iterator_traits<iterator>::reference          reference;
        // typedef	typename iterator_traits<iterator>::iterator_category	iterator_category;
        my_reverse_iterator():_it() {};
        my_reverse_iterator (iterator_type  it): _it(it){};
        // my_reverse_iterator (const iterator_type  it): _it(it){};
        my_reverse_iterator (const my_reverse_iterator &x):_it(x.base()){};
        template <typename Iter> my_reverse_iterator (const my_reverse_iterator< Iter > &x) {*this = x;};
        
        iterator_type base() const{return(_it);};

        template <class _iterator>
  	   	my_reverse_iterator& operator= (const my_reverse_iterator<_iterator>& rev_it)
        {
            _it = rev_it.base();
            return (*this);	  
		}


        reference 	operator*() const{ iterator_type tmp = _it; return *(--tmp);};
        pointer 	operator->() const{return &(operator*());};
        my_reverse_iterator & 	operator++ (){--(_it); return(*this);};
        my_reverse_iterator 	operator++ (int){my_reverse_iterator __tmp = *this; --(_it); return __tmp;};
        my_reverse_iterator & 	operator--(){++(_it); return(*this);};
        my_reverse_iterator 	operator-- (int){my_reverse_iterator __tmp = *this; ++(_it); return __tmp;};
        my_reverse_iterator 	operator+(difference_type n) const{ return (my_reverse_iterator(_it - n));};
        my_reverse_iterator &   operator+=(difference_type n) {_it -= n; return(*this);};
        my_reverse_iterator 	operator-(difference_type n) const {return (my_reverse_iterator(_it + n));};
        my_reverse_iterator &   operator-=(difference_type n) {_it += n; return(*this);};
        reference 	operator[](difference_type n) const {return (this->base()[-n - 1]);};//to check
        ~my_reverse_iterator() {};

    };
    template<typename _iterator>
    bool operator==(const my_reverse_iterator<_iterator>& x, const my_reverse_iterator<_iterator>& y)
    { return x.base() == y.base(); };

    template<typename _iterator>
    bool operator!=(const my_reverse_iterator<_iterator>& x, const my_reverse_iterator<_iterator>& y)
    { return !(x == y); };

    template<typename _iterator>
    bool operator>(const my_reverse_iterator<_iterator>& x, const my_reverse_iterator<_iterator>& y)
    { return x.base() < y.base(); };

    template<typename _iterator>
    bool operator<(const my_reverse_iterator<_iterator>& x, const my_reverse_iterator<_iterator>& y)
    { return x.base() > y.base(); };

    template<typename _iterator>
    bool operator>=(const my_reverse_iterator<_iterator>& x, const my_reverse_iterator<_iterator>& y)
    { return x.base() <= y.base(); };

    template<typename _iterator>
    bool operator<=(const my_reverse_iterator<_iterator>& x, const my_reverse_iterator<_iterator>& y)
    { return x.base() >= y.base(); };

    template<typename _iterator>
    typename my_reverse_iterator<_iterator>::difference_type operator-(
        const my_reverse_iterator<_iterator>& lhs,
        const my_reverse_iterator<_iterator>& rhs)
    { return rhs.base() - lhs.base(); };

    template<typename _iterator>
    typename my_reverse_iterator<_iterator>::difference_type operator+(
        typename my_reverse_iterator<_iterator>::difference_type n,
        const my_reverse_iterator<_iterator>& rev_it)
    { return (rev_it + n); };
}
//  	reverse_iterator () done
//  	reverse_iterator (iterator_type x) done
//  	reverse_iterator (const reverse_iterator &x) done 
// template<typename Iter>  	reverse_iterator (const reverse_iterator< Iter > &x) done
// iterator_type 	base () const done
// reference 	operator * () const done
// pointer 	operator-> () const done
// reverse_iterator & 	operator++ () done
// reverse_iterator 	operator++ (int) done
// reverse_iterator & 	operator-- () done
// reverse_iterator 	operator-- (int) done
// reverse_iterator 	operator+ (difference_type n) const done
// reverse_iterator & 	operator+= (difference_type n) done
// reverse_iterator 	operator- (difference_type n) const done
// reverse_iterator & 	operator-= (difference_type n) done
// reference 	operator[] (difference_type n) const done
#endif