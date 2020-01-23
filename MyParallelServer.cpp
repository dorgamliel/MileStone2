//
// Created by alon on 21/01/2020.
//

#include "MyParallelServer.h"
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <vector>
#include <thread>

#define MAX_WAIT 5

void MyParallelServer::start(int port, ClientHandler* c) {
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    int addrlen = sizeof(address);
    vector<thread> threadVec;
    //we need to convert our number
    // to a number that the network understands.
    //the actual bind command
    if (bind(server_socket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return;
    }
    //run untill reaching maximum waiting time for client.
    while (c->getClientSocket() != -1) {
        //making socket listen to the port
        if (listen(server_socket, 5) < 0) { //can also set to SOMAXCON (max connections)
            std::cerr << "Error during listening command" << std::endl;
            return;
        } else {
            std::cout << "Server is now listening ..." << std::endl;
        }
        //set client timeout
        struct timeval tv = {MAX_WAIT, 0};
        setsockopt(server_socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
        // accepting a client
        c->setClientSocket(accept(server_socket, (struct sockaddr *) &address, (socklen_t *) &addrlen));
        if (c->getClientSocket() == -1) {
            std::cerr << "Error accepting client" << std::endl;
        } else {
            std::cout << "connected to client" << std::endl;
            ClientHandler* newC = c->clone();
            newC->setClientSocket(c->getClientSocket());
            threadVec.push_back(thread(&ClientHandler::handleClient, newC));
        }
    }
    for (thread& t : threadVec) {
        t.join();
    }
    stop();
}



void MyParallelServer::stop() {
    close(server_socket);
}