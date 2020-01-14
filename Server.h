//
// Created by dorgamliel on 09/01/2020.
//

#ifndef TEMPFORSERVER_SERVER_H
#define TEMPFORSERVER_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    //Server interface
    class Server {
    protected:
        int server_socket;
    public:
        virtual void open(int, ClientHandler*) = 0; // opens server connection and waits for for clients.
        virtual void stop() = 0; // close server.
    };
}

namespace boot {
    class Main {
    public:
        int main(int, char*[]);
    };
}

#endif //TEMPFORSERVER_SERVER_H
