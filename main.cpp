#include "AVLTree.h"
int main(int argc, const char**argv) {
    AVLTree<char> *tree;
    tree = new AVLTree<char>;
    char *c = new char('c');
    tree->insertTreeNode(4, c);

    return 0;
}