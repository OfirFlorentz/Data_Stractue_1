//
// Created by ofir on 25/11/2019.
//

#ifndef HW1_WET_QUEUE_H
#define HW1_WET_QUEUE_H

#include <iostream>

using std::cout;

template <class T>
class Chain{
public:
    T value;
    Chain<T>* next;
    Chain<T>* prev;
    explicit Chain(const T& value) : value(value){
        next = nullptr;
        prev = nullptr;
    }
};


template <class T>
class Queue {
    Chain<T>* first;
    Chain<T>* last;
    int cur_size;
public:
    explicit Queue();
    ~Queue();
    void dequeue();
    void dequeueByValue(Chain<T>*);
    bool isExist(const T&) const;
    Chain<T>* enqueue(const T);
    T& top() const;
    bool isEmpty() const ;
    int getCurrentSize() const;
    class OverFlow : public std::exception{} ;
    class Empty : public std::exception{} ;
    class ElementDoesntExist : public std::exception{} ;
    class Nullptr : public std::exception{} ;
};




template <class T>

//constructor
Queue<T>::Queue() : cur_size(0) {
    first = nullptr;
    last = nullptr;
}

//destrector
template <class T>
Queue<T>:: ~Queue() {
    Chain<T> *cur = first;
    Chain<T> *next = nullptr;
    while(cur != nullptr){
        next = cur->next;
        delete cur;
        cur = next;
    }
}

template <class T>
void Queue<T>:: dequeue() {
    if (isEmpty()) {
        throw Empty();
    }
    Chain<T>* t = first;
    if(first == last) {
        first = last = nullptr;
    } else {
        first = first->next;
    }
    delete t;
    cur_size--;
}

template <class T>
Chain<T>* Queue<T>:: enqueue(const T element){
    Chain<T>* new_chain = new Chain<T>(element);
    new_chain->next= nullptr;
    new_chain->prev = last;
    new_chain->value = element;
    if(first== nullptr){
        last=first=new_chain;
    } else {
        last->next = new_chain;
        last = new_chain;
    }
    cur_size++;
    return new_chain;
}

template <class T>
T& Queue<T>::top() const {
    if(isEmpty()) {
        throw Empty();
    }
    return first->value;
}

template <class T>
bool Queue<T>::isEmpty() const {
    return cur_size == 0;
}

template <class T>
int Queue<T>::getCurrentSize() const {
    return cur_size;
}

template <class T>
void Queue<T>::dequeueByValue(Chain<T>* chain) {
    if(chain == nullptr)
        throw Nullptr();
    if (first == chain) {
        first = first->next;
        first->prev = nullptr;
        delete chain;
    } else if (last == chain) {
        last = chain->prev;
        last->next = nullptr;
        delete chain;
    } else {
        chain->prev->next = chain->next;
        chain->next->prev = chain->prev;
        delete chain;
    }
    cur_size--;
}


template <class T>
bool Queue<T>::isExist(const T& value) const{
    Chain<T> *cur = first;
    while(cur != nullptr){
        if(cur->value == value)
            return true;
        cur = cur->next;
    }
    return false;
}


#endif //HW1dequeue_WET_QUEUE_H
