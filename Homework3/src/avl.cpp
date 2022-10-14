#include <bst.hpp>

template<class T>
AVL<T>::AVL() {
    this->null = new BSTNode<T>();
    this->null->left = this->null->right = this->null;
    this->null->height = 0;
}

template<class T>
int AVL<T>::balanceFactor(BSTNode<T> *node) {
    // YOUR CODE HERE
    return (node->right->height - node->left->height);
}

template<class T>
void AVL<T>::update(BSTNode<T> *node) {
    if (node == this->null)
        return;
    node->height = std::max(node->left->height, node->right->height) + 1;
}

template<class T>
BSTNode<T>* AVL<T>::rotateRight(BSTNode<T> *node) {
    // YOUR CODE HERE
    p = node;
    q = p->left;
    p->left = q->right;
    q->right = p;
    p->height = update(p);
    q->height = update(q);
    return q;
}

template<class T>
BSTNode<T>* AVL<T>::rotateLeft(BSTNode<T> *node) {
    // YOUR CODE HERE 
    p = node;
    q = p->right;
    p->right = q->left;
    q->left = p;
    p->height = update(p);
    q->height = update(q);
    return q;
}

template<class T>
BSTNode<T> *AVL<T>::balance(BSTNode<T> *node) {
    // YOUR CODE HERE
    node->height = update(node);
    if (balanceFactor(node) == 2){
        if (balanceFactor(node->right) < 0){
            node->right = rotateRight(node->right);
        }
        node = rotateLeft(node);
    }
    else if (balanceFactor(node) == -2){
        if (balanceFactor(node->left) > 0){
            node->left = rotateleft(node->left);
        }
        node = rotateRight(node);
    }
    return node;
}


template<class T>
BSTNode<T>* AVL<T>::insert(T key, BSTNode<T> *node) {
    // YOUR CODE HERE
}

template<class T>
BSTNode<T> *AVL<T>::insert(T key) {
    return BST<T>::insert(key);
}

template class AVL<int>;
