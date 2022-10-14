#include <bst.hpp>
#include <stack.hpp>

// Operator Overloading

bool operator<( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) {
    return (lhs.first < rhs.first) || (lhs.first == rhs.first && lhs.second < rhs.second);
}

bool operator>( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) {
    return (lhs.first > rhs.first) || (lhs.first == rhs.first && lhs.second > rhs.second);
}

bool operator==( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) {
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}


template<class T>
BSTNode<T>::BSTNode() {
    this->left = this->right = NULL;
    this->height = 0;
}

template<class T>
BSTNode<T>::BSTNode(T key, int height, BSTNode *left, BSTNode *right) {
    this->key = key;
    this->height = height;
    this->left = left;
    this->right = right;
}

template<class T>
BSTNode<T>::~BSTNode() {
    this->left = this->right = NULL;
}


template<class T>
void BST<T>::clear(BSTNode<T> *node) {
    // YOUR CODE HERE
    if (node == NULL){
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
    node = NULL;
}

template<class T>
BSTNode<T> *BST<T>::find(T key, BSTNode<T> *node) {
    // YOUR CODE HERE
    if (node == NULL){
        return NULL;
    }
    if (node->key == key){
        return node;
    }
    if (key < node->key){
        return find(key, node->left);
    }
    else{
        return find(key, node->right);
    }
}

template<class T>
BSTNode<T> *BST<T>::findMaximum(BSTNode<T> *node) {
    // YOUR CODE HERE
    if (node == NULL){
        return node;
    }
    if (node->right == NULL){
        return node;
    }
    return findMaximum(node->right);
}

template<class T>
BSTNode<T> *BST<T>::insert(T key, BSTNode<T> *node) {
    // YOUR CODE HERE
    if (node == NULL){
        BSTNode<T> *tempNode = new BSTNode<T>(key);
        return tempNode;
    }
    if (key < node->key){
        node->left = insert(key, node->left);
    }
    else{
        node->right = insert(key, node->right);
    }
    return node;
}

template<class T>
BSTNode<T> *BST<T>::remove(T key, BSTNode<T> *node) {
    // YOUR CODE HERE
    if (node->key == key){
        if (node->right == NULL && node->left == NULL){
            delete node;
            return NULL;
        }
        else if (node->right == NULL && node->left != NULL){
            BSTNode<T> *tempNode = node->left;
            delete node;
            return tempNode;
        }
        else if (node->right != NULL && node->left == NULL){
            BSTNode<T> *tempNode = node->left;
            delete node;
            return tempNode;
        }
        else if (node->right != NULL && node->left != NULL){
            key = findMaximum(node->left)->key;
            node->key = key;
            node->left = remove(key, node->left);
        }
    }
    else if (key < node->key){
        node->left = remove(key, node->left);
    }
    else{
        node->right = remove(key, node->right);
    }
    return node;
}


template<class T>
BST<T>::BST() {
    this->root = NULL;
}

template<class T>
BST<T>::~BST() {
    this->clear(this->root);
 }


template<class T>
BSTNode<T> *BST<T>::find(T key) {
    return this->find(key, this->root);
}

template<class T>
BSTNode<T> *BST<T>::findMaximum() {
    return this->findMaximum(this->root);
}


template<class T>
BSTNode<T> *BST<T>::insert(T key) {
    return this->root = this->insert(key, this->root);
}

template<class T>
BSTNode<T> *BST<T>::remove(T key) {
    return this->root = this->remove(key, this->root);
}

template class BSTNode<int>;
template class BST<int>;

template class BSTNode<std::pair<int, int> >;
template class BST<std::pair<int, int> >;
