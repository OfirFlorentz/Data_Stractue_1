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

    AVLTree<DC>* tree = new AVLTree<DC>();
    //insert shit
    tree->insertTreeNode(a);

    tree->printTree();
    //tree->insertTreeNode(d);
    //tree->insertTreeNode(c);

    delete(tree);
    return 0;
}