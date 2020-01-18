//
// Created by dorgamliel on 09/01/2020.
//

#ifndef MILESTONE2_SERVER_H
#define MILESTONE2_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    //Server interface
    class Server {
    protected:
        int server_socket;
    public:
        virtual void start(int, ClientHandler*) = 0; // opens server connection and waits for for clients.
        virtual void stop() = 0; // close server.
    };
}

namespace boot {
    class Main {
    public:
        int main(int, char*[]);
    };
}

#endif //MILESTONE2_SERVER_H
