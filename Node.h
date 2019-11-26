//
// Created by ofir on 26/11/2019.
//

#ifndef HW1_WET_NODE_H
#define HW1_WET_NODE_H

#include <iostream>

class ValueNode;
class SeverNode;

class ServerNode{
    ServerNode *right;
    ServerNode *left;
    ValueNode *value;
    int server_id;
public:
    explicit ServerNode(int server_id, ValueNode* value);
    int getId();
    void valueIncrease();
    void valueDecrease();

    void setRight(ServerNode *server);
    void setLeft(ServerNode *server);
    void setValue(ValueNode *value);
};

class ValueNode{
    ValueNode *up;
    ValueNode *down;
    ServerNode *first_server;
    const int value;
public:
    explicit ValueNode(int value);
    ~ValueNode();
    ValueNode(const ValueNode&)= delete;
    ValueNode& operator=(const ValueNode&)= delete;

    int getValue() const;
    bool isEmpty() const ;

    ValueNode* getUp();
    ValueNode* getDown();
    void setUp(ValueNode *value);
    void setDown(ValueNode *value);

    void addServer(ServerNode&);

};
#endif //HW1_WET_NODE_H
