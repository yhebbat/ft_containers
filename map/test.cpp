#include "./map.hpp"       // your Map path.
#include "../vector/vector.hpp" // your Vector path.
#include "../utilities/utilities.hpp"
#include <map>
#include <iostream>

int main()
{
    ft::map<int, int> m;

    m.insert(ft::make_pair(1, 1));
    m.insert(ft::make_pair(2, 2));
    m.insert(ft::make_pair(3, 3));
    m.insert(ft::make_pair(4, 4));
    ft::map<int, int>::iterator tmp = m.begin();
    ft::map<int, int>::iterator my_it, my_it1;

    // std::cout << "hey" << tmp->first<< std::endl;
    // m.Test();
    for(; tmp != m.end(); tmp++)
       std::cout << tmp->first << std::endl;  
    m.Test();
    //ft::map<int, char>::const_iterator c_it = my_it1, c_ob;
    //ft::pair<int, int> p;
    // p = ft::make_pair(1,2);
    // const ft::pair<int, int> k(p);

    // k = p;
    // std::cout << k.first << std::endl;
    // c_it = c_ob;

}