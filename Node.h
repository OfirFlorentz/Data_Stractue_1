//
// Created by ofir on 26/11/2019.
//

#ifndef HW1_WET_NODE_H
#define HW1_WET_NODE_H

#include <iostream>
#include "Avl.h"

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


/*
class ServerNode{
    int server_id;
public:
    explicit ServerNode(int server_id, ValueNode* value);
    int getId();
    void valueIncrease();
    void valueDecrease();

    ServerNode* getRight();

    void setRight(ServerNode *server);
    void setLeft(ServerNode *server);
    void setValue(ValueNode *value);
};


class ValueNode{
    ValueNode *up;
    ValueNode *down;
    const int value;
    Avl<DCNode> servers;
    int size;
public:
    explicit ValueNode(int value);
    ValueNode(const ValueNode&)= delete;
    ValueNode& operator=(const ValueNode&)= delete;

    int getSize() const;
    int getValue() const;
    ValueNode* getDown();
    ValueNode* getUp();

    bool isEmpty() const ;
    void setUp(ValueNode *value);
    void setDown(ValueNode *value);
    void addServer(DCNode&);
    void removeServer(DCNode&);

    int* getNodesValue();

};
*/
#endif //HW1_WET_NODE_H
