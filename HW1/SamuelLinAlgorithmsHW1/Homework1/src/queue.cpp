#include <queue.hpp>

template<class T>
QueueNode<T>::QueueNode(T value, QueueNode<T> *next, QueueNode<T> *prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
QueueNode<T>::~QueueNode() {
    this->next = this->prev = NULL;
}

template<class T>
Queue<T>::Queue() {
    this->head = this->tail = NULL;
}

template<class T>
Queue<T>::~Queue() {
    // YOUR CODE HERE
    QueueNode<T> *currNode = this->head;
    while (currNode != NULL) {
        QueueNode<T> *tempNode = currNode->next;
        delete currNode;
        currNode = tempNode;
    }
    this->head = NULL;
    this->tail = NULL;
}

template<class T>
bool Queue<T>::empty() {
    // YOUR CODE HERE
    if (this->head == NULL && this->tail == NULL) {
        return true;
    }
    else {
        return false;
    }
    return true;
}

template<class T>
T Queue<T>::pop() {
    T value = this->head->value;
    // YOUR CODE HERE
    QueueNode<T> *currNode = this->head;
    this->head = currNode->next;
    delete currNode;
    if (this->head == NULL) {
        this->tail = NULL;
    } 
    else
        this->head->prev = NULL;
    return value;
}

template<class T>
void Queue<T>::push(T value) {
    QueueNode<T> *p = new QueueNode<T>(value, NULL, NULL);
    // YOUR CODE HERE
    p->next = NULL;
    if (this->tail == NULL) {
        this->head = this->tail = p;
    } else {
        this->tail->next = p;
        p->prev = this->tail;
        this->tail = p;
    }
}

template class Queue<int>;
