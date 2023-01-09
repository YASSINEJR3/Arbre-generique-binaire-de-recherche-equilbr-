#include "BTree.h"


template<class T>
BTree<T>::BTree()
{
    //ctor
    root  = nullptr;
}

template<class T>
BTree<T>::~BTree()
{
    //dtor
}

template<class T>
int BTree<T>::GetHeight(Node<T>* node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

template<class T>
int BTree<T>::GetBalance(Node<T>* node)
{
    if (node == nullptr)
        return 0;
    return GetHeight(node->left) - GetHeight(node->right);

}

template<class T>
Node<T>* BTree<T>::RightRotate(Node<T>* y) {
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(GetHeight(y->left), GetHeight(y->right)) + 1;
    x->height = std::max(GetHeight(x->left), GetHeight(x->right)) + 1;

    return x;
}

template<class T>
Node<T>* BTree<T>::LeftRotate(Node<T>* x) {

    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(GetHeight(x->left), GetHeight(x->right)) + 1;
    y->height = std::max(GetHeight(y->left), GetHeight(y->right)) + 1;

    return y;
}

template<class T>
Node<T>* BTree<T>::Insert(Node<T>* node, T key) {
    if (node == nullptr)
        return new Node<T>(key);


    if (key < node->key)
      node->left = Insert(node->left, key);
    else if (key >= node->key)
      node->right = Insert(node->right, key);

    //balancing
    node->height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
    int balance = GetBalance(node);

    if (balance > 1 && key < node->left->key) {
      return RightRotate(node);
    }

    if (balance < -1 && key > node->right->key) {
      return LeftRotate(node);
    }

    if (balance > 1 && key > node->left->key) {
      node->left = LeftRotate(node->left);
      return RightRotate(node);
    }

    if (balance < -1 && key < node->right->key){
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}

template<class T>
void BTree<T>::padding ( char ch, int n )
{
  int i;
  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

template<class T>
void BTree<T>::structure( Node<T>* arbre, int level )
{
  if ( arbre == nullptr ) {
    padding ( '\t', level );
    puts ( "~" );
  }
  else {
    structure ( arbre->right, level + 1 );
    padding ( '\t', level );
    cout <<arbre->key<< endl;
    structure ( arbre->left, level + 1 );
  }
}

template<class T>
void BTree<T>::afficher()
{
    if(root != nullptr)
        structure(root);
}

template<class T>
void BTree<T>::Insert(T key)
{
    root = Insert(root,key);
}

template<class T>
bool BTree<T>::recherche(T data)
{
    return recherche(root,data);
}

template<class T>
bool BTree<T>::recherche(Node<T>* N, T key)
{
    if(N == nullptr)
        return false;
    if(N->key == key )
        return true;

    if( N->key > key )
        recherche(N->left ,key);
    else
        recherche(N->right ,key);

}
