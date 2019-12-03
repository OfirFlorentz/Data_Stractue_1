#include <iostream>
#include "Queue.h"

using std::cout;

template <class T>

//constructor
Queue<T>::Queue(int max_size) : front(0), rear(0), max_size(max_size), cur_size(0) {
    arr = new T[max_size];
}

//destrector
template <class T>
Queue<T>:: ~Queue() {
    delete []arr;
}

template <class T>
void Queue<T>:: dequeue() {
    if(isEmpty()) {
        throw Empty();
    }
    front = (front + 1) % max_size ;
    cur_size --;
}

template <class T>
void Queue<T>:: enqueue(const T element) {
    if(isFull()) {
        throw Full();
    }
    arr[rear] = element;
    cur_size++;
    rear = (rear + 1) % max_size ;
}

template <class T>
T Queue<T>::top() const {
    if(isEmpty()) {
        return NULL;
    }
    return arr[front];
}

template <class T>
bool Queue<T>::isEmpty() const {
    return cur_size == 0;
}

template <class T>
bool Queue<T>::isFull() const {
    return cur_size == max_size;
}

template <class T>
int Queue<T>::getMaxSize() const {
    return max_size;
}

template <class T>
int Queue<T>::getCurrentSize() const {
    return cur_size;
}




