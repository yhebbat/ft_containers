#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class node {

    public:
        node *left;
        int data;
        int height;
        node *right;
        node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->height = 0;
        }
        node() {
            this->left = NULL;
            this->right = NULL;
            this->height = 0;
        }
};

class AVL
{
private:
    
public:
    node * root;
    AVL(){
        this->root = NULL;

    }

    int calheight(node *p){

            if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;

    }

    int bf(node *n){
            if(n->left && n->right){
                return n->left->height - n->right->height; 
            }
            else if(n->left && n->right == NULL){
                return n->left->height; 
            }
            else if(n->left== NULL && n->right ){
                return -n->right->height;
            }
    }

    node * llrotation(node *n){
        node *p;
        node *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp; 
    }


    node * rrrotation(node *n){
        node *p;
        node *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp; 
    }


    node * rlrotation(node *n){
        node *p;
        node *tp;
        node *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp; 
        
        return tp2; 
    }

    node * lrrotation(node *n){
        node *p;
        node *tp;
        node *tp2;
        p = n;
        tp = p->left;
        tp2 = p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp; 
        
        return tp2; 
    }

    node* insert(node *r,int data){
        
        if(r==NULL){
            node *n;
            n = new node;
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1; 
            return r;             
        }
        else{
            if(data < r->data)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }        

        return r;

        }

    void levelorder_newline(){
        if (this->root == NULL){
            cout<<"\n"<<"Empty tree"<<"\n";
            return;            
        }
        levelorder_newline(this->root);
    }

    void levelorder_newline(node *v){
        queue <node *> q;
        node *cur;
        q.push(v);
        q.push(NULL);      

        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur == NULL && q.size()!=0){
                cout<<"\n";
                
                q.push(NULL);
                continue;
            }
            if(cur!=NULL){
                cout<<" "<<cur->data;

                if (cur->left!=NULL){
                q.push(cur->left);
                }
                if (cur->right!=NULL){
                    q.push(cur->right);
                }
            }
            
            
        }
    }
 
    node *min_node(node *node)
	{
        while(node->left!=NULL)
            node = node->left;
        return node;
		// node *current = node;
		// while (current->left != NULL)
		// 	current = current->left;
		// return current;
	}

	node* deleteNode(node *p, int data)
	{
		if(p == NULL)
			return p;
        if(p->data < data)
            p->right = deleteNode(p->right,data);
        else if(p->data > data)
            p->left = deleteNode(p->left,data);
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
				p->right = deleteNode(p->right,temp->data);
			}
        }
		if(p == NULL)
			return p;
		p->height = calheight(p);

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

     node* inpre(node* p){
        while(p->right!=NULL)
            p = p->right;
        return p;    
    }

    node* insuc(node* p){
        while(p->left!=NULL)
            p = p->left;

        return p;    
    }

    void print_tree(node *r)
	{
		if (r == NULL)
		{
			std::cout << "Empty tree"<<std::endl;
			return;
		}
		print_tree(r, "", true);
    }

    void print_tree(node *root, string indent, bool last)
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
			std::cout << root->data << endl;
			print_tree(root->left, indent, false);
			print_tree(root->right, indent, true);
        }
    }

    ~AVL(){

    }
};

 int main() {
  AVL root;
  root.root = root.insert(root.root, 10);
  root.root = root.insert(root.root, 20);
  root.root = root.insert(root.root, 30);
  root.root = root.insert(root.root, 40);
  root.root = root.insert(root.root, 50);
  root.root = root.insert(root.root, 60);
//   root.root = root.insert(root.root, 70);
//   root.root = root.insert(root.root, 8);
//   root.root = root.insert(root.root, 11);
//   levelorder_newline();
root.print_tree(root.root);
  root.root = root.deleteNode(root.root, 13);
  cout << "After deleting " << endl;
//   levelorder_newline();
root.print_tree(root.root);
  return 0;
}

// int main(){

//     AVL b;
//     int c,x;

//     do{
//         cout<<"\n1.Display levelorder on newline";
//         cout<<"\n2.Insert";
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
//             b.root = b.insert(b.root,x);
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