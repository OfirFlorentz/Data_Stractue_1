#include <iostream>
#include "DCM.h"

using std::cout;
using std::endl;


int main() {
    char *values[] = {"INVALID_INPUT", "FAILURE", "SUCCESS"};

    /*
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

    */
    DCM dcm;
    int x;
    cout << values[dcm.addDataCenter(5, 4)] << endl;
    cout << values[dcm.addDataCenter(5, 2)] << endl;
    cout << values[dcm.addDataCenter(8, 2)] << endl;
    cout << values[dcm.requestServer(5,0,1, &x)] << " x is: " << x <<  endl;
    cout << values[dcm.freeServer(5,0)] << x <<  endl;
    cout << values[dcm.requestServer(5,3,0, &x)] << " x is: " << x <<  endl;
    cout << values[dcm.requestServer(5,3,0, &x)] << " x is: " << x <<  endl;
    cout << values[dcm.requestServer(5,3,0, &x)] << " x is: " << x <<  endl;
    cout << values[dcm.requestServer(5,3,0, &x)] << " x is: " << x <<  endl;
    cout << values[dcm.requestServer(5,3,0, &x)] << " x is: " << x <<  endl;
    return 0;
}
