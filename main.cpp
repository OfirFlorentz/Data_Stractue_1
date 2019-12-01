#include "AVLTree.h"
int main(int argc, const char**argv) {
    AVLTree<char> *tree;
    tree = new AVLTree<char>;
    char c = 'c';
    tree->insertTreeNode(c);
    tree->insertTreeNode('b');
    tree->insertTreeNode('e');
    tree->insertTreeNode('h');
    tree->insertTreeNode('a');
    tree->printTree();
    delete tree;

    return 0;
}