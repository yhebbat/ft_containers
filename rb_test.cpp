// #define NOIR 0
// #define ROUGE 1
// #define FEUILLE NULL

// typedef struct nnoeud {
//   struct nnoeud *gauche; //Pointeur vers fils gauche
//   struct nnoeud *droit; //Pointeur vers fils droit 
//   struct nnoeud *parent; //Pointeur vers père
//   int couleur; // ROUGE ou NOIR
//   int clé; // Peut être n'importe quel type, tant que les opérations de comparaison (<, = , > ) sont définies
// }noeud;

// noeud* parent(noeud* n) {
//   return n->parent;
// }

// noeud* grandparent(noeud* n) {
//   struct noeud* p = parent(n);
//   if (p == NULL)
//     return NULL; // Un noeud sans parent n'a pas de grand-parent
//   return parent(p);
// }

// noeud* frere(noeud* n) {
//   struct noeud* p = parent(n);
//   if (p == NULL)
//     return NULL; // Un noeud sans parent n'a pas de frere
//   if (n == p->gauche)
//     return p->droit;
//   else
//     return p->gauche;
// }

// //Renvoie le frère du père
// noeud* oncle(noeud* enfant) {
//     noeud* p = parent(enfant);
//     noeud* g = grandparent(enfant);
//   if (g == NULL)
//     return NULL; // Pas de grand parent, donc pas d'oncle
//   return frere(p);
// }

// void rotation_gauche(noeud* x) {
//   noeud* y = x->droit;
//   //le fils droit de x devient le fils gauche de y
//   x->droit = y->gauche;
//   if (y->gauche != NULL)
//     y->gauche->parent = x;
 
//   y->parent = x->parent;
//   //Si x est la racine, y devient la racine
//   if (x->parent == NULL)
//     x = y;

//   //Sinon, on remplace x par y
//   else if (x == x->parent->gauche)
//     x->parent->gauche = y;
//   else
//     x->parent->droit = y;

//   //On attache x à gauche de y
//   y->gauche = x;
//   x->parent = y;
// }

// void rotation_droite(noeud* x) {
//     noeud* y = x->gauche;
//   //le fils gauche de x devient le fils droit de y
//   x->gauche = y->droit;
//   if (y->droit != NULL)
//     y->droit->parent = x;
 
//   y->parent = x->parent;
//   //Si x est la racine, y devient la racine
//   if (x->parent == NULL)
//     x = y;

//   //Sinon, on remplace x par y
//   else if (x == x->parent->droit)
//     x->parent->droit = y;
//   else
//     x->parent->gauche = y;

//   //On attache x à droite de y
//   y->droit = x;
//   x->parent = y;
// }

// void insertion_cas1(struct noeud *n) {
//    if (parent(n) == NULL)
//       n->couleur = NOIR;
//  }

// void insertion_cas2(struct noeud *n) {
//    return; /* Ne rien faire puisque l'arbre est bien un arbre rouge-noir */
//  }

//  void insertion_cas3(struct noeud *n) {
//    parent(n)->couleur = NOIR;
//    oncle(n)->couleur = NOIR;
   
//    struct noeud *g = grandparent(n);
//    g->couleur = ROUGE;
//    insertion_repare_arbre(g);
//  }


// void insertion_cas4(struct noeud *n) {
//    struct noeud *p = parent(n);
//    struct noeud *g = grandparent(n);

//    if (n == g->gauche->droit) {
//       rotation_gauche(p);
//       n = n->gauche;
//    } else if (n == g->droit->gauche) {
//       rotation_droit(p);
//       n = n->droit; 
//    }

//    insertion_cas5(n);
//  }


// void insertion_cas5(struct node *n) {
//    struct noeud *p = parent(n);
//    struct noeud *g = grandparent(n);

//    if (n == p->gauche)
//       rotation_droit(g);
//    else
//       rotation_gauche(g);
  
//    p->couleur = NOIR;
//    g->couleur = ROUGE;
//  }
// void insertion_repare_arbre(struct noeud *n) {
//    if (parent(n) == NULL)
//       insertion_cas1(n);
//    else if (parent(n)->couleur == NOIR)
//       insertion_cas2(n);
//    else if (oncle(n)->couleur == ROUGE)
//       insertion_cas3(n);
//    else
//       insertion_cas4(n);
//  }

// struct noeud *insertion(struct noeud *racine, struct noeud *n) {
//   // Insertion d'un nouveau nœud dans l'arbre
//   insertion_recursif(racine, n);

//   // Réparation de l'arbre au cas où les propriétés rouge-noir seraient violées
//   insertion_repare_arbre(n);

//   // Recherche de la nouvelle racine à renvoyer
//   racine = n;
   
//   while (parent(racine) != NULL)
//     racine = parent(racine);
    
//   return racine;
// }

// void insertion_recursif(struct noeud *racine, struct noeud *n) {
//   // Descente récursive dans l'arbre jusqu'à atteindre une feuille
//   if (racine != NULL && n->clé < racine->clé) {
//     if (racine->gauche != FEUILLE) {
//       insertion_recursif(racine->gauche, n);
//       return;
//     }
//     else
//       racine->gauche = n;
//   } 
//   else if (racine != NULL) {
//     if (racine->droit != FEUILLE) {
//       insertion_recursif(racine->droit, n);
//       return;
// 	}
//     else
//       racine->droit = n;
//   }

//   // Insertion du nouveau noeud n
//   n->parent = racine;
//   n->gauche = FEUILLE; // NIL
//   n->droit = FEUILLE; // NIL
//   n->couleur = ROUGE;
// }

// Implementing Red-Black Tree in C++

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *parent;
  Node *left;
  Node *right;
  int color;
};

typedef Node *NodePtr;

class RedBlackTree {
   private:
  NodePtr root;
  NodePtr TNULL;

  void initializeNULLNode(NodePtr node, NodePtr parent) {
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
  }

  // Preorder
  void preOrderHelper(NodePtr node) {
    if (node != TNULL) {
      cout << node->data << " ";
      preOrderHelper(node->left);
      preOrderHelper(node->right);
    }
  }

  // Inorder
  void inOrderHelper(NodePtr node) {
    if (node != TNULL) {
      inOrderHelper(node->left);
      cout << node->data << " ";
      inOrderHelper(node->right);
    }
  }

  // Post order
  void postOrderHelper(NodePtr node) {
    if (node != TNULL) {
      postOrderHelper(node->left);
      postOrderHelper(node->right);
      cout << node->data << " ";
    }
  }

  NodePtr searchTreeHelper(NodePtr node, int key) {
    if (node == TNULL || key == node->data) {
      return node;
    }

    if (key < node->data) {
      return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
  }

  // For balancing the tree after deletion
  void deleteFix(NodePtr x) {
    NodePtr s;
    while (x != root && x->color == 0) {
      if (x == x->parent->left) {
        s = x->parent->right;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          leftRotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->right->color == 0) {
            s->left->color = 0;
            s->color = 1;
            rightRotate(s);
            s = x->parent->right;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->right->color = 0;
          leftRotate(x->parent);
          x = root;
        }
      } else {
        s = x->parent->left;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          rightRotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->left->color == 0) {
            s->right->color = 0;
            s->color = 1;
            leftRotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->left->color = 0;
          rightRotate(x->parent);
          x = root;
        }
      }
    }
    x->color = 0;
  }

  void rbTransplant(NodePtr u, NodePtr v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  void deleteNodeHelper(NodePtr node, int key) {
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL) {
      if (node->data == key) {
        z = node;
      }

      if (node->data <= key) {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    if (z == TNULL) {
      cout << "Key not found in the tree" << endl;
      return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == TNULL) {
      x = z->right;
      rbTransplant(z, z->right);
    } else if (z->right == TNULL) {
      x = z->left;
      rbTransplant(z, z->left);
    } else {
      y = minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        rbTransplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      rbTransplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    delete z;
    if (y_original_color == 0) {
      deleteFix(x);
    }
  }

  // For balancing the tree after insertion
  void insertFix(NodePtr k) {
    NodePtr u;
    while (k->parent->color == 1) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            rightRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          leftRotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->right;

        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            leftRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          rightRotate(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    root->color = 0;
  }

  void printHelper(NodePtr root, string indent, bool last) {
    if (root != TNULL) {
      cout << indent;
      if (last) {
        cout << "R----";
        indent += "   ";
      } else {
        cout << "L----";
        indent += "|  ";
      }

      string sColor = root->color ? "RED" : "BLACK";
      cout << root->data << "(" << sColor << ")" << endl;
      printHelper(root->left, indent, false);
      printHelper(root->right, indent, true);
    }
  }

   public:
  RedBlackTree() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
  }

  void preorder() {
    preOrderHelper(this->root);
  }

  void inorder() {
    inOrderHelper(this->root);
  }

  void postorder() {
    postOrderHelper(this->root);
  }

  NodePtr searchTree(int k) {
    return searchTreeHelper(this->root, k);
  }

  NodePtr minimum(NodePtr node) {
    while (node->left != TNULL) {
      node = node->left;
    }
    return node;
  }

  NodePtr maximum(NodePtr node) {
    while (node->right != TNULL) {
      node = node->right;
    }
    return node;
  }

  NodePtr successor(NodePtr x) {
    if (x->right != TNULL) {
      return minimum(x->right);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  NodePtr predecessor(NodePtr x) {
    if (x->left != TNULL) {
      return maximum(x->left);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->left) {
      x = y;
      y = y->parent;
    }

    return y;
  }

  void leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  // Inserting a node
  void insert(int key) {
    NodePtr node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL) {
      y = x;
      if (node->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == nullptr) {
      root = node;
    } else if (node->data < y->data) {
      y->left = node;
    } else {
      y->right = node;
    }

    if (node->parent == nullptr) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr) {
      return;
    }

    insertFix(node);
  }

  NodePtr getRoot() {
    return this->root;
  }

  void deleteNode(int data) {
    deleteNodeHelper(this->root, data);
  }

  void printTree() {
    if (root) {
      printHelper(this->root, "", true);
    }
  }
};

int main() {
  RedBlackTree bst;
  bst.insert(55);
  bst.insert(40);
  bst.insert(65);
  bst.insert(60);
  bst.insert(75);
  bst.insert(57);

  bst.printTree();
  cout << endl
     << "After deleting" << endl;
  bst.deleteNode(40);
  bst.printTree();
}