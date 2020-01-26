//
// Created by alon on 21/01/2020.
//

#ifndef MILESTONE2__MYPARALLELSERVER_H_
#define MILESTONE2__MYPARALLELSERVER_H_
#include <thread>
#include "Server.h"
#include <vector>

class MyParallelServer : public server_side::Server {

 public:
    MyParallelServer() {

    }

    void start(int, ClientHandler*);
    void stop();
    static void startClient(ClientHandler* c);

};

#endif //MILESTONE2__MYPARALLELSERVER_H_
