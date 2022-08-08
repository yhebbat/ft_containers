#include "./map.hpp"       // your Map path.
#include "../vector/vector.hpp" // your Vector path.
#include "../utilities/utilities.hpp"
#include <map>
#include <iostream>
#include <unistd.h>
#include <ctime>

int main()
{
    std::map<int, int> std_m;
    ft::map<int, int> ft_m;
    std::cout << "===========================insert_values====================" << std::endl;
    for (int i = 0; i < 10; i++)
        ft_m.insert(ft::make_pair(i, i));
    ft_m.insert(ft::pair<int, int>(10,33));
    
    for (int i = 0; i < 11; i++)
        std_m.insert(std::make_pair(i, i));
    for (int i = 0; i < 11; i++)
        std::cout << "value " << i << " |std : " << std_m[i] << "|ft : " << ft_m[i] << std::endl;
    std::cout << "===========================size====================" << std::endl;
    std::cout << "std : " << std_m.size() << "|ft : " << ft_m.size() << std::endl;
    std::cout << "===========================max_size====================" << std::endl;
    std::cout << "std : " << std_m.max_size() << "|ft : " << ft_m.max_size() << std::endl;
    std::cout << "===========================begin====================" << std::endl;
    ft::map<int, int>::iterator it = ft_m.begin();
    std::map<int, int>::iterator it2 = std_m.begin();
    std::cout << "std : " << it2->first << "|ft : " << it->first << std::endl;
    std::cout << "===========================rbegin====================" << std::endl;
    ft::map<int, int>::reverse_iterator r_it = ft_m.rbegin();
    std::map<int, int>::reverse_iterator r_it2 = std_m.rbegin();
    std::cout << "std : " << r_it2->first << "|ft : " << r_it->first << std::endl;
    std::cout << "===========================erase====================" << std::endl;
    ft_m.erase(2);
    std_m.erase(2);
    ft::map<int, int>::iterator itt = ft_m.begin();
    std::map<int, int>::iterator itt2 = std_m.begin();
    for (; itt != ft_m.end(); itt++)
        std::cout << "|ft : " << itt->first << std::endl;
    for (; itt2 != std_m.end(); itt2++)
        std::cout <<  "|||std : " << itt2->first << std::endl;
    std::cout << "===========================lower_bound====================" << std::endl;   
    ft::map<int, int>::iterator itt3 = ft_m.lower_bound(5);
    std::map<int, int>::iterator itt4 = std_m.lower_bound(5);
    std::cout << "std : " << itt4->first << "|ft : " << itt3->first << std::endl;
    std::cout << "===========================upper_bound====================" << std::endl;
    ft::map<int, int>::iterator itt5 = ft_m.upper_bound(5);
    std::map<int, int>::iterator itt6 = std_m.upper_bound(5);
    std::cout << "std : " << itt6->first << "|ft : " << itt5->first << std::endl;
    std::cout << "===========================equal_range====================" << std::endl;
    std::pair<std::map<int,int>::iterator,std::map<int,int>::iterator> ret;
    ret = std_m.equal_range(1);
    ft::pair<ft::map<int,int>::iterator,ft::map<int,int>::iterator> ret2;
    ret2 = ft_m.equal_range(1);
    std::cout << "std===> " << "lower bound : " << ret.first->first << "|upper bound : " << ret.second->first << std::endl;
    std::cout << "ft ===> " << "lower bound : " << ret2.first->first << "|upper bound : " << ret2.second->first << std::endl;
    std::cout << "===========================swap====================" << std::endl;
    ft::map<int, int> ft_m2;
    ft::map<int, int> ft_m3;
    ft_m2.insert(ft::make_pair(1, 1));
    ft_m3.insert(ft::make_pair(1, 2));
    std::cout << "before :" << "ft_m2 : " << ft_m2[1] << "|ft_m3 : " << ft_m3[1] << std::endl;
    ft_m2.swap(ft_m3);
    std::cout << "after :" << "ft_m2 : " << ft_m2[1] << "|ft_m3 : " << ft_m3[1] << std::endl;
    std::cout << "===========================count====================" << std::endl;
    std::cout << "std : " << std_m.count(1) << "|ft : " << ft_m.count(1) << std::endl;
    std::cout << "std : " << std_m.count(2) << "|ft : " << ft_m.count(2) << std::endl;
    std::cout << "===========================clear====================" << std::endl;
    ft_m.clear();
    std_m.clear();
    std::cout << "ft size : " << ft_m.size() << " |std size : " << std_m.size() << std::endl;
}