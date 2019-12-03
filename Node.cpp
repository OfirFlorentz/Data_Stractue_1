//
// Created by ofir on 26/11/2019.
//

#include "Node.h"

bool operator > (const DCNode &first, const DCNode &second) {
    if(first.value > second.value)
        return true;
    else if(first.value < second.value)
        return false;
    return (first.id>second.id);
}

bool operator > ( DCNode &first,  DCNode &second) {
    if(first.value > second.value)
        return true;
    else if(first.value < second.value)
        return false;
    return (first.id>second.id);
}

bool operator < (const DCNode &first, const DCNode &second) {
    return (!(first>second) && !(first==second));
}

bool operator < (DCNode &first, DCNode &second) {
    return (!(first>second) && !(first==second));
}


bool operator <= (const DCNode &first, const DCNode &second) {
    return (first<second) || (first==second);
}

bool operator <= (DCNode &first, DCNode &second) {
    return (first<second) || (first==second);
}

bool operator >= (const DCNode &first, const DCNode &second) {
    return (first>second) || (first==second);
}

bool operator >= (DCNode &first, DCNode &second) {
    return (first>second) || (first==second);
}

bool  operator == (const DCNode &first, const DCNode &second) {
    return (first.id == second.id);
}

bool  operator == (DCNode &first, DCNode &second) {
    return (first.id == second.id);
}


int DCNode::getId() const {
    return id;
}

int DCNode::getValue() const {
    return value;
}

DCNode::DCNode(int id, int value) : id(id), value(value){
}

//--------------------------------------------------------------------//
//                                end of Dc                           //
/*
ValueNode::ValueNode(int value): value(value), servers(), size(0) {
    up = nullptr;
    down = nullptr;
}


int ValueNode::getValue() const {
    return value;
}

int ValueNode::getSize() const {
    return size;
}

bool ValueNode::isEmpty() const {
    return servers.isEmpty();
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

void ValueNode::addServer(DCNode& server){
    servers.addServer(server);
}


void ValueNode::removeServer(DCNode& server){
    servers.removeServer(server);
}
*/

