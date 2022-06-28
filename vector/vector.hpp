#ifndef VECTOR_HPP
#define VECTOR_HPP


# include <limits>
# include <iterator>
# include <string>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <memory>

#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../utilities/utilities.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            //The first template parameter (T)
            typedef T													value_type;
            //The second template parameter (Alloc)	
            typedef Alloc												allocator_type;
            typedef typename allocator_type::reference					reference;
            typedef typename allocator_type::const_reference			const_reference;
            typedef typename allocator_type::pointer					pointer;
            typedef typename allocator_type::const_pointer				const_pointer;
            typedef ft::my_random_iterator<value_type>					iterator;
            typedef ft::my_random_iterator<const value_type>			const_iterator;
            typedef ft::my_reverse_iterator<iterator>					reverse_iterator;
            typedef ft::my_reverse_iterator<const_iterator>				const_reverse_iterator;
            typedef typename iterator_traits<iterator>::difference_type	difference_type;
            typedef typename allocator_type::size_type					size_type;

        private:
			allocator_type	_alloc;
			size_type		_size,_capacity;
			pointer			_first,_last;

        public:
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////--------------------CONSTRACTORS && DESTRACTOS--------------------////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			explicit vector (const allocator_type& alloc = allocator_type()):
				_alloc(alloc), _first(nullptr), _last(nullptr), _size(0), _capacity(0){};

			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()):
				_alloc(alloc), _first(nullptr), _last(nullptr), _size(0), _capacity(0)
				{
					if (n > alloc.max_size())
						throw std::length_error("vector");
					_size = n;
					_capacity = n;
					if(this->_size > n)
					{
						this->_first = this->_alloc.allocate(n);
						this->_last = this->_first + n;
						for (size_t i = 0; i < this->_size; i++)
							this->_alloc.construct((this->_first + i), val);
					}
				};

			template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()
				,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())://to_check
				_alloc(alloc), _first(nullptr), _last(nullptr), _size(0), _capacity(0)
				{
					this->_capacity = this->_size = last - first;
					this->_first = this->_alloc.allocate(this->_size);
					this->_last = this->_first + this->_size;
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.construct((this->_first + i), *(first + i));
				};

			vector (const vector& x):
			 _first(nullptr), _last(nullptr), _size(0), _capacity(0) { *this = x; };
		
            ~vector()
			{
				this->clear();
				_alloc.deallocate(_first, _capacity);
			}
		//////////////////////////////////////////////////////////////////////////////////////////
		///////////Assign content/////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			vector& operator= (const vector& x)
			{
				this->_capacity = x._capacity;
				this->_size = x._size;
				this->_first = x._first;
				this->_last = x->_last;
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.construct((this->_first + i), *(x._first + i));
			}
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Returns an iterator pointing to the first element in the vector.//////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			iterator begin(){ return(this->_first); };
			const_iterator begin() const{ return(this->_first); };
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////An iterator to the element past the end of the sequence.//////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			iterator end(){ return(this->_last); };
			const_iterator end() const{ return(this->_last); };
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////A reverse iterator to the reverse beginning of the sequence container.////////
		//////////////////////////////////////////////////////////////////////////////////////////
			reverse_iterator rbegin() { return(reverse_iterator(this->_last));};
			const_reverse_iterator rbegin() const { return(reverse_iterator(this->_last));};
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////A reverse iterator to the reverse end of the sequence container.//////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			reverse_iterator rend() { return(reverse_iterator(this->_first));};
			const_reverse_iterator rend() const { return(reverse_iterator(this->_first));};
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Returns the number of elements in the vector./////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			size_type size() const { return(this->_size);};
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Returns the maximum number of elements that the vector can hold.//////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			size_type max_size() const { return(_alloc.max_size());};
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Resizes the container so that it contains n elements./////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			void resize (size_type n, value_type val = value_type())//to check
			{
				if (n < _size)
				{
					for (pointer it = _first + n; it < _last; it++)
						_alloc.destroy(it);
					_last = _first + n;
					_size = n;
				}
				else if (n > _size)
				{
					pointer first, last;
					if (n > max_size())
						throw std::length_error("vector");
					if (n > _capacity)
					{
						if (n > _capacity * 2)
							_capacity = n;
						else
							_capacity *= 2;
					}
					first = _alloc.allocate(_capacity);
					last = first + n;
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(first + i, *(_first + i));
					for (size_type i = _size; i < n; i++)
						_alloc.construct(first + i, val);
					for (pointer it = _first; it < _last; it++)
						_alloc.destroy(it);
					_first = first;
					_last = last;
					_size = n;
				}
			}
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Return size of allocated storage capacity.////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			size_type capacity() const {return (this->_capacity);};
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Test whether vector is empty./////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			bool empty() const { return (this->_size == 0);};
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Request a change in capacity//////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			void reserve (size_type n)//to_check
			{
				if (n > max_size())
						throw std::length_error("vector");
				if (n > this->_capacity)
				{
					pointer begin, end;
					begin = _alloc.allocate(n);
					end = begin + _size;
					for (int i = 0; i < _size; i++)
						_alloc.construct((begin + i), *(_first + i));
					for (pointer it = _first; it < _last; it++)
						_alloc.destroy(it);
					_alloc.deallocate(_first, _capacity);
					_first = begin;
					_last = end;
					_capacity = n;
				}
			};
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Returns a reference to the element at position n in the vector container./////
		//////////////////////////////////////////////////////////////////////////////////////////
			reference operator[] (size_type n) { return(*(this->_first + n)); };
			const_reference operator[] (size_type n) const { return(*(this->_first + n)); };
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Returns a reference to the element at position n in the vector.///////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			reference at (size_type n)
			{ 
				if (n >= this->size())
					throw (std::out_of_range("vector"));
				return(*(this->_first + n));
			};
			const_reference at (size_type n) const
			{ 
				if (n >= this->size())
					throw (std::out_of_range("vector"));
				return(*(this->_first + n));
			};
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Returns a reference to the element at position 0 in the vector.///////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			reference front() { return(*(this->_first)); };
			const_reference front() const { return(*(this->_first)); };
		//////////////////////////////////////////////////////////////////////////////////////////
		////////////Returns a reference to the element at position 0 in the vector.///////////////
		//////////////////////////////////////////////////////////////////////////////////////////
			reference back() { return(*(this->_last - 1)); };
			const_reference back() const { return(*(this->_last - 1)); };

		/////////////////////////////////////////////////////////////////////////////////////////
		////////////Assign vector content////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				size_t n;
				n = last - first;
				if (_capacity < n)
				{
					this->clear();
					_alloc.deallocate(_first, _capacity);
					_first = _alloc.allocate(n);
					_last = _first + n;
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_first + i, *(&(*first) + i));
					_size = _capacity = n;
				}
				else
				{
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(_first + i);
					_size = n;
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(_first + i, *(&(*first) + i));
				}
			}

			void assign (size_type n, const value_type& val)
			{
				if (_capacity < n)
				{
					this->clear();
					_alloc.deallocate(_first, _capacity);
					_first = _alloc.allocate(n);
					_last = _first + n;
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_first + i, val);
					_size = _capacity = n;
				}
				else
				{
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(_first + i);
					_size = n;
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(_first + i, val);
				}
			}
		/////////////////////////////////////////////////////////////////////////////////////////
		////////////Add element at the end///////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////
			void push_back (const value_type& val)
			{
				if (this->size() == 0)
					reserve(1);
				else if (this->size() == this->capacity())
					reserve(this->size() * 2);
				_alloc.construct(_last, val);
				_size++;
				_last++;
			}
		/////////////////////////////////////////////////////////////////////////////////////////
		////////////remove element at the end/////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////
			void pop_back (const value_type& val)
			{
				if (this->size() != 0)
				{
					_alloc.destroy(_last);
					_size--;
					_last--;
				}
			}
		/////////////////////////////////////////////////////////////////////////////////////////
		////////////Insert elements//////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////
			iterator insert (iterator position, const value_type& val)
			{
				size_t dist_from_last = _last - &(*position);
				if (this->_capacity == 0)
				{
					this->_first = this->_alloc.allocate(1);
					this->_last = this->_first + 1;
					this->_alloc.construct(this->_first , val);
					this->_size = this->_capacity = 1;
					return(this->_first);
				}
				if (this->_size == this->_capacity)
					reserve(this->_capacity * 2);
				size_t i;
				for (i = 0; i < dist_from_last; i++)
					this->_alloc.costruct(_last - i, *(_last - i - 1));
				this->_alloc.costruct(_last - i, val);
				_last++;
				_size++;
				return(_first + dist_from_last);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				size_t dist_from_last = _last - &(*position);
				if (this->_capacity == 0)
				{
					this->_first = this->_alloc.allocate(n);
					this->_last = this->_first + n;
					for (size_t i = 0; i < n; i++)
						this->_alloc.construct((this->_first + i) , val);
					this->_size = this->_capacity = n;
					return;
				}
				if (_capacity < _size + n)
				{
					if (_capacity * 2 < _size + n)
						reserve (_size + n);
					else
						reserve (_capacity * 2);
				}
				_last += n;
				_size += n;
				for (size_type i = 0; i < dist_from_last; i++)
					_alloc.construct(_last - i - 1, *(_last - n - i - 1));
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_last - dist_from_last - i - 1, val);//dist_from_last -> n
			}

			template <class InputIterator>
		    void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())//TO DO
			{
				size_type pos = _last - &(*position);
				size_type n = std::distance(first, last);
				if (_size == 0)
				{
					reserve(n);
					for (size_type i = 0; i < n; i++, first++)
						_alloc.construct(_first + i , *(&(*first)));
					_size += n;
					return;
				}
				if (_capacity < _size + n)
				{
					if (_capacity * 2 < _size + n)
						reserve (_size + n);
					else
						reserve (_capacity * 2);
				}
				_last += n;
				_size += n;
				for (size_type i = 0; i < pos; i++)
					_alloc.construct(_last - i - 1, *(_last - n - i - 1));
				for (size_type i = 0; i < n; i++, first++)
					_alloc.construct(_last - pos - i - 1, (*first));
			}

		/////////////////////////////////////////////////////////////////////////////////////////
		////////////Erase elements//////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////
			iterator erase (iterator position)
			{
				pointer here = &(*position);
				if(position + 1 != this->_last)
				{
					this->_alloc.destroy(here);
					for (size_t i = 0; i < this->_last - here - 1; i++)
					{
						this->_alloc.construct(here + i, *(here + i + 1));
					}		
				}
				pop_back();
				return(itrator(here));
			}
			
			iterator erase (iterator first, iterator last)
			{
				pointer pos_first= &(*first);
				pointer pos_last= &(*last);
				size_type distance = pos_last - pos_first;
				// size_type dist = _last - pos_last;
				for (pointer i = pos_first; i < pos_last; i++)
					this->_alloc.destroy(i);
				for (size_t i = 0; i < _last - pos_last; i++)
					this->_alloc.construct((pos_first + i), *(pos_last + i));
				// for (size_t i = 0; i < _end - plast; i++)
				// 	_alloc.destroy(_first + i);
				for (size_t i = 0; i < distance; i++)//to check
					pop_back();
				return(iterator(pos_first));
			}

		/////////////////////////////////////////////////////////////////////////////////////////
		////////////Exchanges the content of the container by the content of x///////////////////
		/////////////////////////////////////////////////////////////////////////////////////////
			void swap (vector& x)
			{
				std::swap(x._first, this->_first);
				std::swap(x._last, this->_last);
				std::swap(x._size, this->_size);
				std::swap(x._capacity, this->_capacity);
				std::swap(x._alloc, this->_alloc);
			}


		/////////////////////////////////////////////////////////////////////////////////////////
		////////////------------------Clear content---------------------/////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////
			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_first + i);
				_size = 0;
			}

		/////////////////////////////////////////////////////////////////////////////////////////
		////////////Returns a copy of the allocator object associated with the vector.///////////
		/////////////////////////////////////////////////////////////////////////////////////////
			allocator_type get_allocator() const {allocator_type allocat(_alloc); return (allocat); }
    };

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}
	
template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(rhs < lhs));
}
template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
		return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return !(rhs < lhs);
}

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}
}
#endif