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
        bool isLeaf();
        
        TreeNode* getLeft() {
            return left_child;
        }

        TreeNode* getRight() {
            return right_child;
        }

        T& getData() {
            return *data;
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
            if ( *data < *new_data) {
                if (right_child != nullptr) {
                    right_child = right_child->insertNode(new_data);
                    return this->balanceTree();
                } else {
                    TreeNode* new_node = new TreeNode(new_data);
                    right_child = new_node;
                    return this->balanceTree();
                }
            } else if (*new_data < *data){
                if (left_child != nullptr){
                    left_child = left_child->insertNode(new_data);
                    return this->balanceTree();
                } else {
                    TreeNode* new_node = new TreeNode(new_data);
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
            if (*data == *target_data){
                if (left_child == nullptr && right_child == nullptr){
                    delete this;
                    return nullptr;
                } else if (right_child == nullptr && left_child != nullptr){
                    TreeNode* next_right = left_child->getRightest();
                    T* next_right_data = next_right->data;
                    next_right->data = this->data;
                    data = next_right_data;
                    left_child = left_child->removeTreeNode(target_data);
                } else if (left_child == nullptr && right_child != nullptr){
                    TreeNode* next_left = right_child->getLeftest();
                    T* next_left_data = next_left->data;
                    next_left->data = this->data;
                    data = next_left_data;
                    right_child = right_child->removeTreeNode(target_data);
                } else if (left_child != nullptr && right_child != nullptr){
                    TreeNode* next_left = right_child->getLeftest();
                    T* next_left_data = next_left->data;
                    next_left->data = this->data;
                    data = next_left_data;
                    right_child = right_child->removeTreeNode(target_data);
                }
            } else if ( *target_data < *data){
                if (left_child != nullptr){
                    left_child = left_child->removeTreeNode(target_data);
                }
            } else if (*data < *target_data){
                if (right_child != nullptr){
                    right_child = right_child->removeTreeNode(target_data);
                }
            }
            return this->balanceTree();
        }

        TreeNode* getLeftest(){
            if (left_child== nullptr){
                return this;
            } else {
                return left_child->getLeftest();
            }
        }

        TreeNode* getRightest(){
            if (right_child== nullptr){
                return this;
            } else {
                return right_child->getLeftest();
            }
        }


        static int getHeight (TreeNode* node){
            if (node == nullptr){
                return -1;
            } else {
                return node->getHeight();
            }
        }

        int getHeight(){
            return this->height;
        }

        static int getBalanceFactor (const TreeNode * node){
            if (node == nullptr){
                return 0;
            } else {
                return getHeight(node->left_child) - getHeight(node->right_child);
            }
        }

        void inorderOutput(){
            if (left_child != nullptr){
                left_child->inorderOutput();
            }
            if (data != nullptr){
                std::cout << *data << "-" << getHeight() << "-";
                if (left_child != nullptr){
                    std::cout << "L:" << left_child->getData() << "-";
                }
                if (right_child != nullptr){
                    std::cout << "R:" << right_child->getData();
                }
                std::cout << std::endl;
            }
            if (right_child != nullptr){
                right_child->inorderOutput();
            }
        }

        T* getData(T* target_data);

        void fillInorderArr(int* i, T** arr);
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
    T** inorderArr();
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
    if (data == nullptr){
        return AVL_NULL_POINTER;
    }
    if (root == nullptr){
        root = new TreeNode(data);
        num_nodes++;
    } else {
        T* old_data = root->getData(data);
        root = root->insertNode(data);
        T* new_data = root->getData(data);
        if (old_data == nullptr && new_data != nullptr){
            num_nodes++;
        }
    }
    return AVL_SUCCESS;
}

template<class T>
AVLStatus AVLTree<T>::removeTreeNode(T *data) {
    if (root == nullptr){
        return NODE_NOT_EXIST;
    } else if (root->getData(data) == nullptr) {
        return NODE_NOT_EXIST;
    } else {
        num_nodes--;
        root = root->removeTreeNode(data);
        return AVL_SUCCESS;
    }
}

template<class T>
bool AVLTree<T>::isExist(T *target_data) {
    if(root == nullptr)
        return false;
    return root->getData(target_data) != nullptr;
}

template<class T>
T *AVLTree<T>::getData(T *target_data) {
    if(root == nullptr)
        return nullptr;
    return root->getData(target_data);
}

template<class T>
void AVLTree<T>::printTree() {
    if (root != nullptr){
        root->inorderOutput();
    }
}

template<class T>
T **AVLTree<T>::inorderArr() {
    if (num_nodes == 0){
        return nullptr;
    }
    T** in_order_arr = new T*[num_nodes];
    int index = 0;
    root->fillInorderArr(&index,in_order_arr);
    return in_order_arr;
}



// Node funcs

template<class T>
AVLTree<T>::TreeNode::TreeNode(T *target_data) {
    data = target_data;
    height = 0;
    left_child = nullptr;
    right_child = nullptr;
}

template<class T>
AVLTree<T>::TreeNode::~TreeNode() {
    delete data;
    if (left_child != nullptr){
        delete left_child;
    }
    if (right_child != nullptr){
        delete right_child;
    }

}

template<class T>
T *AVLTree<T>::TreeNode::getData(T *target_data) {
    if (*data == *target_data){
        return data;
    } else if (*target_data < *data){
        if (left_child != nullptr){
            return left_child->getData(target_data);
        } else {
            return nullptr;
        }
    } else if (*data < *target_data){
        if (right_child != nullptr){
            return right_child->getData(target_data);
        } else {
            return nullptr;
        }
    }
}

template<class T>
bool AVLTree<T>::TreeNode::isLeaf() {
    return right_child == nullptr&& left_child == nullptr;
}

template<class T>
void AVLTree<T>::TreeNode::fillInorderArr(int *i, T **arr) {
    if(left_child != nullptr){
        left_child->fillInorderArr(i,arr);
    }
    arr[*i] = data;
    *i = *i + 1;
    if(right_child != nullptr){
        right_child->fillInorderArr(i,arr);
    }
}

#endif //HW1_WET_AVLTREE_H
