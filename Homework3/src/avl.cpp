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
    BSTNode <T> *p = node;
    BSTNode <T> *q = p->left;
    p->left = q->right;
    q->right = p;
    update(p);
    update(q);
    return q;
}

template<class T>
BSTNode<T>* AVL<T>::rotateLeft(BSTNode<T> *node) {
    // YOUR CODE HERE 
    BSTNode <T> *p = node;
    BSTNode <T> *q = p->right;
    p->right = q->left;
    q->left = p;
    update(p);
    update(q);
    return q;
}

template<class T>
BSTNode<T> *AVL<T>::balance(BSTNode<T> *node) {
    // YOUR CODE HERE
    update(node);
    if (balanceFactor(node) == 2){
        if (balanceFactor(node->right) < 0){
            node->right = rotateRight(node->right);
        }
        node = rotateLeft(node);
    }
    else if (balanceFactor(node) == -2){
        if (balanceFactor(node->left) > 0){
            node->left = rotateLeft(node->left);
        }
        node = rotateRight(node);
    }
    return node;
}


template<class T>
BSTNode<T>* AVL<T>::insert(T key, BSTNode<T> *node) {
    // YOUR CODE HERE
    if (node == NULL){
        BSTNode<T> *tempNode = new BSTNode<T>(key);
    }
    if (key < node->key){
        node->left = insert(key, node->left);
    }
    else{
        node->right = insert(key, node->right);
    }
    node = balance(node);
    return node;
}

template<class T>
BSTNode<T> *AVL<T>::insert(T key) {
    return BST<T>::insert(key);
}

template class AVL<int>;
