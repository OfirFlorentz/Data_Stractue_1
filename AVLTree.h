//
// Created by Nathan on 11/25/2019.
//

#ifndef HW1_WET_AVLTREE_H
#define HW1_WET_AVLTREE_H

#include "algorithm"
#include "iostream"
using namespace std;


enum AVLStatus {
    AVL_SUCCESS,
    AVL_OUT_OF_MEMORY,
    AVL_NULL_POINTER,
    NODE_NOT_EXIST,
    NODE_ALREADY_EXIST
};

template <class T>
class AVLTree {




    class TreeNode{
        T* data;
        int height;
        TreeNode* left_child;
        TreeNode* right_child;
    public:
        explicit TreeNode(T* target_data);
        ~TreeNode();

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
            node->right_child->height =
                    max(getHeight(node->right_child->left_child),
                            getHeight(node->right_child->right_child)) + 1;
            node->height =
                    max(getHeight(node->left_child),
                            getHeight(node->right_child)) + 1;
            return node;
        }
        TreeNode* rrRotate(){
            TreeNode* node = this->right_child;
            this->right_child = this->right_child->left_child;
            node->left_child = this;
            node->left_child->height =
                    max(getHeight(node->left_child->left_child),
                            getHeight(node->left_child->right_child)) + 1;
            node->height =
                    max(getHeight(node->left_child),
                            getHeight(node->right_child)) + 1;
            return node;
        }
        TreeNode* rlRotate(){
            this->right_child = this->right_child->llRotate();
            TreeNode* node = this->rrRotate();
            node->height =
                    max(getHeight(node->left_child),
                        getHeight(node->right_child)) + 1;
            return node;
        }
        TreeNode* lrRotate(){
            this->left_child = this->left_child->rrRotate();
            TreeNode* node = this->llRotate();
            node->height =
                    max(getHeight(node->left_child),
                        getHeight(node->right_child)) + 1;
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
            if ( *data < *new_data) {
                if (right_child != NULL) {
                    right_child = right_child->insertNode(new_data);
                    return this->balanceTree();
                } else {
                    right_child = new_node;
                    return this->balanceTree();
                }
            } else if (*new_data < *data){
                if (left_child != NULL){
                    left_child = left_child->insertNode(new_data);
                    return this->balanceTree();
                } else {
                    left_child = new_node;
                    return this->balanceTree();
                }
            } else if (*new_data == *data){
                delete this->data;
                this->data = new_data;
                return this;
            }
        }

        TreeNode* removeTreeNode(T* target_data){
            if (getData(target_data) == NULL){
                return this;
            } else {
                if (*data == *target_data){
                    if (left_child == NULL && right_child == NULL){
                        return NULL;
                    } else if (right_child == NULL && left_child != NULL){
                        data = left_child->data;
                        height = left_child->height;
                        right_child = left_child->right_child;
                        left_child = left_child->left_child;
                    } else if (left_child == NULL && right_child != NULL){
                        data = right_child->data;
                        height = right_child->height;
                        left_child = right_child->left_child;
                        right_child = right_child->right_child;
                    } else if (left_child != NULL && right_child != NULL){
                        TreeNode* next_left = right_child->getLeftest();
                        T* next_left_data = next_left->data;
                        next_left->data = this->data;
                        data = next_left_data;
                        right_child = right_child->removeTreeNode(target_data);
                    }
                } else if ( *target_data < *data){
                    if (left_child != NULL){
                        left_child = left_child->removeTreeNode(target_data);
                    }
                } else if (*data < *target_data){
                    if (right_child != NULL){
                        right_child = right_child->removeTreeNode(target_data);
                    }
                }
                return this->balanceTree();
            }
        }


        TreeNode* getLeftest(){
            if (left_child==NULL){
                return this;
            } else {
                return left_child->getLeftest();
            }
        }




        bool isLeaf(){
            return right_child == NULL && left_child == NULL;
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
                    std::cout << "L:" << left_child->getData() << "-";
                }
                if (right_child != NULL){
                    std::cout << "R:" << right_child->getData();
                }
                std::cout << std::endl;
            }
            if (right_child != NULL){
                right_child->inorderOutput();
            }
        }

        T* getData(T* target_data){
            if (*data == *target_data){
                return data;
            } else if (*target_data < *data){
                if (left_child != NULL){
                    return left_child->getData(data);
                } else {
                    return NULL;
                }
            } else if (*data < *target_data){
                if (right_child != NULL){
                    return right_child->getData(data);
                } else {
                    return NULL;
                }
            }
        }
    };

    TreeNode* root;
    int num_nodes;


public:
    AVLTree();
    ~AVLTree();
    AVLTree(const AVLTree &tree) = default;
    int getNumNodes();
    AVLStatus insertTreeNode(T* data);
    AVLStatus removeTreeNode(T* data);
    bool isExist(T* target_data);
    T* getData(T* target_data);
    void printTree();
    };

template<class T>
AVLTree<T>::AVLTree() {
    root = nullptr;
    num_nodes = 0;
}

template<class T>
AVLTree<T>::~AVLTree() {
    delete root;
}

template<class T>
int AVLTree<T>::getNumNodes() {
    return num_nodes;
}

template<class T>
AVLStatus AVLTree<T>::insertTreeNode(T *data) {
    if (data == NULL){
        return AVL_NULL_POINTER;
    }
    if (root == NULL){
        root = new TreeNode(data);
    } else {
        root = root->insertNode(data);
    }
    return AVL_SUCCESS;
}

template<class T>
AVLStatus AVLTree<T>::removeTreeNode(T *data) {
    if (root == NULL){
        return NODE_NOT_EXIST;
    } else {
        root = root->removeTreeNode(data);
        return AVL_SUCCESS;
    }
}

template<class T>
bool AVLTree<T>::isExist(T *target_data) {
    return root->getData(target_data) != NULL;
}

template<class T>
T *AVLTree<T>::getData(T *target_data) {
    return root->getData(target_data);
}

template<class T>
void AVLTree<T>::printTree() {
    if (root != NULL){
        root->inorderOutput();
    }
}



// Node funcs

template<class T>
AVLTree<T>::TreeNode::TreeNode(T *target_data) {
    data = target_data;
    height = 0;
    left_child = NULL;
    right_child = NULL;
}

template<class T>
AVLTree<T>::TreeNode::~TreeNode() {
    delete data;
    if (left_child != NULL){
        delete left_child;
    }
    if (right_child != NULL){
        delete right_child;
    }
}

#endif //HW1_WET_AVLTREE_H
