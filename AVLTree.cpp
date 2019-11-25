//
// Created by Nathan on 11/25/2019.
//

#include "AVLTree.h"

template <class T>
AVLTree<T>::TreeNode::TreeNode(int id, const T& data) :
        id(id), height(height) {
    T* copied_data = T(data);
    this->data = copied_data;
    height = 0;
    left_child = nullptr;
    right_child = nullptr;
}

template <class T>
AVLTree<T>::TreeNode::~TreeNode() {
    delete data;
    delete left_child;
    delete right_child;
}

template <class T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <class T>
AVLTree<T>::~AVLTree() {
    //need to scan all tree
    delete root;
}

/*
template <class T>
AVLStatus AVLTree<T>::insertTreeNode(int id, const T& data) const {
    TreeNode node = new TreeNode(id, data);
    if (node == nullptr) {
        return AVL_OUT_OF_MEMORY;
    }
    node.id = id;
    node.data = T(data);
    return AVL_SUCESS;
}*/
