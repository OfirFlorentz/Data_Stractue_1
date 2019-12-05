#include <iostream>
#include "DCM.h"
#include <math.h>

using std::cout;
using std::endl;



int main() {
    char *values[] = {"SUCCESS", "FAILURE", "ALLOCATION_ERROR", "INVALID_INPUT" };

    /*
    DC d(1, 10);
    try {
        cout << "num of windows " << d.numOfWindows() << endl;
        cout << d.requestServer(3, 1) << endl;
        cout << d.requestServer(0, 1) << en0dl;
        d.freeServer(3);
        d.freeServer(0);
        cout << "num of windows " << d.numOfWindows() << endl;
        cout << d.requestServer(0, 0) << endl;
        cout << "num of windows " << d.numOfWindows() << endl;
        cout << d.requestServer(0, 1) << endl;
        cout << d.requestServer(0, 1) << endl;
        cout << d.requestServer(0, 1) << endl;
        cout << d.requestServer(0, 1) << endl;
        cout << d.requestServer(0, 1) << endl;
        cout << d.requestServer(0, 1) << endl;
        cout << d.requestServer(0, 1) << endl;
        cout << d.requestServer(0, 1) << endl;
        cout << d.requestServer(0, 1) << endl;
        cout << "num of windows " << d.numOfWindows() << endl;
        d.freeServer(8);
        cout << d.requestServer(0, 1) << endl;
        d.freeServer(55);
        cout << d.requestServer(0, 1) << endl;
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    */
/*    DCM* ptr = new DCM;
    DCM& dcm = *ptr;
    int x;
    int* arr;
    cout << values[dcm.addDataCenter(7, 2)] << endl;
    cout << values[dcm.addDataCenter(8, 2)] << endl;
    cout << values[dcm.addDataCenter(9, 1)] << endl;
    cout << values[dcm.addDataCenter(10, 2)] << endl;
    cout << values[dcm.addDataCenter(11, 1)] << endl;
    cout << values[dcm.removeDataCenter(7)] << endl;
    cout << values[abs(dcm.requestServer(7, 0, 1, &x))] << endl;
    cout << values[abs(dcm.requestServer(7, -1, 1, &x))] << endl;
    cout << values[abs(dcm.requestServer(11, 0, 1, &x))] << endl;
    cout << values[dcm.removeDataCenter(11)] << endl;
    cout << "counter is" << dcm.getCounter() << endl;


    dcm.GetDataCentersByOS(1, &arr, &x);

    for(int i = 0; i < x; i++)
        cout << arr[i] << endl;*/


    DCM * dcm1 = new DCM();
    dcm1->addDataCenter(10,51);
    dcm1->addDataCenter(11,299);
    dcm1->addDataCenter(8,231);
    dcm1->addDataCenter(9,231);
    dcm1->addDataCenter(6,231);

    dcm1->removeDataCenter(6);
    //cout << dcm1->removeDataCenter(7) << endl;

    //dcm1->addDataCenter(9,23);
    //cout << dcm1->removeDataCenter(7) << endl;

    int  num;
    int * datacenters;

    dcm1->GetDataCentersByOS(0,&datacenters,&num);

    for (int i = 0; i < num ; ++i) {
        cout << i << ": " << datacenters[i]  << endl;
    }


    int * a = new int(6);
    int * new_a = new int (6);

    int * b = new int(8);
    //char* new_b = new char('b');
    int* c = new int(9);
    int * d = new int(10);

    int * e = new int (11);

    //char* new_c = new char('c');


    AVLTree<int >* tree = new AVLTree<int >();
    //insert shit
    //tree->insertTreeNode(a);

    //tree->insertTreeNode(e);
    tree->insertTreeNode(d);
    tree->insertTreeNode(e);
    tree->insertTreeNode(b);
    tree->insertTreeNode(c);
    tree->insertTreeNode(a);

    //tree->insertTreeNode(d);
    //tree->insertTreeNode(f);


    tree->removeTreeNode(new_a);
    //tree->removeTreeNode(new_b);
    //tree->removeTreeNode(new_c);

    //tree->insertTreeNode(new_c);



    tree->printTree();
    //tree->insertTreeNode(c);

    cout << tree->getNumNodes() << endl;

    int ** arr = tree->inorderArr();

    for (int i = 0; i < tree->getNumNodes() ; ++i) {
        cout << *arr[i] << ",";
    }

    delete arr;

    delete tree;



    /*
    cout << "remove " << values[dcm.removeDataCenter(8)] << endl;
    cout << "remove " << values[dcm.removeDataCenter(8)] << endl;
    cout << values[dcm.requestServer(8,0,1, &x)] << " x is: " << x <<  endl;
    cout << values[dcm.requestServer(5,0,1, &x)] << " x is: " << x <<  endl;
    cout << "free" << values[dcm.freeServer(5,0)] << x <<  endl ;
    cout << values[dcm.requestServer(5,3,0, &x)] << " x is: " << x <<  endl;
    cout << values[dcm.requestServer(5,3,0, &x)] << " x is: " << x <<  endl;
    cout << values[dcm.requestServer(5,3,0, &x)] << " x is: " << x <<  endl;
    cout << values[dcm.requestServer(5,3,0, &x)] << " x is: " << x <<  endl;
    cout << values[dcm.requestServer(5,3,0, &x)] << " x is: " << x <<  endl;
     */
    //delete ptr;
    return 0;
}
