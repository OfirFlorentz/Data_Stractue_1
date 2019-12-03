//
// Created by ofir on 01/12/2019.
//

#ifndef HW1_WET_DC_H
#define HW1_WET_DC_H

#include <exception>
#include <iostream>
#include "Queue.h"

enum StatusType { INVALID_INPUT, FAILURE, SUCCESS};
enum OS {LINUX, WINDOWS};


struct Server{
    bool busy;
    bool os;
    int server_num;
};

class DC {
    int id;
    int num_of_servers;
    Queue<Server> windows;
    Queue<Server> lin;
    int num_of_windows;
    Server** servers;
    Chain<Server>** servers_in_q;

public:
    DC(int id, int num_of_servers);
    ~DC();
    DC(const DC&) = delete;
    bool operator = (const DC&) = delete;
    void freeServer(int server_id);
    int requestServer(int server_id, bool os);
    int numOfWindows() const;
    int numOfLinux() const;

    friend bool operator ==(const DC&, const DC&);
    friend bool operator < (const DC&, const DC&);


    class InvalidInput : public std::exception {
        const char* what() const throw() override{
            return "invalid input";
        }
    };
    class Failure : public std::exception {
        const char *what() const throw() override {
            return "failure";
        }
    }
};


#endif //HW1_WET_DC_H
