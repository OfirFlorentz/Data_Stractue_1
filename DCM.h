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
    AVLTree<DCNode> linux_tree;
    AVLTree<DCNode> windows_tree;
    int servers_counter;
    void updateServers(int server_id, int num_of_windows, int num_of_linux, int prev_wind, int prev_lin);

public:
    DCM():dc_tree(), linux_tree(), windows_tree(), servers_counter(0){};
    StatusType addDataCenter(int id, int num_of_servers);
    StatusType removeDataCenter(int id);
    StatusType requestServer(int dc_id, int server_id, int os, int* assigned_id);
    StatusType freeServer(int dc_id, int server_id);
    StatusType GetDataCentersByOS(int os, int **dataCenters, int* numOfDataCenters);
};


#endif //HW1_WET_DCM_H
