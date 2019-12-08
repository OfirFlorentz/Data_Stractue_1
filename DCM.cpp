//
// Created by ofir on 02/12/2019.
//

#include "DCM.h"

StatusType DCM::addDataCenter(int id, int num_of_servers) {
    // Validate parameters
    if (num_of_servers <= 0 || id <= 0)
        return INVALID_INPUT;
    // Create new dc and allocate memory for it.
    DC* new_dc;
    new_dc = new DC(id, num_of_servers);
    // If DC with same id already exist, abort and return failure.
    if(dc_tree.isExist(new_dc)) {
        delete new_dc;
        return FAILURE;
    } else {
        // Add the dc to the dc tree
        // And add DCnodes to the linux and windows trees
        dc_tree.insertTreeNode(new_dc);
        DCNode* new_windows = new DCNode(id , 0);
        DCNode* new_linux = new DCNode(id, num_of_servers);
        windows_tree.insertTreeNode(new_windows);
        linux_tree.insertTreeNode(new_linux);
        servers_counter++;
        return SUCCESS;
    }
}

StatusType DCM::removeDataCenter(int id) {
    // Validate parameters
    if (id <= 0)
        return INVALID_INPUT;
    // Create a template node to remove with it
    DC temp(id, 1);
    DC* temp_ptr = dc_tree.getData(&temp);
    if (temp_ptr == nullptr){
        return FAILURE;
    }
    // Remove the data center from the remaining trees.
    DCNode node_windows(id,temp_ptr->numOfWindows());
    windows_tree.removeTreeNode(&node_windows);
    DCNode node_linux(id,temp_ptr->numOfLinux());
    linux_tree.removeTreeNode(&node_linux);
    dc_tree.removeTreeNode(&temp);
    servers_counter--;
    return SUCCESS;
}

StatusType DCM::requestServer(int dc_id, int server_id, int os, int* assigned_id) {
    // Validate parameters.
    if (dc_id <= 0 || server_id < 0 || os > 1 || os < 0)
        return INVALID_INPUT;
    // Check data center exists with enough servers
    DC temp(dc_id,1);
    DC* dc = dc_tree.getData(&temp);//num of servers is not importent for compering
    if(dc == NULL)
        return FAILURE;
    if (dc->numOfServers() <= server_id )
        return INVALID_INPUT;
    // Try to allocate a server
    try {
        int windows_server = dc->numOfWindows();
        int linux_server = dc->numOfLinux();
        int server = dc->requestServer(server_id, os);
        *assigned_id = server;
        // os changed
        if(windows_server != dc->numOfWindows())
            updateServers(dc_id, dc->numOfWindows(), dc->numOfLinux(), windows_server, linux_server);
    }
    // If it fails, return failure
    catch(const DC::Failure& e) {
        return FAILURE;
    }
    catch(const std::exception& e) {
        cout << "somthingworng " <<  e.what();
        return FAILURE;
    }
    return SUCCESS;
}

// A function that updates the trees after every change in server operating systems.
void DCM::updateServers(int server_id, int num_of_windows, int num_of_linux, int prev_wind, int prev_lin) {
    DCNode* new_windows = new DCNode(server_id , prev_wind);
    DCNode* new_linux = new DCNode(server_id, prev_lin);
    windows_tree.removeTreeNode(new_windows);
    linux_tree.removeTreeNode(new_linux);
    delete new_windows;
    delete new_linux;
    new_windows = new DCNode(server_id , num_of_windows);
    new_linux = new DCNode(server_id, num_of_linux);
    windows_tree.insertTreeNode(new_windows);
    linux_tree.insertTreeNode(new_linux);
}

StatusType DCM::freeServer(int dc_id, int server_id) {
    // Validate parameters
    if (dc_id <= 0 || server_id < 0)
        return INVALID_INPUT;
    DC temp(dc_id,1);
    DC* dc = dc_tree.getData(&temp);//num of servers is not importent for compering
    // Make sure data center exists with correct number of servers
    if(dc == NULL)
        return FAILURE;
    if (dc->numOfServers() <= server_id )
        return INVALID_INPUT;
    // free server. If fails return failure.
    try {
        dc->freeServer(server_id);
    } catch(const DC::Failure& e) {
        return FAILURE;
    }
    catch(const std::exception& e) {
        cout << "somthingworng " <<  e.what();
        return FAILURE;
    }
    return SUCCESS;
}

StatusType DCM::GetDataCentersByOS(int os, int **dataCenters, int *numOfDataCenters) {
    // If no data centers return failure.
    if(servers_counter == 0)
        return FAILURE;
    *numOfDataCenters = servers_counter;
    DCNode** in_order_elements;
    // Allocate memory for sorted Data Centers array.
    *dataCenters= (int*)malloc(sizeof(int) * servers_counter);
    // If allocation failed, return error.
    if (*dataCenters == NULL){
        return ALLOCATION_ERROR;
    }
    // Choose relevant order
    if(os == 0) {
        in_order_elements = linux_tree.inorderArr();
    } else {
        in_order_elements = windows_tree.inorderArr();
    }
    // Reverse the output from the tree and return it.
    int j =0;
    for(int i = servers_counter-1; i>=0; i--) {

        (*dataCenters)[j++] = in_order_elements[i]->getId();
    }
    delete[] in_order_elements;
    return SUCCESS;
}

