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
    DCM* ptr = new DCM;
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
        cout << arr[i] << endl;
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
    delete ptr;
    return 0;
}
