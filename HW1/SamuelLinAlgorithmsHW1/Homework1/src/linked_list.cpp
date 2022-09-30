#include <linked_list.hpp>

template<class T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T>* next, LinkedListNode<T>* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
    this->next = NULL;
}


template<class T>
LinkedList<T>::LinkedList() {
     this->root = NULL;
}

template<class T>
LinkedList<T>::~LinkedList() {
    // YOUR CODE HERE
    LinkedListNode<T> *currNode = this->root;
    while (currNode != NULL){
        LinkedListNode<T> *tempNode = currNode->next;
        delete currNode;
        currNode = tempNode;
    }
}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
    // YOUR CODE HERE
    LinkedListNode<T> *valNode = find(value);
    if (valNode != NULL) {
        return valNode;
    }
    else {
        valNode = new LinkedListNode<T>(value, this->root, NULL);
        this->root = valNode;
        return valNode;
    }
}

template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {
    // YOUR CODE HERE
    LinkedListNode<T> *currNode = this->root;
    while (currNode != NULL && currNode->value != value) {
        currNode = currNode->next;
    }
    return currNode;
}

template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
    // YOUR CODE HERE
    LinkedListNode<T> *currNode = this->root;
    LinkedListNode<T> *prevNode = NULL;
    while (currNode != NULL) {
        if (currNode->value == value){
            if (prevNode == NULL) {
                this->root = currNode->next;
            }
            else {
                prevNode->next = currNode->next;
            }
            delete currNode;
            break;
        }
        else {
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
    return this->root;
}

template<class T>
int LinkedList<T>::size() {
    // YOUR CODE HERE 
    LinkedListNode<T> *currNode = this->root;
    int count = 0;
    while (currNode != NULL) {
        currNode = currNode->next;
        count += 1;
    }
    return count;
}

template class LinkedListNode<int>;
template class LinkedList<int>;
