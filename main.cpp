#include <iostream>
#include "DCM.h"
#include <math.h>
#include "HashTable.h"

using std::cout;
using std::endl;



int main() {
    int * a = new int(16);
    int * new_a = new int (16);
    int * b = new int(32);
    int* c = new int(9);
    int * d = new int(10);
    int * e = new int (11);

    HashTable<int> *table = new HashTable<int>;
    table->addItem(a);
    table->addItem(b);
    table->addItem(c);
    table->addItem(d);
    table->addItem(new_a);
    table->removeItem(a);
    table->removeItem(e);


    table->printData();
    cout << table->getNumItmes() << endl;
    cout << table->getSize() << endl;

    delete table;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete new_a;

    return 0;
}
