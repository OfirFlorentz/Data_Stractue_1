//
// Created by ofir on 02/12/2019.
//

#include "DCM.h"


StatusType DCM::addDataCenter(int id, int num_of_servers) {
    if (num_of_servers <= 0 || id <= 0)
        return INVALID_INPUT;
    DC* new_dc = new DC(id, num_of_servers);
    AVLStatus t = dc_tree.insertTreeNode(new_dc);
    if (t == 'EXIST') {
        delete new_dc;
        return FAILURE;
    }
    DCNode* new_windows = new DCNode(id , 0);
    DCNode* new_linux = new DCNode(id, num_of_servers);
    windows_tree.insertTreeNode(new_windows);
    linux_tree.insertTreeNode(new_linux);
    return SUCCESS;
}

StatusType DCM::removeDataCenter(int id) {
    if (id <= 0)
        return INVALID_INPUT;
    DC temp(id, 1);
    AVLStatus t = dc_tree.removeTreeNode(&temp);
    if(t == NODE_NOT_EXIST)
        return FAILURE;
    DCNode node_temp(id,1);
    windows_tree.removeTreeNode(&node_temp); //num of servers is not importent for compering
    linux_tree.removeTreeNode(&node_temp);
    return SUCCESS;
}

//if not succsess assigned_int untouched. we should check
StatusType DCM::requestServer(int dc_id, int server_id, int os, int* assigned_id) {
    if (dc_id <= 0 || server_id < 0 || os > 1 || os < 0)
        return INVALID_INPUT;
    DC temp(dc_id,1);
    DC* dc = dc_tree.getData(&temp);//num of servers is not importent for compering
    if(dc == nullptr)
        return FAILURE;
    if (dc->numOfLinux() <= server_id )
        return INVALID_INPUT;
    try {
        int windows_server = dc->numOfWindows();
        int server = dc->requestServer(server_id, os);
        *assigned_id = server;
        // os changed
        if(windows_server != dc->numOfWindows())
            updateServers(server_id, dc->numOfWindows(), dc->requestServer() - dc->numOfWindows())
    }
    catch(const DC::Failure& e) {
        return FAILURE;
    }
    catch(const std::exception& e) {
        cout << "somthingworng " <<  e.what();
        return FAILURE;
    }
}


void DCM::updateServers(int server_id, int num_of_windows, int num_of_linux) {
    DCNode* new_windows = new DCNode(server_id , num_of_windows);
    DCNode* new_linux = new DCNode(server_id, num_of_linux);
    windows_tree.removeTreeNode(new_windows);
    linux_tree.removeTreeNode(new_windows);
    windows_tree.insertTreeNode(new_windows);
    linux_tree.insertTreeNode(new_linux);
}

StatusType DCM::FreeServer(int dc_id, int server_id) {
    if (dc_id <= 0 || server_id < 0)
        return INVALID_INPUT;
    DC temp(dc_id,1);
    DC* dc = dc_tree.getData(&temp);//num of servers is not importent for compering
    if(dc == nullptr)
        return FAILURE;
    if (dc->numOfLinux() <= server_id )
        return INVALID_INPUT;
    try {
        dc->freeServer(server_id);
    } catch(const DC::Failure& e) {
        return FAILURE;
    }
    catch(const std::exception& e) {
        cout << "somthingworng " <<  e.what();
        return FAILURE;
    }
}

