#include "AVLTree.h"
int main(int argc, const char**argv) {
    AVLTree<char> *tree;
    tree = new AVLTree<char>;
    char* c = new char('c');
    tree->insertTreeNode(c);
    char* d = new char('d');
    tree->insertTreeNode(d);
/*
    char* a = new char('d');
    tree->insertTreeNode(a);
*/
    char* f = new char('f');
    tree->insertTreeNode(f);
    char* g = new char('g');
    tree->insertTreeNode(g);
    char* j = new char('j');
    tree->insertTreeNode(j);
    char* k = new char('k');
    tree->insertTreeNode(k);
    char* l = new char('l');
    tree->insertTreeNode(l);
    char* m = new char('m');
    tree->insertTreeNode(m);
    tree->printTree();
    delete tree;

    return 0;
}