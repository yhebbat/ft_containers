ft_containers:
In C++ STL (Standard Template Library), 3 things are meaningful and important:

Containers: These are used to manage a collection of objects of a certain kind. Containers can be of two types: Sequence Containers (vector, deque, list) and Associative Containers (Set, Multiset, Map, Multimap).
Algorithms: These are used to process the elements of a collection. That is algorithms feed from containers and process those elements in a predefined way and may also push the results into the same/different container.
Iterator: These are used to step through the elements of collection of objects (aka containers).
The designer of STL chose a wonderful yet simple common approach - "The separation of data and operation".

The data is held and managed by the Container classes.
The operations over the containers are defined and managed by the configurable algorithms.
So, if Container classes and algorithms are completely different entities, there has to be a bridge between them, right? There has to be a dedicated tunnel between them, there has to be some kind of glue between them. Yes, you are right <=====> Iterators are those Bridge/Tunnel/Glue.

Someone might argue that STL concepts of Container/Algorithm/Iterator contradicts with the fundamental ideas of Object-Oriented Programming: The STL separates the Data and the Operations (Algorithm) over it <---> rather than combining them. The beauty and flexibility of this design is you can almost bind up every kind of container with every kind of algorithm (by kind of algorithm, I mean to say - Modifying/Non-modifying/Mutating/Sorting/Numeric etc.).

Containers in C++ STL (Standard Template Library) - GeeksforGeeks

What are Containers/Adapters? C++ 164319655236_P2C2-4

Vectors in C++ STL:
vector one of the sequence containers, meaning the data is reliably ordered. Vectors are as same dynamic arrays they use contiguous storage locations for their elements, which means you can access any element with an integer index in constant time.

vector - C++ Reference

vector (classe)

Vector in C++ STL - GeeksforGeeks

Allocator:
std::allocator()

Types of Iterators:
Iterators in C++ STL - GeeksforGeeks

- C++ Reference


Operators :
C++ Operator Overloading: Common Practice

Iterator_traits :
std::iterator is deprecated: Why, What It Was, and What to Use Instead - Fluent C++

std::iterator_traits

An Introduction to "Iterator Traits"

Reverse_iterator:
reverse_iterator - C++ Reference

Why isn't a reverse iterator a formal iterator category according to the C++17 standard?

Random_access_iterator
Random Access Iterators

random_access_iterator_tag - C++ Reference

Explicit constructors :
Constructors are functions with the same name as the class. They are used to create the instance of a class. They are provided default by the compiler. But still, the user can have his/her own constructor declared. We can have a constructor with a single parameter and use this kind of constructor for doing type conversion or implicit conversion.

#include <iostream>

class A
{
	int data;
	public:
		A(int a) : data(a){
		    cout<<"A::Constructor...\n";
		};
	friend void display(A obj);
};

void display(A obj){
    cout<<"Valud of data in obj :="<< obj.data<<endl;
}

int main(void)
{
	A a = 98;
  // A a1(99);
  // display(a1);
	display(1000);
	return (0);
}
A declaration like below in this example is called as an Implicit Conversion and calls A(int a) constructor to create an A object from the integer value

Implicit conversions

To avoid all such confusions that happen with Implicit Conversion and Constructor Conversion, we can use explicit keyword in constructor declaration. This forces the compiler not to do an implicit conversion and throws an error for this kind of code. And thus make sure the constructor is explicitly called with the right syntax. This keyword is used only for the constructors.

enable_if:
C++ Tutorial => enable_if


Type traits
A type trait is a templated struct that has member types that give you information about the type that it is templated on.

A quick primer on type traits in modern C++

https://www.youtube.com/watch?v=VvbTP_k_Df4

Template Specialization in C++ - GeeksforGeeks

is_integral

Stack in c++ STL :
A stack is a data structure that operates based on LIFO (Last In First Out) technique. The std::stack allows elements to be added and removed from one end only.

The std::stack class is a container adapter. Container objects hold data of a similar data type. You can create a stack from various sequence containers. If no container is provided, the Deque container will be used by default. Container adapters don’t support iterators, so they can’t be used to manipulate data.

stack - C++ Reference


Map in STL:
AVL tree :
AVL Trees: Rotations, Insertion, Deletion with C++ Example

value_compare Class ( )

AVL tree rotations :
AVL Tree - javatpoint

What is AVL tree Data structure ? | Rotations in AVL tree | All AVL operations with FULL CODE | DSA - Simple Snippets

Inorder Tree Traversal:
Inorder Tree Traversal - Iterative and Recursive | Techie Delight

Traversing Trees with Iterators:
Traversing Trees with Iterators
