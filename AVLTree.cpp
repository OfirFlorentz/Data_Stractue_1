//
// Created by Nathan on 11/25/2019.
//

#include "AVLTree.h"

template <class T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <class T>
AVLTree<T>::~AVLTree() {
    delete root;
}

template <class T>
AVLTree<T>::TreeNode::TreeNode(int id, const T& data, int height) :
    id(id), height(height) {
    T* copied_data = T(data);
    data = copied_data;
}

