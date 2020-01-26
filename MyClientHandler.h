//
// Created by alon on 20/01/2020.
//

#ifndef MILESTONE2__MYCLIENTHANDLER_H_
#define MILESTONE2__MYCLIENTHANDLER_H_

#include <sstream>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include "ClientHandler.h"
#include "Searchable.h"
#include "MatrixSearchable.h"
#include "FileCacheManager.h"
class MyClientHandler : public ClientHandler {
    Solver<Searchable<pair<int, int>>*, vector<State<pair<int, int>>*>>* solver;
    FileCacheManager* cm;

public:
    MyClientHandler(Solver<Searchable<pair<int, int>>*, vector<State<pair<int, int>>*>>* s) {
        this->solver = s;
        this->cm = new FileCacheManager();
    }

    void handleClient() {
        string matrix;
        std::istringstream valueStream;
        is_done = false;
        char buffer[1024] = {0};
        string dataLine;
        int buffSize = sizeof(buffer);
        // continues as long as the script is running
        while (!isDone()) {
            string str = buffer;
            while (str.find("end") != 0) {
                read(this->client_socket, buffer, buffSize);
                matrix += buffer;
                str = buffer;
                fill_n(buffer, sizeof(buffer), 0);
            }
            // USE HASH ON 'MATRIX'

            //try getting solution from existing file.
            try{
                // TRY TO GET MATRIX FROM CACHE/FILE
                string stFromCache = cm->get(matrix);
                char* toSend = new char[stFromCache.size()+1];
                strcpy(toSend, stFromCache.c_str());
                int is_sent = send(client_socket , toSend , strlen(toSend) , 0);
                if (is_sent == -1) {
                    std::cout<<"Error sending message"<<std::endl;
                }
            } catch(const char* e) {
                MatrixSearchable m = createMatrix(&matrix);
                 //SHOULD BE BEST SEARCH ALGORITHM (PROBABLY A*)
                this->solver->setProblem(&m);
                vector<State<pair<int,int>>*> resPath = this->solver->solveProblem();
                string direction;
                string solution;
                int count = 0;
                // print to console the path
                while (!resPath.empty()) {
                    count++;
                    auto s = resPath[resPath.size()-1];
                    resPath.pop_back();
                    auto parent = s->getCameFrom();
                    if (parent == NULL) {
                        direction = "";
                    } else if (parent->getState().first == s->getState().first + 1) {
                        direction = "Up";
                    } else if (parent->getState().first == s->getState().first - 1) {
                        direction = "Down";
                    } else if (parent->getState().second == s->getState().second + 1) {
                        direction = "Left";
                    } else if (parent->getState().second == s->getState().second - 1) {
                        direction = "Right";
                    }
                    solution += direction;
                    solution += "(";
                    solution += to_string(s->getCost());
                    solution += "), ";
                }
                char* toSend = new char[solution.size()+1];
                strcpy(toSend, solution.c_str());
                int is_sent = send(client_socket , toSend , strlen(toSend) , 0);
                if (is_sent == -1) {
                    std::cout<<"Error sending message"<<std::endl;
                }
                //create hash function to calculate file name.
                hash<string> h;
                size_t hash = h(matrix);
                //create a file with solution in it.
                cm->insert(to_string(hash), solution);
            }
            this->is_done = true;
        }
        close(this->client_socket);
    }


    MatrixSearchable createMatrix(string* matrix) {
        string line;
        istringstream lineStream;
        istringstream  valueStream;
        string singleValue;
        string singleLine;
        vector<vector<int>>* costs = new vector<vector<int>>();
        vector<int>* singleRow = new vector<int>();


        lineStream = istringstream(*matrix);
        while (std::getline(lineStream, singleLine, '\n')) {
            if (singleLine == "end") {
                continue;
            }
            valueStream = istringstream(singleLine);
            while (std::getline(valueStream, singleValue, ','))
            {
                singleRow->push_back(stoi(singleValue));
            }
            costs->push_back(*singleRow);
            singleRow->clear();

        }
        // split each line into cells and put each cell cost into 'costs' vector
    // get start and target cells, and remove
    pair<int, int> target((*costs)[costs->size()-1][0], (*costs)[costs->size()-1][1]);
    pair<int, int> start((*costs)[costs->size()-2][0], (*costs)[costs->size()-2][1]);
    // remove start and target info lines from 'costs' vector
    costs->pop_back();
    costs->pop_back();
    // initialize searchable matrix problem
    State<pair<int, int>>* startState = new State<pair<int, int>>(start);
    State<pair<int, int>>* targetState = new State<pair<int, int>>(target);
    // size of matrix (starting from 0)
    int i = (*costs)[0].size() - 1;
    int j = costs->size() - 1;
    MatrixSearchable m;
    m.setInitialState(startState);
    m.setGoalState(targetState);
    pair<int, int> size(i, j);
    m.setSize(size);
    m.setCosts(costs);
    return m;
    // COSTS AND STATES OF MATRIX DISAPPEAR ONCE OUT OF FUNCTIONS
    }


    ClientHandler* clone() {
        auto newSolver = this->solver->clone();
        MyClientHandler* newC = new MyClientHandler(newSolver);
        return newC;
    }

};

#endif //MILESTONE2__MYCLIENTHANDLER_H_
