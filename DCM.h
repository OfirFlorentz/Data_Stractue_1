//
// Created by ofir on 02/12/2019.
//

#ifndef HW1_WET_DCM_H
#define HW1_WET_DCM_H

#include "AVLTree.h"
#include "DC.h"
#include "Node.h"


class DCM {
    AVLTree<DC> dc_tree;
    AVLTree<DC> linux_tree;
    AVLTree<DC> windows_tree;

    void updateServers(int server_id, int num_of_windows, int num_of_linux);

public:
    StatusType addDataCenter(int id, int num_of_servers);
    StatusType removeDataCenter(int id);
    StatusType requestServer(int dc_id, int server_id, int os, int* assigned_id);
    StatusType FreeServer(int dc_id, int server_id);
};


#endif //HW1_WET_DCM_H
