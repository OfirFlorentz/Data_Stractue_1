#include <iostream>
#include "Queue.h"
#include "DC.h"
#include "AVLTree.h"
//#include "Node.cpp"

using std::cout;
using std::endl;

int main(){
/*    DC* a = new DC(1, 10);
    DC* b = new DC(2, 12);
    DC* new_b = new DC(2,12);
    DC* c = new DC(3,12);
    DC* new_c = new DC(3,14);
    DC* d = new DC(4,16);
    DC* e = new DC(5,16);
    DC* f = new DC(6,7);*/

    char* a = new char('a');
    //char* new_a = new char('a');

    char* b = new char('b');
    //char* new_b = new char('b');
    char* c = new char('c');
    //char* new_c = new char('c');


    AVLTree<char >* tree = new AVLTree<char >();
    //insert shit
    //tree->insertTreeNode(a);

    //tree->insertTreeNode(e);
    tree->insertTreeNode(a);
    tree->insertTreeNode(b);
    tree->insertTreeNode(c);
    //tree->insertTreeNode(d);
    //tree->insertTreeNode(f);


    //tree->removeTreeNode(new_a);
    //tree->removeTreeNode(new_b);
    //tree->removeTreeNode(new_c);

    //tree->insertTreeNode(new_c);



    tree->printTree();
    //tree->insertTreeNode(c);

    cout << tree->getNumNodes() << endl;

    char** arr = tree->inorderArr();

    for (int i = 0; i < tree->getNumNodes() ; ++i) {
        cout << *arr[i] << ",";
    }

    delete arr;

    delete tree;


    return 0;
}