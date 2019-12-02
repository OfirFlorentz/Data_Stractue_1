//
// Created by Nathan on 11/25/2019.
//

#ifndef HW1_WET_AVLTREE_H
#define HW1_WET_AVLTREE_H

#include "algorithm"
#include "iostream"
using namespace std;


enum AVLStatus {
    AVL_SUCESS,
    AVL_OUT_OF_MEMORY,
    AVL_NULL_POINTER
};

template <class T>
class AVLTree {




    class TreeNode{
        T* data;
        int height;
        TreeNode* left_child;
        TreeNode* right_child;
    public:
        TreeNode(T* target_data){
            data = target_data;
            height = 0;
            left_child = NULL;
            right_child = NULL;
        }
        ~TreeNode(){
            delete data;
            if (left_child != NULL){
                delete left_child;
            }
            if (right_child != NULL){
                delete right_child;
            }
        }

        TreeNode* getLeft() {
            return left_child;
        }
        TreeNode* getRight() {
            return right_child;
        }
        T& getData() {
            return *data;
        }
        void setLeft(TreeNode* node){
            this->left_child = node;
        }
        void setRight(TreeNode* node){
            this->right_child = node;
        }
        void setHeight(int new_height){
            this->height = new_height;
        }



        TreeNode* llRotate(){
            std::cout << "check2" << std::endl;
            TreeNode* node = this->left_child;
            this->left_child = this->left_child->right_child;
            node->right_child = this;
            return node;
        }
        TreeNode* rrRotate(){
            std::cout << "check1" << std::endl;
            std::cout << this->height << std::endl;
            //this->right_child->height = this->height;
            //std::cout << this->right_child->height << std::endl;
            TreeNode* node = this->right_child;
            this->right_child = this->right_child->left_child;
            node->left_child = this;
            return node;
        }
        TreeNode* rlRotate(){
            std::cout << "check3" << std::endl;
            this->right_child = this->right_child->llRotate();
            TreeNode* node = this->rrRotate();
            return node;
        }
        TreeNode* lrRotate(){
            std::cout << "check4" << std::endl;
            this->left_child = this->left_child->rrRotate();
            TreeNode* node = this->llRotate();
            return node;
        }

/*        void balanceTree (TreeNode* parent, bool is_left){
            if (getBalanceFactor(this) == 2 &&
                                    getBalanceFactor(this->left_child) == -1){
                if (is_left){
                    parent->left_child = this->lrRotate();
                } else {
                    parent->right_child = this->lrRotate();
                }
            } else if (getBalanceFactor(this) == 2 &&
                                    getBalanceFactor(this->left_child) >= 0){
                if (is_left){
                    parent->left_child = this->llRotate();
                } else {
                    parent->right_child = this->llRotate();
                }
            } else if (getBalanceFactor(this) == -2 &&
                                    getBalanceFactor(this->right_child) <= 0){
                if (is_left){
                    parent->left_child = this->rrRotate();
                } else {
                    parent->right_child = this->rrRotate();
                }
            } else if (getBalanceFactor(this) == -2 &&
                                    getBalanceFactor(this->right_child) == 1){
                if (is_left){
                    parent->left_child = this->rlRotate();
                } else {
                    parent->right_child = this->rlRotate();
                }
            }
        }*/
        TreeNode* balanceTree (){
            if (getBalanceFactor(this) == 2 &&
                getBalanceFactor(this->left_child) == -1){
                return this->lrRotate();
            } else if (getBalanceFactor(this) == 2 &&
                       getBalanceFactor(this->left_child) >= 0){
                return this->llRotate();
            } else if (getBalanceFactor(this) == -2 &&
                       getBalanceFactor(this->right_child) <= 0) {
                return this->rrRotate();
            } else if (getBalanceFactor(this) == -2 &&
                       getBalanceFactor(this->right_child) == 1){
                return this->rlRotate();
            } else {
                return this;
            }
        }

        TreeNode* insertNode(T* new_data){
            TreeNode* new_node = new TreeNode(new_data);
            if (*new_data > *data){
                if (right_child != NULL){
                    right_child = right_child->insertNode(new_data);
                    this->height = max(getHeight(right_child),getHeight(left_child))+1;
                    return this->balanceTree();
                } else {
                    right_child = new_node;
                    return this;
                }
            }
            if (*new_data < *data){
                if (left_child != NULL){
                    left_child = left_child->insertNode(new_data);
                    this->height = max(getHeight(right_child),getHeight(left_child))+1;
                    return this->balanceTree();
                } else {
                    return new_node;
                }
            }
        }


/*
        void insertNode( T* new_data, TreeNode * parent, bool is_left) {
            TreeNode* new_node = new TreeNode(new_data);
            if (*new_data > getData()) {
                if (right_child != NULL) {
                    right_child->insertNode(new_data, this, false);
                    this->balanceTree(parent, is_left);
                    this->height=std::max(getHeight(this->right_child),getHeight(this->left_child)) + 1;
                } else {
                    this->right_child = new_node;
                }
            } else if (*new_data < getData()) {
                if (left_child != NULL) {
                    left_child->insertNode(new_data, this, true);
                    this->balanceTree(parent, is_left);
                    this->height=std::max(getHeight(this->right_child),getHeight(this->left_child)) + 1;
                } else {
                    this->left_child = new_node;
                }
            } else if (*new_data == getData()) {
                new_node->height = this->height;
                new_node->left_child = this->left_child;
                new_node->right_child = this->right_child;
                if (is_left) {
                    delete parent->getLeft();
                    parent->setLeft(new_node);
                } else {
                    delete parent->getRight();
                    parent->setRight(new_node);
                }
                return;
            }
        }
*/

        static int getHeight (TreeNode* node){
            if (node == NULL){
                return -1;
            } else {
                return node->getHeight();
            }
        }

        int getHeight(){
            return this->height;
        }

        int getBalanceFactor (){
            return getBalanceFactor(this);
        }

        static int getBalanceFactor (const TreeNode * node){
            if (node == NULL){
                return 0;
            } else {
                return getHeight(node->left_child) - getHeight(node->right_child);
            }
        }

        bool isChild (const T& compare_data){
            if (compare_data > data){
                return this->right_child->isChild(compare_data);
            } else if (compare_data < data){
                return this->left_child->isChild(compare_data);
            } else if (compare_data == data){
                return true;
            }
            return false;
        }

        void inorderOutput(){
            if (left_child != NULL){
                left_child->inorderOutput();
            }
            if (data != NULL){
                std::cout << *data << "-" << getHeight() << "-";
                if (left_child != NULL){
                    std::cout << left_child->getData() << "-";
                }
                if (right_child != NULL){
                    std::cout << right_child->getData();
                }
                std::cout << std::endl;
            }
            if (right_child != NULL){
                right_child->inorderOutput();
            }
        }

        void updateHeight(T* target_data){
            if (*target_data < *data && left_child != NULL){
                left_child->updateHeight(target_data);
            }
            if (*target_data > *data && right_child != NULL){
                right_child->updateHeight(target_data);
            }
            height = std::max(getHeight(left_child),getHeight(right_child)) + 1;
        }
    };

    TreeNode* root;
    int num_nodes;


public:



    AVLTree(){
        root = nullptr;
        num_nodes = 0;
    }
    ~AVLTree(){
        delete root;
    };
    AVLTree(const AVLTree &tree) = default;

    int getNumNodes(){
        return num_nodes;
    }


    void balanceRoot (){
        if (root->getBalanceFactor() == 2 &&
                    this->root->getLeft()->getBalanceFactor() == -1){
            this->root = root->lrRotate();
        } else if (root->getBalanceFactor() == 2 &&
                   this->root->getLeft()->getBalanceFactor() >= 0){
            this->root = root->llRotate();
        } else if (root->getBalanceFactor() == -2 &&
                   this->root->getRight()->getBalanceFactor() <= 0){
            this->root = root->rrRotate();
        } else if (root->getBalanceFactor() == -2 &&
                   this->root->getRight()->getBalanceFactor() == 1){
            this->root = root->rlRotate();
        }
    }

    AVLStatus insertTreeNode(T* data){
        if (data == NULL){
            return AVL_NULL_POINTER;
        }
        if (root == NULL){
            root = new TreeNode(data);
        } else{
            root = root->insertNode(data);
        }
    }

/*
    AVLStatus insertTreeNode(T* data){
        if(!data){
            return AVL_NULL_POINTER;
        }
        TreeNode* node;
        if (root == NULL){
            root = new TreeNode(data);
        }
        else if (*data == root->getData()){
            node = new TreeNode(data);
            node->setLeft(root->getLeft());
            node->setRight(root->getRight());
            node->setHeight(root->getHeight());
            delete root;
            root = node;
        } else if (*data < root->getData()){
            if ( root->getLeft() != NULL ){
                root->getLeft()->insertNode(data, root, true);
                this->balanceRoot();
            } else {
                node = new TreeNode(data);
                root->setLeft(node);
            }
        } else if (*data > root->getData()){
            if ( root->getRight() != NULL ){
                root->getRight()->insertNode(data, root, false);
                this->balanceRoot();
            } else {
                node = new TreeNode(data);
                root->setRight(node);
            }
        }
        root->updateHeight(data);
        if (root->getRight() == NULL && root->getLeft() == NULL){
            root->setHeight(0);
        } else if (root->getRight() == NULL && root->getLeft() != NULL){
            root->setHeight(root->getLeft()->getHeight() + 1);
        } else if (root->getLeft() == NULL && root->getRight() != NULL){
            root->setHeight(root->getRight()->getHeight() + 1);
        } else {
            root->setHeight(std::max(root->getRight()->getHeight(),root->getLeft()->getHeight())+1);
        }
        return AVL_SUCESS;
    }
*/

    void printTree(){
        if (root != NULL){
            root->inorderOutput();
        }
    }



    };


#endif //HW1_WET_AVLTREE_H
