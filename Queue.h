/**This class is queue. it implented with two diractions linked nodes**/
/**The Queue suppoort the basic queue functions like enqueue and dequeue and also support removing element from the
 middle of the queue**/

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
    //Pointer to the first node in the queue
    Chain<T>* last;
    //Pointer to the last node in the queue
    Chain<T>* first;
    //current size of the queue
    int cur_size;
public:
    /* constructor */
    explicit Queue();
    /* destructor */
    ~Queue();
    /* c'contructor, and operator == are not implemted */
    bool operator==(const Queue&) = delete;
    Queue(const Queue&) = delete;
    /* remove first element of the queue */
    void dequeue();
    /* remove the element we get as an input from the queue */
    void dequeueByValue(Chain<T>*);
    /* Add element to the end of the queue */
    Chain<T>* enqueue(const T);
    /* Return the first element in the queue */
    T& top() const;
    /* Return the true if queue is empty, false otherwise*/
    bool isEmpty() const ;
    /* Exceptions classes */
    class Empty : public std::exception{} ;
    class Nullptr : public std::exception{} ;
};



template <class T>

//constructor
Queue<T>::Queue() : cur_size(0) {
    first = nullptr;
    last = nullptr;
}

//destructor
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
void Queue<T>::dequeueByValue(Chain<T>* chain) {
    if(chain == nullptr)
        throw Nullptr();
    if (first == chain) {
        dequeue(); //make cur size smaller in 1
        cur_size++; //fix the problem above
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


#endif //HW1dequeue_WET_QUEUE_H
