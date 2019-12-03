//
// Created by ofir on 26/11/2019.
//

#ifndef HW1_WET_NODE_H
#define HW1_WET_NODE_H

#include <iostream>
#include "AVLTree.h"

class ValueNode;
class DCNode;

class DCNode{
    int id;
    int value;
public:
    DCNode (int id, int value);
    friend bool operator >(const DCNode&, const DCNode&);
    friend bool operator ==(const DCNode& first, const DCNode& second);
    int getId() const;
    int getValue() const;
};

#endif //HW1_WET_NODE_H
