//
// Created by dorgamliel on 09/01/2020.
//

#include <iostream>
#include <unistd.h>
#include <sstream>
#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient() {
    string solution;
    std::istringstream valueStream;
    is_done = false;
    char buffer[1024] = {0};
    string dataLine;
    int buffSize = sizeof(buffer);
    // continues as long as the script is running
    while (!isDone()) {
        read(this->client_socket, buffer, buffSize);
        string str = buffer;
        // checks if a bad message syntax was sent by simulator
        if (str.empty()) {
            continue;
        }
        if (str.find("end") == 0){
            is_done = true;
            continue;
        }
        valueStream = istringstream(str);
        getline(valueStream, str);
        //try getting solution from existing file.
        try{
            //searching in cache and in directory.
            solution = cm->get(str);
            cout<<"found in cache. " <<solution<<endl;
        } catch(const char* e) {
            solver->setProblem(str);
            solution = solver->solveProblem();
            cm->insert(str, solution);
            cout<<"Created a new file. " <<solution<<endl;
        }
    }
    close(this->client_socket);
}