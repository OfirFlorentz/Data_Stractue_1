#include <iostream>
#include "Queue.h"
#include "DC.h"
#include "AVLTree.h"
//#include "Node.cpp"

using std::cout;
using std::endl;

int main(){
/*
    DC* a = new DC(1, 10);
    DC* b = new DC(2, 12);
    DC* new_b = new DC(2,12);
    DC* c = new DC(3,12);
    DC* d = new DC(4,16);
    DC* e = new DC(5,16);
    DC* f = new DC(6,7);

    AVLTree<DC>* tree = new AVLTree<DC>();
    //insert shit
    //tree->insertTreeNode(a);

    tree->insertTreeNode(e);
    tree->insertTreeNode(a);
    tree->insertTreeNode(b);
    tree->insertTreeNode(c);
    tree->insertTreeNode(d);
    tree->insertTreeNode(f);


    tree->removeTreeNode(new_b);

    tree->printTree();
    //tree->insertTreeNode(c);

    delete(tree);
*/
    AVLTree<char> *tree;
    tree = new AVLTree<char>;
    char* c = new char('c');
    tree->insertTreeNode(c);
    char* d = new char('d');
    tree->insertTreeNode(d);
    char* f = new char('f');
    tree->insertTreeNode(f);
    //tree->insertTreeNode(new_f);
    char* g = new char('i');
    tree->insertTreeNode(g);
    char* j = new char('h');
    tree->insertTreeNode(j);
    char* k = new char('g');
    tree->insertTreeNode(k);
    char* l = new char('f');
    tree->insertTreeNode(l);
    char* m = new char('e');
    tree->insertTreeNode(m);

    char* new_f = new char('e');
    if(tree->getData(new_f) == NULL){
        cout << "yay" << endl;
    } else {
        cout << "shit" << endl;
    }
    //tree->removeTreeNode(new_f);




    tree->printTree();
    delete tree;

    return 0;
}