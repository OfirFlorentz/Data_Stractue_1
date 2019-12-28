//
// Created by Nathan on 12/28/2019.
//

#ifndef HW1_WET_HASHTABLE_H
#define HW1_WET_HASHTABLE_H


#include "AVLTree.h"

const int initial_size = 4;

template <class T>
class HashTable {
    AVLTree<T>* arr;
    int size;
    int num_itmes;

    //Functions
    int HashFunc (T* item);
    void IncreaseTable();
    void DecreaseTable();

public:
    HashTable();
    virtual ~HashTable();
    void addItem (T* item);
    void removeItem (T* item);
    int getNumItmes() const;
    int getSize() const;
};

template<class T>
HashTable<T>::HashTable() {
    size = initial_size;
    arr = new AVLTree<T>[size];
    num_itmes = 0;
}


template<class T>
HashTable<T>::~HashTable() {
    delete[] arr;
}

template<class T>
int HashTable<T>::getSize() const {
    return size;
}

template<class T>
int HashTable<T>::getNumItmes() const {
    return num_itmes;
}

template<class T>
int HashTable<T>::HashFunc(T *item) {
    return *item % size;
}

template<class T>
void HashTable<T>::IncreaseTable() {
    int old_size = size;
    size = size*2;
    AVLTree<T>* new_arr = new AVLTree<T>[size];
    for (int i = 0; i < old_size ; ++i) {
        T** temp_arr = arr[i].inorderArr();
        for (int j = 0; j < sizeof(temp_arr)/sizeof(temp_arr[0]) ; ++j) {
            new_arr[HashFunc(temp_arr[j])].insertTreeNode(temp_arr[j]);
        }
        delete temp_arr;
    }
    delete arr;
    arr = new_arr;
}

template<class T>
void HashTable<T>::DecreaseTable() {
    int old_size = size;
    size = size/2;
    AVLTree<T>* new_arr = new AVLTree<T>[size];
    for (int i = 0; i < old_size ; ++i) {
        T** temp_arr = arr[i].inorderArr();
        for (int j = 0; j < sizeof(temp_arr)/sizeof(temp_arr[0]) ; ++j) {
            new_arr[HashFunc(temp_arr[j])].insertTreeNode(temp_arr[j]);
        }
        delete temp_arr;
    }
    delete arr;
    arr = new_arr;
}

template<class T>
void HashTable<T>::addItem(T *item) {
    AVLStatus status = arr[HashFunc(item)].insertTreeNode(item);
    if (status == AVL_SUCCESS){
        num_itmes++;
        if (num_itmes * 2 >= size){
            this->IncreaseTable();
        }
    }
}

template<class T>
void HashTable<T>::removeItem(T *item) {
    AVLStatus status = arr[HashFunc(item)].insertTreeNode(item);
    if (status == AVL_SUCCESS){
        num_itmes--;
        if (num_itmes * 4 < size && num_itmes > initial_size){
            this->DecreaseTable();
        }
    }
}


#endif //HW1_WET_HASHTABLE_H
