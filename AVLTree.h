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
        int key;
        T* data;
        int height;
        TreeNode* left_child;
        TreeNode* right_child;
    public:
        TreeNode(int id, const T& data);
        ~TreeNode();
        const TreeNode& searchNode(int id) {
            if(key == id){
                return this;
            }
            if (left_child != nullptr){
                return searchNode(id);
            }
            if (right_child != nullptr){
                return searchNode(id);
            }
            return nullptr;
        }

        };
    TreeNode* root;


    const TreeNode& getTreeNode(int id) {
        return root->searchNode(id);
    }
public:
    AVLTree();
    ~AVLTree();
    AVLStatus insertTreeNode(int id, const T& data) const;
    //const TreeNode& getTreeNode(int key);
    };


#endif //HW1_WET_AVLTREE_H
