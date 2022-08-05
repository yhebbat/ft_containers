#include "./map.hpp"       // your Map path.
#include "../vector/vector.hpp" // your Vector path.
#include "../utilities/utilities.hpp"
#include <map>
#include <iostream>

int main()
{

    std::map<int, int> ft_m;
    ft::map<int, int> std_m;
    int i = 0;
    // for (int i = 3; i < 13; ++i)
        ft_m.insert(std::make_pair(i, i));
        std_m.insert(ft::make_pair(i, i));

        // ft_m.insert(ft::make_pair(i + 1, i));
    // for (int i = 3; i < 13; ++i)
    //     std_m.insert(ft::make_pair(i, i));

    // if (ft_m == std_m)
    //     std::cout << "blaan" << std::endl;
    // exit(0);
    // std::cout << "mine : "<< ft_m.upper_bound(300)->first << std::endl;
    // std::cout << "std : "<< std_m.upper_bound(300)->first << std::endl;
    // ft::map<int, int> m;
    std::map<int, int>::const_iterator it = ft_m.end();
    for (;it != ft_m.begin(); it--)
        std::cout << it->first << std::endl;
    // m.insert(ft::make_pair(1, 1));
    // m.insert(ft::make_pair(2, 2));
    // m.insert(ft::make_pair(3, 3));
    // m.insert(ft::make_pair(4, 4));

    // ft::map<int, std::string> my_m;
    // for (int i = 0; i < 1e6; ++i)
    //     my_m.insert(ft::make_pair(i, "fill constructor test"));
    // ft::map< int, int>::iterator tmp = m.begin();
    // ft::map<int, int>::iterator my_it, my_it1;
    // ft::map< int, int>::const_iterator tmp1(tmp);
    // std::cout << "hey" << tmp->first<< std::endl;
    // m.Test();
    
    //ft::pair<int, int> p;
    // p = ft::make_pair(1,2);
    // const ft::pair<int, int> k(p);

    // k = p;
    // std::cout << k.first << std::endl;
    // c_it = c_ob;

}