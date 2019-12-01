//
// Created by Nathan on 11/25/2019.
//

#include "AVLTree.h"

/*template <class T>
AVLTree<T>::TreeNode::TreeNode(int id, const T& data) :
        key(id), height(height) {
    T* copied_data = T(data);
    this->data = copied_data;
    height = 0;
    left_child = nullptr;
    right_child = nullptr;
}*/


/*template <class T>
AVLTree<T>::TreeNode::~TreeNode() {
    delete data;
    delete left_child;
    delete right_child;
}*/

template<class T>
const typename AVLTree<T>::TreeNode &AVLTree<T>::TreeNode::searchNode(int id) {/*
    if(key == id
        || (left_child == nullptr && key>id)
        || (right_child == nullptr && key>id)){
        return this;
    }*/

    if (key > id){
        return left_child->searchNode(id);
    } else if (key < id) {
        return right_child->searchNode(id);
    } else {
        return this;
    }
}

template<class T>
/*
const typename AVLTree<T>::TreeNode &
AVLTree<T>::TreeNode::getParent(const AVLTree::TreeNode &node) {
    if (this->left_child == node || this->right_child == node){
        return this;
    }
    if (this->key > node.key){
        return getParent(node.left_child);
    } else if (this->key > node.key){
        return getParent(node.right_child);
    }
    return nullptr;
}
*/

/*template <class T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <class T>
AVLTree<T>::~AVLTree() {
    //need to scan all tree
    delete root;
}*/
/*

template<class T>
AVLStatus AVLTree<T>::insertTreeNode(int id, const T &data) {
    if(data == nullptr){
        return AVL_NULL_POINTER;
    }
    TreeNode node = new TreeNode(id, data);
    TreeNode parent = root->searchNode(id);
    if (node.key == parent.key){
        node.left_child = parent.left_child;
        node.right_child = parent.right_child;
        TreeNode grand_parent = root->getParent(parent);
        delete parent;
    }
    delete node;
    return AVL_SUCESS;
}

template<class T>
const typename AVLTree<T>::TreeNode &AVLTree<T>::getTreeNode(int id) {
    return root->searchNode(id);
}
*/


/*
template <class T>
AVLStatus AVLTree<T>::insertTreeNode(int key, const T& data) const {
    TreeNode node = new TreeNode(key, data);
    if (node == nullptr) {
        return AVL_OUT_OF_MEMORY;
    }
    node.key = key;
    node.data = T(data);
    return AVL_SUCESS;
}
*/
                          