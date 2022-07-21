
#include <iostream>

// class node 
// {
//     int data;
//     int height;
//     node *left;
//     node *right;

    
// };

class node {
  public:
    int data;
    int height;
    node *left;
    node *right;

    node(int data):data(data),height(0),left(NULL),right(NULL){};
    ~node() {};
	node() {
            this->left = NULL;
            this->right = NULL;
            this->height = 0;
	}
	node(const node& rhs)
	{
		this->data = rhs.data;
		this->height = rhs.height;
		this->left = rhs.left;
		this->right = rhs.right;
	}

	bool operator== (const node& rhs)
	{
		return (this->data == rhs.data 
			&& this->height == rhs.height && this->left == rhs.left && this->right == rhs.right);
	}
	bool operator!= (const node& rhs)
	{
		return !(*this == rhs);
	}
	node &operator=(const node& rhs)
	{
		this->data = rhs.data;
		this->height = rhs.height;
		this->left = rhs.left;
		this->right = rhs.right;
		return *this;
	}

};

// template < class T, class Alloc = std::allocator<T> >
class avl_tree
{
  public:
    node   *_root;
    avl_tree() { _root = NULL; };
	// avl_tree() { _root = new node(); };
    ~avl_tree() {};
	// ~avl_tree() { delete _root; };

	//**********calculate the height of the tree
	int calcul_height(node *p)//calculate the height of the tree
	{
		if(p->left && p->right)
		{
			if (p->left->height < p->right->height)
				return (p->right->height + 1);
			else
				return  (p->left->height + 1);
		}
		else if(p->left && p->right == NULL)
			return (p->left->height + 1);
		else if(p->left ==NULL && p->right)
			return (p->right->height + 1);
		return 0;
    }

	int bf(node *n)//balance factor
	{
		if(n->left && n->right)
			return n->left->height - n->right->height;
		else if(n->left && n->right == NULL)
			return n->left->height;
		else if(n->left== NULL && n->right )
			return -n->right->height;
		return 0;
	}

	//****************find the node in the tree

	node *find_min(node *p)//find the node in the tree
	{
		if(p->left)
			return find_min(p->left);
		else
			return p;
	}

	node *find_max(node *p)//find the node in the tree
	{
		if(p->right)
			return find_max(p->right);
		else
			return p;
	}

	bool exist(node* p, int data)//check if the data is in the tree
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

	node* search(node* p, int data)//search the data in the tree
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
	node* llrotation(node *n)
	{
        node *p;
        node *tp;

        p = n;
        tp = p->left;
        p->left = tp->right;
        tp->right = p;
        return (tp); 
    }

	node* rrrotation(node *n)
	{
		node *p;
		node *tp;

		p = n;
		tp = p->right;
		p->right = tp->left;
		tp->left = p;
		return (tp); 
	}

	node* rlrotation(node *n)
	{
		node *p;
		node *tp;
		node *tpp;

		p = n;
		tp = p->right;
		tpp = tp->left;
		p->right = tpp->left;
        tp->left = tpp->right;
        tpp->left = p;
        tpp->right = tp;
		return (tpp);
		// p->right = llrotation(tp);
		// return (rrrotation(p));
	}

	node* lrrotation(node *n)
	{
		node *p;
		node *tp;
		node *tpp;

		p = n;
		tp = p->left;
		tpp = tp->right;
		p->left = tpp->right;
		tp->right = tpp->left;
		tpp->right = p;
		tpp->left = tp;
		return (tpp);
		// p->left = rrrotation(tp);
		// return (llrotation(p));
	}
	//**********************modifiers for the tree

	void clear(node* &p)//delete the tree
	{
		if (p == NULL)
			return;
		// _alloc.destroy(&(p->data));
		if(p->left)
			clear(p->left);
		if(p->right)
			clear(p->right);
		delete(p);// _alloc_node.deallocate(p, 1);
		p = NULL;
	}

	node* insert_(node *r,int data)
	{
		if(r == NULL)
		{
			node *n;
			n = new node;
			n->data = data;
			r = n;
			r->left = r->right = NULL;
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
			r = rrrotation(r);
		else if(bf(r)==-2 && bf(r->right)==1)
			r = rlrotation(r);
		else if(bf(r)==2 && bf(r->left)==-1)
			r = lrrotation(r);
		return r;
	}

	node *min_node(node *node)
	{
		// node *current = node;
		while (node->left != NULL)
			node = node->left;
		return node;
	}

	node* delete_(node *p, int data)
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
				node *temp;
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
				delete(temp);
			}
			else
			{
				node *temp;
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
	void print_tree(node *r)
	{
		if (r == NULL)
		{
			std::cout << "Empty tree"<<std::endl;
			return;
		}
		print_tree(r, "", true);
    }
	
    void print_tree(node *root, std::string indent, bool last)
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
			std::cout << root->data << std::endl;
			print_tree(root->left, indent, false);
			print_tree(root->right, indent, true);
        }
    }
    
};

int main() {
	avl_tree root;
	root._root = root.insert_(root._root, 33);
	root._root = root.insert_(root._root, 13);
	root._root = root.insert_(root._root, 53);
	root._root = root.insert_(root._root, 9);
	root._root = root.insert_(root._root, 21);
	root._root = root.insert_(root._root, 61);
	root._root = root.insert_(root._root, 8);
	root._root = root.insert_(root._root, 11);
	root.print_tree(root._root);
	// if (root.exist(root._root, 13))
	// 	std::cout << "13 Found" << std::endl;
	// else
	// 	std::cout << "13 Not found" << std::endl;
	root._root = root.delete_(root._root, 13);
	std::cout << "After deleting " << std::endl;
	// if (root.exist(root._root, 13))
	// 	std::cout << "13 Found" << std::endl;
	// else
	// 	std::cout << "13 Not found" << std::endl;
	root.print_tree(root._root);
	std::cout << "After deleting all" << std::endl;
	root.clear(root._root);
	root.print_tree(root._root);

}

// int main(){

//     AVL b;
//     int c,x;

//     do{
//         cout<<"\n1.Display levelorder on newline";
//         cout<<"\n2.insert_";
//         cout<<"\n3.Delete\n";
//         cout<<"\n0.Exit\n";
//         cout<<"\nChoice: ";

//         cin>>c;

//         switch (c)
//         {
//         case 1:
//             b.levelorder_newline();
//             // to print the tree in level order
//             break;
                  
//         case 2:
//             cout<<"\nEnter no. ";
//             cin>>x;
//             b.root = b.insert_(b.root,x);
//             break;
        
//         case 3:
//             cout<<"\nWhat to delete? ";
//             cin>>x;
//             b.root = b.deleteNode(b.root,x);
//             break;
            
//         case 0:
//             break;
//         }

//      } while(c!=0);
  
// }