//
// Created by ofir on 24/11/2019.
//

#include "library1.h"
#include "DCM.h"

void * Init(){
    DCM *DS = new DCM ();
    return (void*)DS;
}

StatusType AddDataCenter(void *DS, int dataCenterID, int numOfServers) {
    if (DS == NULL){
        return INVALID_INPUT;
    }
    return ((DCM *)DS)-> addDataCenter(dataCenterID, numOfServers);
}

StatusType RemoveDataCenter(void *DS, int dataCenterID) {
    if (DS == NULL){
        return INVALID_INPUT;
    }
    return ((DCM *)DS)-> removeDataCenter(dataCenterID);
}

StatusType RequestServer(void *DS, int dataCenterID, int serverID, int os, int *assignedID){
    if (DS == NULL){
        return INVALID_INPUT;
    }
    return ((DCM *) DS)-> requestServer(dataCenterID,serverID,os,assignedID);
}

StatusType FreeServer(void *DS, int dataCenterID, int serverID){
    if (DS == NULL){
        return INVALID_INPUT;
    }
    return ((DCM *) DS)-> freeServer(dataCenterID,serverID);
}

StatusType GetDataCentersByOS(void *DS, int os, int **dataCenters, int* numOfDataCenters){
    if (DS == NULL){
        return INVALID_INPUT;
    }
    return ((DCM *) DS)->GetDataCentersByOS(os,dataCenters,numOfDataCenters);
}

void Quit(void **DS) {
    delete ((DCM *) *DS);
    *DS = NULL;
}