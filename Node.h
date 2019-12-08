/**This class is hold id of server and the amount of servers he have from speicfic type**/

#ifndef HW1_WET_NODE_H
#define HW1_WET_NODE_H

#include <iostream>

class DCNode{
    int id;
    int value;
public:
    // constructor
    DCNode (int id, int value);
    // comparing operators overloading
    // comparing is first by value and then by id
    friend bool operator >(const DCNode&, const DCNode&);
    friend bool operator >(DCNode&, DCNode&);
    friend bool operator ==(const DCNode& first, const DCNode& second);
    friend bool operator ==(DCNode& first, DCNode& second);
    int getId() const;
    int getValue() const;
};

bool operator <(const DCNode&, const DCNode&);
bool operator <(DCNode&, DCNode&);

#endif //HW1_WET_NODE_H
