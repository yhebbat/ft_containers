
#include <iostream>
#include "./utilities/utilities.hpp"
#include "./map/avl_tree.hpp"

int main()
{
	ft::avl_tree<ft::pair<int,int> > root;
	// ft::avl_tree<int> root;
	root.insert_(ft::make_pair(10,1));
	root.insert_(ft::make_pair(10,2));
	root.insert_(ft::make_pair(30,3));
	root.insert_(ft::make_pair(40,4));
	root.insert_(ft::make_pair(50,5));
	root.insert_(ft::make_pair(60,6));
	root.insert_(ft::make_pair(70,7));
	root.insert_(ft::make_pair(80,8));
	root.insert_(ft::make_pair(90,9));
	// if (root.search(100) != NULL)
	// 	std::cout << root.search(100)->data.second << std::endl;
	// std::cout << "heello" << std::endl;
	// root.exist(10);
	// find_parent(_root);
	// if (root.find_next(10) != NULL)
	// 	std::cout << root.find_next(10)->data.first << std::endl;
	// else
	// 	std::cout << "NULL" << std::endl;
	// std::cout << "next of 20 is :"<< root.find_next(10)->data.first;
	// if (root.exist(90))
	// 	std::cout << "search: "<< root.search(90)->data.first << std::endl;
	// else
	// 	std::cout << "not exist" << std::endl;
	// root.insert_(90);
	// root.insert_(-10);
	// root.insert_(-100);
	// root.insert_(-200);
	// std::cout << "size: " << root.size() << std::endl;
	// ft::avl_tree<int, int> root2;
	// root2 = root;
	// std::cout << "next of 10 is :"<< root.find_next(10)->data << std::endl;
	// if (root.find_prev(10) == NULL)
	// 	std::cout << "next of 10 is : NULL" << std::endl;
	// else
	// 	std::cout << "next of 10 is :"<< root.find_next(10)->data.first << " prev of 10 is :"<< root.find_prev(10)->data.first  << std::endl;;
	// std::cout << "next of 20 is :"<< root.find_next(20)->data.first << " prev of 20 is :"<< root.find_prev(20)->data.first  << std::endl;
	// std::cout << "next of 30 is :"<< root.find_next(30)->data.first << " prev of 30 is :"<< root.find_prev(30)->data.first  << std::endl;
	// std::cout << "next of 40 is :"<< root.find_next(40)->data.first << " prev of 40 is :"<< root.find_prev(40)->data.first  << std::endl;
	// std::cout << "next of 50 is :"<< root.find_next(50)->data.first << " prev of 50 is :"<< root.find_prev(50)->data.first  << std::endl;
	// std::cout << "next of 60 is :"<< root.find_next(60)->data.first << " prev of 60 is :"<< root.find_prev(60)->data.first  << std::endl;
	// std::cout << "next of 70 is :"<< root.find_next(70)->data.first << " prev of 70 is :"<< root.find_prev(70)->data.first  << std::endl;
	// std::cout << "next of 80 is :"<< root.find_next(80)->data.first << " prev of 80 is :"<< root.find_prev(80)->data.first  << std::endl;
	// if (root.find_next(90) == NULL)
	// 	std::cout << "next of 90 is : NULL" << std::endl;
	// else
	// 	std::cout << "next of 90 is :"<< root.find_next(90)->data.first << std::endl;
	// std::cout << "min value" << root.find_min()->data << std::endl;
	// std::cout << "max value" << root.find_max()->data << std::endl;
	root.print_tree();
	// if (root.exist(root._root, 13))
	// 	std::cout << "13 Found" << std::endl;
	// else
	// 	std::cout << "13 Not found" << std::endl;
	// root._root = root.delete_(root._root, 60);
	// root.delete_(60);
	// std::cout << "next of 50 is :"<< root.find_next(50)->data << "prev of 50 is :"<< root.find_prev(50)->data  << std::endl;
	// root._root = root.delete_(root._root, 13);
	// root._root = root.delete_(13);
	std::cout << "After deleting " << std::endl;
	root.delete_(10);
	// root.print_tree();
	// std::cout << "After deleting " << std::endl;
	root.delete_(20);
	root.delete_(30);
	root.delete_(40);
	root.delete_(50);
	root.delete_(60);
	root.delete_(70);
	root.delete_(80);
	root.delete_(90);
	root.print_tree();
	// root.delete_(1);
	// if (root.exist(root._root, 13))
	// 	std::cout << "13 Found" << std::endl;
	// else
	// 	std::cout << "13 Not found" << std::endl;
	// root.print_tree(root._root);
	// root.print_tree();
	// std::cout << "After deleting all" << std::endl;
	// root.clear();
	// root.print_tree(root._root);
	system("leaks a.out");
	// root.print_tree();

}