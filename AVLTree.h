//
// Created by Nathan on 11/25/2019.
//

#ifndef HW1_WET_AVLTREE_H
#define HW1_WET_AVLTREE_H

enum AVLStatus {
    AVL_SUCESS,
    AVL_OUT_OF_MEMORY
};

template <class T>
class AVLTree {
    class TreeNode{
        int id;
        T* data;
        int height;
        TreeNode* left_child;
        TreeNode* right_child;
    public:
        TreeNode(int id, const T& data);
        ~TreeNode();
    };
    TreeNode* root;
public:
    AVLTree();
    ~AVLTree();
    AVLStatus insertTreeNode(int id, const T& data) const;
    };


#endif //HW1_WET_AVLTREE_H
