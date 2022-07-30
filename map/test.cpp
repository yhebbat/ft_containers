#include "./map.hpp"       // your Map path.
#include "../vector/vector.hpp" // your Vector path.
#include "../utilities/utilities.hpp"
#include <map>
#include <iostream>

int main()
{
    ft::map< int, int> m;
    
    m.insert(ft::make_pair(1, 1));
    m.insert(ft::make_pair(2, 2));
    m.insert(ft::make_pair(3, 3));
    m.insert(ft::make_pair(4, 4));

    ft::map<int, std::string> ft_m1;

    for (size_t i = 0; i < 10; i++)
    {
        ft_m1.insert(ft::make_pair(i, "string2"));
    }
    ft::map<int, std::string> const ft_m2(ft_m1.begin(), ft_m1.end());

    std::string res, ft_res, c_res, c_ft_res;

    for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;

    std::cout << ft_res << std::endl;
    // for (ft::map<int, std::string>::const_iterator rit = ft_m2.begin(); rit != ft_m2.end(); ++rit) // fill c_ft_res from const ft_m1
    //         c_ft_res += rit->second;

    // std::cout << "hey" << tmp->first<< std::endl;
    // m.Test();
    // m.erase(3);
    // for(; tmp != m.end(); tmp++)
    //    std::cout << tmp->first << std::endl;  
    //m.Test();
    //ft::map<int, char>::const_iterator c_it = my_it1, c_ob;
    //ft::pair<int, int> p;
    // p = ft::make_pair(1,2);
    // const ft::pair<int, int> k(p);

    // k = p;
    // std::cout << k.first << std::endl;
    // c_it = c_ob;

}