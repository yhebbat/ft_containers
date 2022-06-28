#include <iostream>     // std::cout
#include <iterator>     // std::iterator, std::input_iterator_tag

#include "iterators/bidirectional_iterator.hpp"
#include "iterators/random_access_iterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include <iostream>
#include <iterator>
#include <vector>

// class MyIterator : public std::iterator<std::input_iterator_tag, int>
// {
// 	int* p;
// public:
// 	MyIterator(int* x) :p(x) {}
// 	MyIterator(const MyIterator& mit) : p(mit.p) {}
// 	MyIterator& operator++() {++p;return *this;}
// 	MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
// 	bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
// 	bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
// 	int& operator*() {return *p;}
// };

int main () {
  int numbers[]={10,20,30,40,50};
  // ft::my_random_iterator<int> numbers(num);
  ft::my_random_iterator<int> from(numbers);
  ft::my_random_iterator<int> until(numbers + 5);
  for (ft::my_random_iterator<int> it=from; it!=until; it++)
    std::cout << *it << ' ';
  std::cout << '\n';

  return 0;
}

// int main()
// {
//     int a[]={0, 1, 2, 3};
//     //             ↑  └───── x, y
//     //             └──────── z
 
//     ft::my_reverse_iterator<int*>
//         x= (&a + 4) ;
//         // y= {(&a + 4)},
//         // z= {(&a + 3)};
 
//     std::cout
//         << std::boolalpha
//         << "*x == " << *x << '\n' // 3
//         << "*y == " << *y << '\n' // 3
//         << "*z == " << *z << '\n' // 2
//         << "x == y ? " << (x == y) << '\n' // true
//         << "x != y ? " << (x != y) << '\n' // false
//         << "x <  y ? " << (x <  y) << '\n' // false
//         << "x <= y ? " << (x <= y) << '\n' // true
//         << "x == z ? " << (x == z) << '\n' // false
//         << "x != z ? " << (x != z) << '\n' // true
//         << "x <  z ? " << (x <  z) << '\n' // true!
//         << "x <= z ? " << (x <= z) << '\n' // true
//         // << "x <=> y == 0 ? " << (x <=> y == 0) << '\n' // true
//         // << "x <=> y <  0 ? " << (x <=> y <  0) << '\n' // false
//         // << "x <=> y >  0 ? " << (x <=> y >  0) << '\n' // false
//         // << "x <=> z == 0 ? " << (x <=> z == 0) << '\n' // false
//         // << "x <=> z <  0 ? " << (x <=> z <  0) << '\n' // true
//         // << "x <=> z >  0 ? " << (x <=> z >  0) << '\n' // false
//         ;
// }