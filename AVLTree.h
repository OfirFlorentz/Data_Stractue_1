//
// Created by Nathan on 11/25/2019.
//

#ifndef HW1_WET_AVLTREE_H
#define HW1_WET_AVLTREE_H

#include "algorithm"

enum AVLStatus {
    AVL_SUCESS,
    AVL_OUT_OF_MEMORY,
    AVL_NULL_POINTER
};

template <class T>
class AVLTree {




    class TreeNode{
        int key;
        T* data;
        int height;
        TreeNode* left_child;
        TreeNode* right_child;
    public:
        TreeNode(int target_key, const T* target_data):
                key(target_key) {
            data = new T(*target_data);
            height = 0;
            left_child = nullptr;
            right_child = nullptr;
        }
        ~TreeNode(){
            delete data;
            delete left_child;
            delete right_child;
        }
/*        const TreeNode& searchNode(int key_to_find){
            if (left_child != nullptr && key > key_to_find){
                return left_child->searchNode(key_to_find);
            } else if (right_child != nullptr && key < key_to_find) {
                return right_child->searchNode(key_to_find);
            } else {
                return this;
            }
        }*/
        TreeNode* getLeft() {
            return left_child;
        }

        TreeNode* getRight() {
            return right_child;
        }

        T& getData() const {
            return data;
        }

        int getKey(){
            return key;
        }

        void setLeft(const TreeNode* node){
            this->left_child = node;
        }

        void setRight(const TreeNode* node){
            this->right_child = node;
        }

        void setHeight(int new_height){
            this->height = new_height;
        }



        const TreeNode& llRotate(){
            TreeNode& node = this->left_child;
            this->left_child = this->left_child->right_child;
            node.right_child = this;
            return node;
        }
        const TreeNode& rrRotate(){
            TreeNode& node = this->right_child;
            this->right_child = this->right_child->left_child;
            node.left_child = this;
            return node;
        }
        const TreeNode& rlRotate(){
            this->right_child = this->right_child->llRotate();
            TreeNode& node = this->rrRotate();
            return node;
        }
        const TreeNode& lrRotate(){
            this->left_child = this->left_child->rrRotate();
            TreeNode& node = this->llRotate();
            return node;
        }
        void balanceTree (const TreeNode& parent, bool is_left){
            if (getBalanceFactor(this) == 2 &&
                                    getBalanceFactor(this->left_child == -1)){
                if (is_left){
                    parent.left_child = this->lrRotate();
                } else {
                    parent.right_child = this->lrRotate();
                }
            } else if (getBalanceFactor(this) == 2 &&
                                    getBalanceFactor(this->left_child >= 0)){
                if (is_left){
                    parent.left_child = this->llRotate();
                } else {
                    parent.right_child = this->llRotate();
                }
            } else if (getBalanceFactor(this) == -2 &&
                                    getBalanceFactor(this->right_child <= 0)){
                if (is_left){
                    parent.left_child = this->rrRotate();
                } else {
                    parent.right_child = this->rrRotate();
                }
            } else if (getBalanceFactor(this) == -2 &&
                                    getBalanceFactor(this->right_child == 1)){
                if (is_left){
                    parent.left_child = this->rlRotate();
                } else {
                    parent.right_child = this->rlRotate();
                }
            }
        }


        void insertNode(int new_key, const T* new_data, const TreeNode* parent, bool is_left) {
            TreeNode &new_node(new_key, new_data);
            if (new_key > key) {
                if (right_child != nullptr) {
                    right_child->insertNode(new_key, new_data, this, false);
                    this->balanceTree(parent, is_left);
                    this->height=std::max(getHeight(this->right_child),getHeight(this->left_child)) + 1;
                } else {
                    this->right_child = new_node;
                }
            } else if (new_key < key) {
                if (left_child != nullptr) {
                    left_child->insertNode(new_key, new_data, this, true);
                    this->balanceTree(parent, is_left);
                    this->height=std::max(getHeight(this->right_child),getHeight(this->left_child)) + 1;
                } else {
                    left_child->right_child = new_node;
                }
            } else if (new_key == key) {
                new_node.height = this->height;
                new_node.left_child = this->left_child;
                new_node.right_child = this->right_child;
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


/*
        void balanceTree (int target_key, const TreeNode& parent, bool is_left){
            if (target_key > key && right_child != nullptr){
                right_child->balanceTree(target_key, this, false);
            } else if (target_key < key && left_child != nullptr){
                left_child->balanceTree(target_key, this, true);
            }
            if (getBalanceFactor(this) == 2 && getBalanceFactor(this->left_child == -1)){
                if (is_left){
                    parent.left_child = this->lrRotate();
                } else {
                    parent.right_child = this->lrRotate();
                }
            } else if (getBalanceFactor(this) == 2 && getBalanceFactor(this->left_child >= 0)){
                if (is_left){
                    parent.left_child = this->llRotate();
                } else {
                    parent.right_child = this->llRotate();
                }
            } else if (getBalanceFactor(this) == -2 && getBalanceFactor(this->right_child <= 0)){
                if (is_left){
                    parent.left_child = this->rrRotate();
                } else {
                    parent.right_child = this->rrRotate();
                }
            } else if (getBalanceFactor(this) == -2 && getBalanceFactor(this->right_child == 1)){
                if (is_left){
                    parent.left_child = this->rlRotate();
                } else {
                    parent.right_child = this->rlRotate();
                }
            }
            this->height=std::max(getHeight(left_child),getHeight(right_child));
        }
*/
/*        const TreeNode& getParent (const TreeNode& node) {
            if (node == nullptr){
                return nullptr;
            }
            if (this->left_child == node || this->right_child == node){
                return this;
            }
            if (this->key > node.key){
                return this->left_child->getParent(node);
            } else if (this->key > node.key){
                return this->right_child->getParent(node);
            } else {
                return nullptr;
            }
        }*/
        static int getHeight (const TreeNode& node){
            if (node == nullptr){
                return -1;
            } else {
                return node.height;
            }
        }

        int getHeight(){
            return this->height;
        }

        static int getBalanceFactor (const TreeNode node){
            if (node == nullptr){
                return 0;
            } else {
                return getHeight(node.left_child) - getHeight(node.right_child);
            }
        }
/*        AVLStatus fixTreeBalance (int id){
            if(this->key > id){
                return this->left_child->fixTreeBalance();
            } else if (this->key < id){
                return  this->right_child->fixTreeBalance();
            }
            if (getBalanceFactor(this) == 2){
                if (getBalanceFactor(this->left_child) >= 0){
                    //DO LL

                } else if (getBalanceFactor(this->left_child) == -1){
                    //DO LR
                }
            }
            else if (getBalanceFactor(this) == -2){
                if (getBalanceFactor(this->right_child) <= 0){
                    //DO RR
                } else if (getBalanceFactor(this->right_child) == 1){
                    //DO RL
                }
            }

        }*/
    };




    const TreeNode& getTreeNode(int id){
        return root->searchNode(id);
    }
    TreeNode* root;


public:



    AVLTree(){
        root = nullptr;
    }
    ~AVLTree(){
        delete root;
    };
    AVLTree(const AVLTree &tree) = default;
/*
    const TreeNode& getParent (const TreeNode& node) {
        return root->getParent(node);
    }
*/
    //AVLTree& operator=(const AVLTree<T> &tree) = default;
/*    AVLStatus fixTreeBalance(int id){
        return this->root->fixTreeBalance(id);
    };*/
/*    AVLStatus insertTreeNode(int id, const T& data){
        if(data == nullptr){
            return AVL_NULL_POINTER;
        }
        TreeNode node = new TreeNode(id, data);
        TreeNode parent = root->searchNode(id);
        if (node.key == parent.key) {
            node.left_child = parent.left_child;
            node.right_child = parent.right_child;
            node.height = parent.height;
            TreeNode temp = parent;
            parent = node;
            delete temp;
        } else if (node.key > parent.key){
            parent.right_child = node;
        } else if (node.key < parent.key){
            parent.left_child = node;
        }
        delete node;
        return AVL_SUCESS;
    }*/

    AVLStatus insertTreeNode(int key, const T* data){
        if(data == nullptr){
            return AVL_NULL_POINTER;
        }
        TreeNode* node;
        if (key == root->getKey() || root == nullptr){
            node = new TreeNode(key, data);
            node->setLeft(root->getLeft());
            node->setRight(root->getRight());
            node->setHeight(root->getHeight());
            delete root;
            root = node;
        } else if (key < root->getKey()){
            if ( root->getLeft() != nullptr ){
                root->getLeft()->insertNode(key, data, root, true);
            } else {
                node = new TreeNode(key, data);
                root->setLeft(node);
                delete node;
            }
        } else if (key > root->getKey() && root->getRight() != nullptr){
            if ( root->getLeft() != nullptr ){
                root->getRight().insertNode(key, data, root, false);
            } else {
                node = new TreeNode(key, data);
                root->setRight(node);
                delete node;
            }
        }
        return AVL_SUCESS;
    }


    AVLStatus balanceTree();
    AVLStatus llRotate();
    AVLStatus rlRotate();
    AVLStatus lrRotate();
    AVLStatus rrRotate();


    //const TreeNode& getTreeNode(int key);
    };


#endif //HW1_WET_AVLTREE_H
