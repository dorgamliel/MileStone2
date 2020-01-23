//
// Created by dorgamliel on 09/01/2020.
//
#ifndef MILESTONE2_CLIENTHANDLER_H
#define MILESTONE2_CLIENTHANDLER_H
#include <istream>
#include "CacheManager.h"
#include "Solver.h"

using namespace std;

//this interface is responsible of determining type of client-server connection protocol.
class ClientHandler {
protected:
    int client_socket;
    bool is_done = false;
public:
    virtual void handleClient() = 0;
    void setClientSocket(int s){ client_socket = s;}
    int getClientSocket() { return client_socket; }
    bool isDone() { return is_done; }
    virtual ClientHandler* clone() = 0;
};


#endif //MILESTONE2_CLIENTHANDLER_H
