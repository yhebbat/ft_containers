
#include <iostream>
#include "./utilities/utilities.hpp"

template <class T>
class node {
  public:
    // int data;
	T	data;
    int height;
    node *left;
    node *right;
	node *parent;

    node(T data):data(data),height(0),left(NULL),right(NULL){};
    ~node() {};
	node() {
            this->left = NULL;
            this->right = NULL;
            this->height = 0;
			this->parent = NULL;
	}
	node(const node& rhs)
	{
		this->data = rhs.data;
		this->height = rhs.height;
		this->left = rhs.left;
		this->right = rhs.right;
		this->parent = rhs.parent;
	};

	bool operator== (const node& rhs)
	{
		return (this->data == rhs.data);
	};

	bool operator!= (const node& rhs)
	{
		return !(*this == rhs);
	};
	node &operator=(const node& rhs)
	{
		this->data = rhs.data;
		this->height = rhs.height;
		this->left = rhs.left;
		this->right = rhs.right;
		this->parent = rhs.parent;
		return *this;
	};

};

// template < class key, class T, class Alloc = std::allocator<T>, class Allconode = std::allocator<node<T> > >
    template <class Key,                                          // map::key_type
              class T,                                             // map::mapped_type
              class Compare = std::less<Key>,                      // map::key_compare
            //   class Alloc = std::allocator<ft::pair<const Key, T> >, // map::allocator_type
			  class Alloc = std::allocator<T>,
			  class Allconode = std::allocator<node<T> >
              >
class avl_tree
{
  public:
	typedef node<T>					node_type;
	typedef Alloc					allocator_type;
	typedef Allconode				alloc_node;

	private:
	node_type		*_root;
	allocator_type	_alloc;
	alloc_node		_alloc_node;
	size_t			_size;

	public:
    avl_tree():_size(0) { _root = NULL; };
	avl_tree(const avl_tree &other) : _root(other._root), _size(other._size)
	{
		*this = other;
	}
    ~avl_tree() {};

	avl_tree &operator=(const avl_tree& rhs) 
	{
		this->_alloc = rhs._alloc;
		this->_alloc_node = rhs._alloc_node;
		insert_nodes(rhs._root);
		return (*this);
	};

	void insert_nodes(node_type *node)
	{
		if (node == NULL)
			return;
		insert_(node->data);
		if (node->left != NULL)
			insert_nodes(node->left);
		if (node->right != NULL)
			insert_nodes(node->right);
	}
	//**********calculate the height of the tree

	int calcul_height(node_type *p)//calculate the height of the tree
	{
		if(p->left && p->right)
		{
			if (p->left->height < p->right->height)
			{
				// std::cout << p->data << "height is :" << p->right->height << std::endl;
				return (p->right->height + 1);
			}
			else
			{
				// std::cout << p->data << "height is :" << p->left->height << std::endl;
				return  (p->left->height + 1);
			}
		}
		else if(p->left && p->right == NULL)
		{
			// std::cout << p->data << "height is :" << p->left->height << std::endl;
			return (p->left->height + 1);
		}
		else if(p->left == NULL && p->right)
		{
			// std::cout << p->data << " height is :" << p->right->height << ":::" << p->right->data << std::endl;
			return (p->right->height + 1);
		}
		// std::cout << p->data << "height is :0" << std::endl;
		return 1;
    }

	int bf(node_type *n)//balance factor
	{
		if(n->left && n->right)
			return n->left->height - n->right->height;
		else if(n->left && n->right == NULL)
			return n->left->height;
		else if(n->left== NULL && n->right )
			return -n->right->height;
		return 0;
	}

	//****************find the node_type in the tree

	node_type *find_next(T data)
	{
		return find_next(data, _root);
	}

	node_type *find_next(T data, node_type *p)//find the node_type in the tree
	{
		node_type *here;
		if(exist(p, data))
		{
			here = search(p, data);
			if(here->right)
				return find_min(here->right);
			else if(here->parent)
			{
				node_type *dad = here->parent;
				if (dad->left == here)
					return dad;
				else if(dad->right == here)
				{
					while(dad && dad->right == here)
					{
						here = dad;
						dad = here->parent;
					}
					return dad;
				}
			}
		}
		return NULL;
	}

	node_type *find_prev(T data)
	{
		return find_prev(data, _root);
	}

	node_type *find_prev(T data, node_type *p)//find the node_type in the tree
	{
		node_type *here;
		if(exist(p, data))
		{
			here = search(p, data);
			if(here->left)
				return find_max(here->left);
			else if(here->parent)
			{
				node_type *dad = here->parent;
				if (dad->right == here)
					return dad;
				else if(dad->left == here)
				{
					while(dad && dad->left == here)
					{
						here = dad;
						dad = here->parent;
					}
					return dad;
				}
			}
		}
		return NULL;
	}

	node_type *find_min()
	{
		return find_min(_root);
	}

	node_type *find_max()
	{
		return find_max(_root);
	}

	node_type *find_min(node_type *p)//find the node_type in the tree
	{
		if(p->left)
			return find_min(p->left);
		else
			return p;
	}

	node_type *find_max(node_type *p)//find the node_type in the tree
	{
		if(p->right)
			return find_max(p->right);
		else
			return p;
	}

	bool exist(node_type* p, T data)//check if the data is in the tree
	{
		if(p == NULL)
			return false;
		if(p->data == data)
			return true;
		if(p->data > data)
			return exist(p->left, data);
		else
			return exist(p->right, data);
	}

	node_type* search(node_type* p, T data)//search the data in the tree
	{
		if(p == NULL)
			return NULL;
		if(p->data == data)
			return p;
		if(p->data > data)
			return search(p->left, data);
		else
			return search(p->right, data);
	}

	//*****************roatations
	node_type* llrotation(node_type *n)
	{
        node_type *p;
        node_type *tp;

        p = n;
        tp = p->left;
        p->left = tp->right;
        tp->right = p;
		p->height = calcul_height(p);
		tp->height = calcul_height(tp);
        return (tp); 
    }

	node_type* rrrotation(node_type *n)
	{
		node_type *p;
		node_type *tp;

		p = n;
		tp = p->right;
		p->right = tp->left;
		tp->left = p;
		p->height = calcul_height(p);
		tp->height = calcul_height(tp);
		return (tp); 
	}

	node_type* rlrotation(node_type *n)
	{
		node_type *p;
		node_type *tp;
		node_type *tpp;

		p = n;
		tp = p->right;
		tpp = tp->left;
		p->right = tpp->left;
        tp->left = tpp->right;
        tpp->left = p;
        tpp->right = tp;
		p->height = calcul_height(p);
		tp->height = calcul_height(tp);
		tpp->height = calcul_height(tpp);
		return (tpp);
		// p->right = llrotation(tp);
		// return (rrrotation(p));
	}

	node_type* lrrotation(node_type *n)
	{
		node_type *p;
		node_type *tp;
		node_type *tpp;

		p = n;
		tp = p->left;
		tpp = tp->right;
		p->left = tpp->right;
		tp->right = tpp->left;
		tpp->right = p;
		tpp->left = tp;
		p->height = calcul_height(p);
		tp->height = calcul_height(tp);
		tpp->height = calcul_height(tpp);
		return (tpp);
		// p->left = rrrotation(tp);
		// return (llrotation(p));
	}
	//**********************modifiers for the tree

	void clear()
	{
		
		if(_root)
			clear(_root);
		_root = NULL;
		_size = 0;
	}
	void clear(node_type* &p)//clear all the tree
	{
		if (p == NULL)
			return;
		_alloc.destroy(&(p->data));
		if(p->left)
			clear(p->left);
		if(p->right)
			clear(p->right);
		_alloc_node.deallocate(p, 1);
		p = NULL;
		_size = 0;
	}

	void find_parent(node_type *p)
	{
		if (p == NULL)
			return;
		if (p == _root)
			p->parent = NULL;
		if(p->left)
		{
			node_type *tmp = p->left;
			tmp->parent = p;
			find_parent(tmp);
		}
		if(p->right)
		{
			node_type *tmp = p->right;
			tmp->parent = p;
			find_parent(tmp);
		}
	}

	int size() const
	{
		return this->_size;
	}

	bool empty() const
	{
		return (this->_size == 0);
	}
	
	bool insert_(T data)
	{
		if (exist(_root, data))
			return false;
		this->_root = this->insert_(_root, data);
		this->_size++;
		find_parent(_root);
		return true;
	}

	node_type* insert_(node_type *r,T data)
	{
		// if (r != NULL)
		// 	std::cout << "inserting " << data << " in the tree" << r->data << std::endl;
		if(r == NULL)
		{
			// std::cout << "inserting " << data << std::endl;
			node_type *n;
			// n = new node_type;
			n = _alloc_node.allocate(1);
			_alloc.construct(&(n->data), data);
			// n->data = data;
			r = n;
			r->left = r->right = r->parent = NULL;
			r->height = 1;
			return r;             
		}
		else
		{
			if(data < r->data)
				r->left = insert_(r->left, data);
			else
				r->right = insert_(r->right, data);
		}
		r->height = calcul_height(r);
		if(bf(r)==2 && bf(r->left)==1)
			r = llrotation(r);
		else if(bf(r)==-2 && bf(r->right)==-1)
		{
			// std::cout << "here here" << std::endl;
			r = rrrotation(r);
		}
		else if(bf(r)==-2 && bf(r->right)==1)
			r = rlrotation(r);
		else if(bf(r)==2 && bf(r->left)==-1)
			r = lrrotation(r);
		return r;
	}

	node_type *min_node(node_type *node)
	{
		// node_type *current = node_type;
		while (node->left != NULL)
			node = node->left;
		return node;
	}


	bool delete_(T data)
	{
		if (!exist(_root, data))
			return false;
		_root = delete_(_root, data);
		_size--;
		find_parent(_root);
		return true;
	}

	node_type* delete_(node_type *p, T data)
	{
		if(p == NULL)
			return p;
        if(p->data < data)
            p->right = delete_(p->right,data);
        else if(p->data > data)
            p->left = delete_(p->left,data);
        else
		{
			if(p->left == NULL || p->right == NULL)
			{
				node_type *temp;
				if(p->left)
					temp = p->left;
				else
					temp = p->right;
				if(temp == NULL)
				{
					temp = p;
					p = NULL;
				}
				else
					*p = *temp;
				_alloc.destroy(&(temp->data));
				_alloc_node.deallocate(temp, 1);
			}
			else
			{
				node_type *temp;
				temp = min_node(p->right);
				p->data = temp->data;
				p->right = delete_(p->right,temp->data);
			}
        }
		if(p == NULL)
			return p;
		p->height = calcul_height(p);

        if(bf(p)==2 && bf(p->left)==1)
			p = llrotation(p);                  
        else if(bf(p)==2 && bf(p->left)==-1)
			p = lrrotation(p);
        else if(bf(p)==2 && bf(p->left)==0)
			p = llrotation(p);
        else if(bf(p)==-2 && bf(p->right)==-1)
			p = rrrotation(p);
        else if(bf(p)==-2 && bf(p->right)==1)
			p = rlrotation(p);
        else if(bf(p)==-2 && bf(p->right)==0)
			p = llrotation(p);
        return p;
    }

	//************display the tree in the following format:
	void print_tree()
	{
		print_tree(_root);
		// std::cout << _size << std::endl;
    }
	void print_tree(node_type *r)
	{
		// std::cout << _size << std::endl;
		if (r == NULL)
		{
			std::cout << "Empty tree"<<std::endl;
			return;
		}
		print_tree(r, "", true);
    }

    void print_tree(node_type *root, std::string indent, bool last)
	{
        if (root != nullptr)
        {
        	std::cout << indent;
			if (last)
			{
				std::cout << "R----";
				indent += "   ";
			}
			else
			{
				std::cout << "L----";
				indent += "|  ";
			}
			std::cout << root->data ;//<<"::"<< root->height;
			// if (root->parent == NULL)
			// 	std::cout << " root";
			// else
			// 	std::cout << " parent->" << root->parent->data;
			// if (root->left != NULL)
			// 	std::cout << " my left is " << root->left->data;
			// if (root->right != NULL)
			// 	std::cout << " my right is " << root->right->data;
			std::cout << std::endl;
			print_tree(root->left, indent, false);
			print_tree(root->right, indent, true);
        }
    }
    
};

int main()
{
	avl_tree<int, int> root;
	root.insert_(10);
	root.insert_(20);
	root.insert_(30);
	root.insert_(40);
	root.insert_(50);
	root.insert_(60);
	root.insert_(70);
	root.insert_(80);
	root.insert_(90);
	std::cout << "size: " << root.size() << std::endl;
	avl_tree<int, int> root2;
	root2 = root;
	// std::cout << "next of 10 is :"<< root.find_next(10)->data << std::endl;
	// if (root.find_prev(10) == NULL)
	// 	std::cout << "next of 90 is : NULL" << std::endl;
	// else
	// 	std::cout << "next of 10 is :"<< root.find_next(90)->data << "prev of 10 is :"<< root.find_prev(10)->data  << std::endl;;
	// std::cout << "next of 20 is :"<< root.find_next(20)->data << "prev of 20 is :"<< root.find_prev(20)->data  << std::endl;
	// std::cout << "next of 30 is :"<< root.find_next(30)->data << "prev of 30 is :"<< root.find_prev(30)->data  << std::endl;
	// std::cout << "next of 40 is :"<< root.find_next(40)->data << "prev of 40 is :"<< root.find_prev(40)->data  << std::endl;
	// std::cout << "next of 50 is :"<< root.find_next(50)->data << "prev of 50 is :"<< root.find_prev(50)->data  << std::endl;
	// std::cout << "next of 70 is :"<< root.find_next(70)->data << "prev of 70 is :"<< root.find_prev(70)->data  << std::endl;
	// std::cout << "next of 60 is :"<< root.find_next(60)->data << "prev of 60 is :"<< root.find_prev(60)->data  << std::endl;
	// std::cout << "next of 80 is :"<< root.find_next(80)->data << "prev of 80 is :"<< root.find_prev(80)->data  << std::endl;
	// if (root.find_next(90) == NULL)
	// 	std::cout << "next of 90 is : NULL" << std::endl;
	// else
	// 	std::cout << "next of 90 is :"<< root.find_next(90)->data << std::endl;
	// std::cout << "min value" << root.find_min()->data << std::endl;
	// std::cout << "max value" << root.find_max()->data << std::endl;
	root2.print_tree();
	// if (root.exist(root._root, 13))
	// 	std::cout << "13 Found" << std::endl;
	// else
	// 	std::cout << "13 Not found" << std::endl;
	// root._root = root.delete_(root._root, 60);
	root.delete_(60);
	// std::cout << "next of 50 is :"<< root.find_next(50)->data << "prev of 50 is :"<< root.find_prev(50)->data  << std::endl;
	// root._root = root.delete_(root._root, 13);
	// root._root = root.delete_(13);
	std::cout << "After deleting " << std::endl;
	// if (root.exist(root._root, 13))
	// 	std::cout << "13 Found" << std::endl;
	// else
	// 	std::cout << "13 Not found" << std::endl;
	// root.print_tree(root._root);
	root2.print_tree();
	// std::cout << "After deleting all" << std::endl;
	// root.clear();
	// root.print_tree(root._root);
	// system("leaks a.out");
	// root.print_tree();

}