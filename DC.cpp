//
// Created by ofir on 01/12/2019.
//

#include "DC.h"

//we have to check in dcm there is no other DC with same id
DC::DC(int id, int num_of_servers) : id(id), num_of_servers(num_of_servers), num_of_windows(0), windows(),lin() {
    if(id <= 0 || num_of_servers <= 0)
        throw InvalidInput();
    servers = new Server*[num_of_servers];
    servers_in_q = new Chain<Server>*[num_of_servers];
    for(int i=0; i<num_of_servers; i++){
        servers[i] = new Server;
        servers[i]->os = 0;
        servers[i]->busy = false;
        servers[i]->server_num = i;
        servers_in_q[i] = lin.enqueue(*servers[i]);
    }
}

void DC::freeServer(int server_id) {
    if(server_id < 0 || server_id >= num_of_servers)
        throw InvalidInput();
    if(servers[server_id]->busy == false) {
        throw Failure();
    } else{
      servers[server_id]->busy = false;
      if(servers[server_id]->os == 1)
          servers_in_q[server_id] = windows.enqueue(*servers[server_id]);
      else
          servers_in_q[server_id] = lin.enqueue(*servers[server_id]);
    }
}

int DC::requestServer(int server_id, bool os) {
    if(server_id < 0 || server_id >= num_of_servers)
        throw InvalidInput();
    int s_num;
    if (servers[server_id]->busy == false) {
        s_num = server_id;
        if (servers[server_id]->os == 0) {
            lin.dequeueByValue(servers_in_q[server_id]);
        } else {
            windows.dequeueByValue(servers_in_q[server_id]);
        }
        if (servers[server_id]->os != os) {
            if(os == 0)
                num_of_windows--;
            else
                num_of_windows++;
            servers[server_id]->os = os;
        }
    } else if (os == 0) {
        if (!lin.isEmpty()) {
            s_num = lin.top().server_num;
            lin.dequeue();
        } else if (!windows.isEmpty()) {
            s_num = windows.top().server_num;
            servers[s_num]->os = 0;
            windows.dequeue();
            num_of_windows --;
        } else {
            throw Failure();
        }
    } else if (os == 1) {
        if (!windows.isEmpty()) {
            s_num = windows.top().server_num;
            windows.dequeue();
        } else if (!lin.isEmpty()) {
            s_num = lin.top().server_num;
            servers[s_num]->os = 1;
            lin.dequeue();
            num_of_windows ++;
        } else {
            throw Failure();
        }
    }
    servers[s_num]->busy = true;
    servers_in_q[s_num] = nullptr;
    return s_num;
}

DC::~DC() {
    for(int i=0; i<num_of_servers; i++) {
        delete servers[i];
    }
    delete[] servers_in_q;
    delete[] servers;
}

int DC::numOfWindows() const {
    return num_of_windows;
}

int DC::numOfLinux() const {
    return num_of_servers-num_of_windows;
}

bool operator==(const DC & first, const DC & second) {
    return(first.id == second.id);
}

bool operator==( DC & first,  DC & second) {
    return(first.id == second.id);
}

bool operator<(const DC & first, const DC & second) {
    return first.id < second.id;
}

bool operator<(DC & first, DC & second) {
    return first.id < second.id;
}

ostream &operator<<(ostream &os, const DC &dc) {
    return os << dc.id;
}

int DC::numOfServers() const {
    return num_of_servers;
}


bool operator>(const DC & first, const DC & second) {
    return (!(first < second) && !(first==second));
}

bool operator>( DC & first,  DC & second) {
    return (!(first < second) && !(first==second));
}

bool operator<=(const DC & first, const DC & second) {
    return ((first < second) || (first==second));
}


bool operator>=(const DC & first, const DC & second) {
    return ((first > second) || (first==second));
}


