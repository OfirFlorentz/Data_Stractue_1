#include <iostream>
#include "DCM.h"
#include <math.h>
#include "HashTable.h"

using std::cout;
using std::endl;



int main() {
    int * a = new int(6);
    int * new_a = new int (6);
    int * b = new int(8);
    int* c = new int(9);
    int * d = new int(10);
    int * e = new int (11);

    HashTable<int> *table = new HashTable<int>;
    table->addItem(a);
    table->addItem(b);
    table->addItem(c);
    table->addItem(d);
    table->addItem(e);
    delete table;
    return 0;
}
