#include <iostream>
#include "Queue.h"
#include "DC.h"
#include "AVLTree.h"
//#include "Node.cpp"

using std::cout;
using std::endl;

int main(){
    DC* a = new DC(1, 10);
    DC* b = new DC(2, 12);
    DC* c = new DC(3,12);
    DC* d = new DC(4,16);
    DC* e = new DC(5,16);
    DC* f = new DC(6,7);

    AVLTree<DC>* tree = new AVLTree<DC>();
    //insert shit
    //tree->insertTreeNode(a);

    tree->printTree();
    tree->insertTreeNode(e);
    tree->insertTreeNode(a);
    tree->insertTreeNode(b);
    tree->insertTreeNode(c);
    tree->insertTreeNode(d);
    tree->insertTreeNode(f);

    tree->printTree();
    //tree->insertTreeNode(c);

    delete(tree);
    return 0;
}