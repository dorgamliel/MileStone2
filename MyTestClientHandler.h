//
// Created by dorgamliel on 09/01/2020.
//

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "StringReverser.h"

class MyTestClientHandler : public ClientHandler {
    StringReverser* solver;
    FileCacheManager* cm;
public:
    MyTestClientHandler(StringReverser* sol, FileCacheManager* cache){
        solver = sol;
        cm = cache;
    }
    void handleClient();
};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
