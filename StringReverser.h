//
// Created by dorgamliel on 13/01/2020.
//

#ifndef TEMPFORSERVER_STRINGREVERSER_H
#define TEMPFORSERVER_STRINGREVERSER_H

using namespace std;

#include <string>
#include "Solver.h"

class StringReverser : public Solver<string, string>{
public:
    string solveProblem();
    void setProblem(string);
};


#endif //TEMPFORSERVER_STRINGREVERSER_H
