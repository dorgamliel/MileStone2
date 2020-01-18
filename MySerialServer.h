//
// Created by dorgamliel on 09/01/2020.
//

#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public server_side::Server{
public:
    MySerialServer(){

    }
    void start(int, ClientHandler *c);
    void stop();
};


#endif //MILESTONE2_MYSERIALSERVER_H
