#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../utilities/utilities.hpp"
#include <vector>
# include <iostream>
# include <iterator>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
# include "vector.hpp"

int main()
{
    std::vector<int> std_v;
    ft::vector<int> my_v;

    std::cout << "==========================values==========================" << std::endl;
    for (int i = 0; i < 10; i++)
        std_v.push_back(i);
    for (int i = 0; i < 10; i++)
        my_v.push_back(i);
    for (int i = 0; i < 10; i++)
        std::cout << "value " << i << " |std : " << std_v[i] << "|ft : " << my_v[i] << std::endl;
    std::cout << "==========================size==========================" << std::endl;
    std::cout << "size :  " << "|std :" << std_v.size() << "|ft : " << my_v.size() << std::endl;
    std::cout << "==========================capacity==========================" << std::endl;
    std::cout << "capacity :  " << "|std :" << std_v.capacity() << "|ft : " << my_v.capacity() << std::endl;
    std::cout << "==========================resize==========================" << std::endl;
    std_v.resize(20, 66);
    my_v.resize(20, 66);
    std::cout << "size :  " << "|std :" << std_v.size() << "|ft : " << my_v.size() << std::endl;
    std::cout << "==========================values after resize==========================" << std::endl;
    for (int i = 0; i < 20; i++)
        std::cout << "value " << i << " |std : " << std_v[i] << "|ft : " << my_v[i] << std::endl;
    std::cout << "==========================reserve==========================" << std::endl;
    std_v.reserve(25);
    my_v.reserve(25);
    std::cout << "capacity :  " << "|std :" << std_v.capacity() << "|ft : " << my_v.capacity() << std::endl;
    std::cout << "==========================values after reserve==========================" << std::endl;
    for (int i = 0; i < 25; i++)
        std::cout << "value " << i << " |std : " << std_v[i] << "|ft : " << my_v[i] << std::endl;
    std::cout << "==========================front==========================" << std::endl;
    std::cout << "front :  " << "|std :" << std_v.front() << "|ft : " << my_v.front() << std::endl;
    std::cout << "==========================back==========================" << std::endl;
    std::cout << "back :  " << "|std :" << std_v.back() << "|ft : " << my_v.back() << std::endl;
    std::cout << "==========================at==========================" << std::endl;
    std::cout << "at :  " << "|std :" << std_v.at(5) << "|ft : " << my_v.at(5) << std::endl;
    std::cout << "==========================pop_back==========================" << std::endl;
    std_v.pop_back();
    my_v.pop_back();
    std::cout << "size :  " << "|std :" << std_v.size() << "|ft : " << my_v.size() << std::endl;
    std::cout << "==========================values after pop_back==========================" << std::endl;
    for (int i = 0; i < 19; i++)
        std::cout << "value " << i << " |std : " << std_v[i] << "|ft : " << my_v[i] << std::endl;
    std::cout << "==========================clear==========================" << std::endl;
    std_v.clear();
    my_v.clear();
    std::cout << "size :  " << "|std :" << std_v.size() << "|ft : " << my_v.size() << std::endl;
    std::cout << "==========================equal_operator==========================" << std::endl;
    ft::vector<int> my_v2;
    ft::vector<int> my_v1;
    my_v2.push_back(1);
    my_v1.push_back(1);
    my_v2.push_back(2);
    my_v1.push_back(2);
    if (my_v1 == my_v2)
        std::cout << "equal" << std::endl;
    else
        std::cout << "not equal" << std::endl;
    std::cout << "==========================iterator==========================" << std::endl;
    ft::vector<int>::iterator it = my_v1.begin();
    ft::vector<int>::const_iterator itt = my_v1.begin();

    if (*it == *itt)
        std::cout << "equal" << std::endl;
    else
        std::cout << "not equal" << std::endl;
    std::cout << "==========================swap==========================" << std::endl;
    ft::vector<int> my_v3;
    ft::vector<int> my_v4;
    my_v3.push_back(1);
    my_v4.push_back(2);
    my_v3.swap(my_v4);
    for (int i = 0; i < 1; i++)
        std::cout << "value " << i << " |my_v3 : " << my_v3[i] << "|my_v4 : " << my_v4[i] << std::endl;
}