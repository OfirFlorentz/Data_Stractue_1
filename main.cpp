#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

int main(){

    Queue<int> q = Queue<int>(4);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(4);
    q.enqueue(3);

    try{
        q.enqueue(3);
    } catch (std::exception& e) {
        std::cout << e.what();
    }

    std::cout << q.top() << " max size is: " << q.getMaxSize();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    std::cout << q.top();

    return 0;
}