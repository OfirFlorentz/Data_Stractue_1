//
// Created by Nathan on 11/25/2019.
//

#ifndef HW1_WET_AVLTREE_H
#define HW1_WET_AVLTREE_H

#include "algorithm"
#include "iostream"

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
        TreeNode(const T& target_data){
            data = new T(target_data);
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
            TreeNode* node = this->left_child;
            this->left_child = this->left_child->right_child;
            node->right_child = this;
            return node;
        }
        TreeNode* rrRotate(){
            TreeNode* node = this->right_child;
            this->right_child = this->right_child->left_child;
            node->left_child = this;
            return node;
        }
        TreeNode* rlRotate(){
            this->right_child = this->right_child->llRotate();
            TreeNode* node = this->rrRotate();
            return node;
        }
        TreeNode* lrRotate(){
            this->left_child = this->left_child->rrRotate();
            TreeNode* node = this->llRotate();
            return node;
        }

        void balanceTree (TreeNode* parent, bool is_left){
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
        }


        void insertNode(const T& new_data, TreeNode * parent, bool is_left) {
            TreeNode* new_node = new TreeNode(new_data);
            if (new_data > getData()) {
                if (right_child != nullptr) {
                    right_child->insertNode(new_data, this, false);
                    this->balanceTree(parent, is_left);
                    this->height=std::max(getHeight(this->right_child),getHeight(this->left_child)) + 1;
                } else {
                    this->right_child = new_node;
                }
            } else if (new_data < getData()) {
                if (left_child != nullptr) {
                    left_child->insertNode(new_data, this, true);
                    this->balanceTree(parent, is_left);
                    this->height=std::max(getHeight(this->right_child),getHeight(this->left_child)) + 1;
                } else {
                    left_child->right_child = new_node;
                }
            } else if (new_data == getData()) {
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
                std::cout << *data << "," << std::endl;
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

    AVLStatus insertTreeNode(const T& data){
        if(!data){
            return AVL_NULL_POINTER;
        }
        TreeNode* node;
        if (root == NULL){
            root = new TreeNode(data);
        }
        else if (data == root->getData()){
            node = new TreeNode(data);
            node->setLeft(root->getLeft());
            node->setRight(root->getRight());
            node->setHeight(root->getHeight());
            delete root;
            root = node;
        } else if (data < root->getData()){
            if ( root->getLeft() != NULL ){
                root->getLeft()->insertNode(data, root, true);
            } else {
                node = new TreeNode(data);
                root->setLeft(node);
                delete node;
            }
        } else if (data > root->getData()){
            if ( root->getRight() != NULL ){
                root->getRight()->insertNode(data, root, false);
            } else {
                node = new TreeNode(data);
                root->setRight(node);
                //delete node;
            }
        }
        return AVL_SUCESS;
    }

    void printTree(){
        //std::cout << "hello";
        if (root != NULL){
            root->inorderOutput();
        }
    }



    AVLStatus balanceTree();
    AVLStatus llRotate();
    AVLStatus rlRotate();
    AVLStatus lrRotate();
    AVLStatus rrRotate();


    //const TreeNode& getTreeNode(int key);
    };


#endif //HW1_WET_AVLTREE_H
