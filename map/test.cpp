#include "./map.hpp"       // your Map path.
#include "../vector/vector.hpp" // your Vector path.
#include "../utilities/utilities.hpp"
#include <map>
#include <iostream>
#include <unistd.h>
#include <ctime>

int main()
{
    // time_t ti = time(NULL);
    std::map<int, int> ft_m;
    ft::map<int, int> std_m;
    int i = 0;
    for (int i = 3; i < 13; ++i)
    {

        ft_m.insert(std::make_pair(i, i));
        std_m.insert(ft::make_pair(i, i));
    }

        // ft_m.insert(ft::make_pair(i + 1, i));
    for (int i = 3; i < 13; ++i)
        std_m.insert(ft::make_pair(i, i));

    // if (ft_m == std_m)
    //     std::cout << "blaan" << std::endl;
    // exit(0);
    std_m.insert(ft::make_pair(10, 10));
    std_m.insert(ft::make_pair(20, 20));
    std_m.insert(ft::make_pair(30, 30));
    std_m.insert(ft::make_pair(40, 40));
    std_m.insert(ft::make_pair(50, 50));
    std_m.insert(ft::make_pair(60, 60));
    // std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& pair = std_m.equal_range(10);
    // const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& pair = std_m.equal_range(10);
    std::cout << "mine : "<< std_m.upper_bound(3)->first << std::endl;
    std::cout << "std : "<< std_m.upper_bound(3)->first << std::endl;
    // std::cout << difftime(time(NULL),  ti) * 1000 <<std::endl;
    // ft::map<int, int> m;
    // ft::map<int, int>::const_iterator it = std_m.end();
    // for (;it != std_m.begin(); --it)
    //     std::cout << it->first << std::endl;
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