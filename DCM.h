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
    // Add a new data center to the data structure
    StatusType addDataCenter(int id, int num_of_servers);
    // Remove an existing data center from the data structure.
    StatusType removeDataCenter(int id);
    // Request a server from a specific data center.
    StatusType requestServer(int dc_id, int server_id, int os, int* assigned_id);
    // Free a server from a specific data center.
    StatusType freeServer(int dc_id, int server_id);
    // Returns an array with the ids of the data centers ordered by the number
    // of servers they have from a specific operating system.
    StatusType GetDataCentersByOS(int os, int **dataCenters, int* numOfDataCenters);
    // returns how many data servers in the data structure.
    int getCounter(){
        return servers_counter;
    };
};


#endif //HW1_WET_DCM_H
