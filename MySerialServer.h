//
// Created by dorgamliel on 09/01/2020.
//

#ifndef TEMPFORSERVER_MYSERIALSERVER_H
#define TEMPFORSERVER_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public server_side::Server{
public:
    MySerialServer(){

    }
    void open(int, ClientHandler *c);
    void stop();
};


#endif //TEMPFORSERVER_MYSERIALSERVER_H
