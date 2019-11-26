//
// Created by ofir on 26/11/2019.
//

#include "Node.h"
#include <iostream>

ServerNode:: ServerNode(int server_id, ValueNode* value):server_id(server_id), value(value) {
    left = nullptr;
    right = nullptr;
};

int ServerNode::getId() {
    return server_id;
}

void ServerNode::valueIncrease() {
    if (left != nullptr)
        left->setRight(right);
    if (right != nullptr)
        right->setLeft(left);
    int cur_value = value->getValue();
    ValueNode* old = value;
    if (cur_value + 1 == value->getUp()->getValue()) {
        value = value->getUp();
    } else {
        ValueNode* new_node = new ValueNode(cur_value + 1);
        new_node->setUp(value->getUp());
        new_node->setDown(value);
        value->setUp(new_node);
        value = new_node;
    }
    value->addServer(*this);
    if(old->isEmpty())
        delete old;
}

void ServerNode::valueDecrease() {
    if (left != nullptr)
        left->setRight(right);
    if (right != nullptr)
        right->setLeft(left);
    int cur_value = value->getValue();
    ValueNode* old = value;
    if (cur_value -1  == value->getDown()->getValue()) {
        value = value->getUp();
    } else {
        ValueNode* new_node = new ValueNode(cur_value - 1);
        new_node->setDown(value->getDown());
        new_node->setUp(value);
        value->setDown(new_node);
        value = new_node;
    }
    value->addServer(*this);
    if(old->isEmpty())
        delete old;
}


void ServerNode::setRight(ServerNode *server){
    right = server;
}

void ServerNode::setLeft(ServerNode *server){
    left = server;
}

void ServerNode::setValue(ValueNode *val){
    value = val;
}

//end of Server Node Function
//start of Value Node function

ValueNode::ValueNode(int value): value(value) {
    up = nullptr;
    down = nullptr;
    first_server = nullptr;
}

ValueNode::~ValueNode() {
    up->setDown(down);
    down->setUp(up);
}

int ValueNode::getValue() const {
    return value;
}


bool ValueNode::isEmpty() const {
    return first_server == nullptr;
}

ValueNode* ValueNode::getUp(){
    return up;
}

ValueNode* ValueNode::getDown(){
    return down;
}


void ValueNode::setUp(ValueNode *val){
    up=val;
}

void ValueNode::setDown(ValueNode *val){
    down=val;
}

void ValueNode::addServer(ServerNode& server){
    ServerNode* old = first_server;
    first_server = &server;
    first_server->setRight(old);
    if(old != nullptr){
        old->setLeft(first_server);
    }
}

