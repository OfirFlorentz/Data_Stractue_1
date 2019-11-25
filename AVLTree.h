//
// Created by Nathan on 11/25/2019.
//

#ifndef HW1_WET_AVLTREE_H
#define HW1_WET_AVLTREE_H

template <class T>
class AVLTree {
    class TreeNode{
        int id;
        T* data;
        int height;
        TreeNode* left_child;
        TreeNode* right_child;
    public:
        TreeNode(int id, const T& data, int height = 0);
        ~TreeNode() = default;
    };
    TreeNode* root;
public:
    AVLTree();
    ~AVLTree();
    TreeNode* insertTreeNode(int id, T* data) const;
    };


#endif //HW1_WET_AVLTREE_H
