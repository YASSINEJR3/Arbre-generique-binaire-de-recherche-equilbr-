#ifndef BTREE_H
#define BTREE_H
#include <iostream>

using namespace std;

//doit etre generic
template<class T>
struct Node {

  T key;
  Node* left;
  Node* right;
  int height;

  Node(T key) {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
  }
};

template<class T>
class BTree
{
    public:
        BTree();
        virtual ~BTree();
        int GetHeight(Node<T>* );
        int GetBalance(Node<T>* );
        Node<T>* RightRotate(Node<T>*);
        Node<T>* LeftRotate(Node<T>* );
        void Insert(T );
        bool recherche(T );
        void afficher();
    protected:

    private:
        Node<T>* root;
        Node<T>* Insert(Node<T>* , T );
        bool recherche(Node<T>*,T );
        void padding(char,int);
        void structure(Node<T>*,int=0);
};

#endif // BTREE_H
