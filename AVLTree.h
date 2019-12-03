//
// Created by Nathan on 11/25/2019.
//

#ifndef HW1_WET_AVLTREE_H
#define HW1_WET_AVLTREE_H

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
        TreeNode(int id, const T& data):
                key(id), height(height) {
            T* copied_data = T(data);
            this->data = copied_data;
            height = 0;
            left_child = nullptr;
            right_child = nullptr;
        }
        ~TreeNode(){
            delete data;
            delete left_child;
            delete right_child;
        }
        const TreeNode& searchNode(int key_to_find){
            if (left_child != nullptr && key > key_to_find){
                return left_child->searchNode(key_to_find);
            } else if (right_child != nullptr && key < key_to_find) {
                return right_child->searchNode(key_to_find);
            } else {
                return this;
            }
        }
        AVLStatus insertNode(int new_key, T& new_data, const TreeNode& parent, bool is_left) {
            TreeNode &new_node(new_key, new_data);
            if (new_key > key) {
                if (right_child != nullptr) {
                    right_child->insertNode(new_key, new_data, this, false);
                    this->height++;
                } else {
                    this->right_child = new_node;
                }
            } else if (new_key < key) {
                if (left_child != nullptr) {
                    left_child->insertNode(new_key, new_data, this, true);
                    this->height++;
                } else {
                    left_child->right_child = new_node;
                }
            } else if (new_key == key) {
                new_node.height = this->height;
                new_node.left_child = this->left_child;
                new_node.right_child = this->right_child;
                if (is_left) {
                    delete parent.left_child;
                    parent.left_child = new_node;
                } else {
                    delete parent.right_child;
                    parent.right_child = new_node;
                }
                return AVL_SUCESS;
            }
            return AVL_SUCESS;
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
        AVLStatus balanceTree (int target_key, const TreeNode& parent, bool is_left){
            if (target_key > key && right_child != nullptr){
                return right_child->balanceTree(target_key, this, false);
            } else if (target_key < key && left_child != nullptr){
                return left_child->balanceTree(target_key, this, true);
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
        }
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



    AVLTree() = default;
    ~AVLTree(){
        delete root;
    };
    AVLTree(const AVLTree &tree) = default;
    const TreeNode& getParent (const TreeNode& node) {
        return root->getParent(node);
    }
    //AVLTree& operator=(const AVLTree<T> &tree) = default;
    AVLStatus fixTreeBalance(int id){
        return this->root->fixTreeBalance(id);
    };
    AVLStatus insertTreeNode(int id, const T& data){
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
    }

    AVLStatus balanceTree();
    AVLStatus llRotate();
    AVLStatus rlRotate();
    AVLStatus lrRotate();
    AVLStatus rrRotate();


    //const TreeNode& getTreeNode(int key);
    };


#endif //HW1_WET_AVLTREE_H
