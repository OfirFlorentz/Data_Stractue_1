#include <iostream>
#include "Queue.h"
#include "DC.h"
//#include "Node.cpp"

using std::cout;
using std::endl;

int main(){
    DC d(1, 10);
    try {
        cout << "num of windows " << d.numOfWindows() << endl;
        cout << d.requestServer(3, 1) << endl;
        cout << d.requestServer(0, 1) << endl;
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
    return 0;
}