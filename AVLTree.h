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
            std::cout << "llRotate" << std::endl;
            TreeNode* node = this->left_child;
            this->left_child = this->left_child->right_child;
            node->right_child = this;
            return node;
        }
        TreeNode* rrRotate(){
            std::cout << "rrRotate" << std::endl;
            std::cout << this->height << std::endl;
            TreeNode* node = this->right_child;
            this->right_child = this->right_child->left_child;
            node->left_child = this;
            return node;
        }
        TreeNode* rlRotate(){
            std::cout << "rlRotate" << std::endl;
            this->right_child = this->right_child->llRotate();
            TreeNode* node = this->rrRotate();
            return node;
        }
        TreeNode* lrRotate(){
            std::cout << "lrRotate" << std::endl;
            this->left_child = this->left_child->rrRotate();
            TreeNode* node = this->llRotate();
            return node;
        }

        TreeNode* balanceTree (){
            this->height = max(getHeight(right_child),getHeight(left_child))+1;
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
            if (*new_data > *data) {
                if (right_child != NULL) {
                    right_child = right_child->insertNode(new_data);
                    return this->balanceTree();
                } else {
                    right_child = new_node;
                    return this;
                }
            } else if (*new_data < *data){
                if (left_child != NULL){
                    left_child = left_child->insertNode(new_data);
                    return this->balanceTree();
                } else {
                    left_child = new_node;
                    return this;
                }
            } else if (*new_data == *data){
                delete this->data;
                this->data = new_data;
                return this;
            }

        }

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

        static int getBalanceFactor (const TreeNode * node){
            if (node == NULL){
                return 0;
            } else {
                return getHeight(node->left_child) - getHeight(node->right_child);
            }
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

    AVLStatus insertTreeNode(T* data){
        if (data == NULL){
            return AVL_NULL_POINTER;
        }
        if (root == NULL){
            root = new TreeNode(data);
        } else {
            root = root->insertNode(data);
        }
    }

    void printTree(){
        if (root != NULL){
            root->inorderOutput();
        }
    }

    };


#endif //HW1_WET_AVLTREE_H
