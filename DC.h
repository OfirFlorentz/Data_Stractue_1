
#ifndef HW1_WET_DC_H
#define HW1_WET_DC_H

#include <exception>
#include <iostream>
#include "Queue.h"
#include "library1.h"


/**This class is Data Center. In the data center there are servers of two kinds "windows" and "linux". **/
/**This class handle all type of request about the servers it holds **/

using namespace std;

struct Server{
    bool busy;
    bool os;
    int server_num;
};


class DC {
    int id;
    int num_of_servers;
    int num_of_windows;
    Queue<Server> windows;
    Queue<Server> lin;
    Server** servers;
    Chain<Server>** servers_in_q;

public:
    DC(int id, int num_of_servers);
    ~DC();
    DC(const DC&) = delete;
    bool operator = (const DC&) = delete;
    /* If the server is busy it freeing the server asked and put him last in queue. Otherwise exception is thrown. */
    void freeServer(int server_id);
    /* if the server asked is free we assign the OS asked and returned is number to the user. otherwise we assign
    other server that is free and is next one according to the queue */
    int requestServer(int server_id, bool os);
    /* return how many windows server in the DC */
    int numOfWindows() const;
    /* return how many linux server in the DC */
    int numOfLinux() const;
    /* return how many servers in the DC */
    int numOfServers() const;

    /* overloading of comparing operators. the comparison is according to the server id */
    friend bool operator ==(const DC&, const DC&);
    friend bool operator ==(DC&, DC&);
    friend bool operator < (const DC&, const DC&);
    friend bool operator < (DC&, DC&);
    friend ostream& operator<<(ostream& os, const DC& dc);


    /* Exception classes */
    class InvalidInput : public std::exception {
        const char* what() const throw() override{
            return "invalid input";
        }
    };
    class Failure : public std::exception {
        const char *what() const throw() override {
            return "failure";
        }
    };
};


#endif //HW1_WET_DC_H
