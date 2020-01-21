/*
//
// Created by alon on 20/01/2020.
//

#ifndef MILESTONE2__MYCLIENTHANDLER_H_
#define MILESTONE2__MYCLIENTHANDLER_H_

#include <sstream>
#include "ClientHandler.h"
#include "Searchable.h"
template <typename T>
class MyClientHandler : public ClientHandler {
    Solver<Searchable<T>*, vector<State<T>>> solver;

 public:
    MyClientHandler(Solver<Searchable<T>*, vector<State<T>>> s) {
        this->solver = s;
    }

    void handleClient() {
        string solution;
        string matrix;
        std::istringstream valueStream;
        is_done = false;
        char buffer[1024] = {0};
        string dataLine;
        int buffSize = sizeof(buffer);
        // continues as long as the script is running
        while (!isDone()) {
            read(this->client_socket, buffer, buffSize);
            matrix += buffer;
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
            fill_n(buffer, sizeof(buffer), 0);
        }
        close(this->client_socket);
    }

};

#endif //MILESTONE2__MYCLIENTHANDLER_H_
*/
