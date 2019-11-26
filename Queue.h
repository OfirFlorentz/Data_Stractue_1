//
// Created by ofir on 25/11/2019.
//

#ifndef HW1_WET_QUEUE_H
#define HW1_WET_QUEUE_H

template <class T>
class Queue {
    T* arr;
    int max_size;
    int cur_size;
    int front;
    int rear;
public:
    explicit Queue(int size);
    ~Queue();
    void dequeue();
    void enqueue(T value);
    T top() const;
    bool isEmpty() const ;
    bool isFull() const ;
    int getMaxSize() const;
    int getCurrentSize() const;
    class Full : public std::exception{} ;
    class Empty : public std::exception{} ;

};


#endif //HW1dequeue_WET_QUEUE_H
