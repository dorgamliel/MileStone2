//
// Created by dorgamliel on 13/01/2020.
//

#include <cstring>
#include "StringReverser.h"

string StringReverser::solveProblem() {
    this->problem = this->problem.substr(0, this->problem.find("\r"));
    int n = this->problem.length();
    string temp = this->problem;
    for (int i=0; i < n/2;i++){
        swap(temp[i], temp[n-i-1]);
    }
    this->solution = temp;
    return this->solution;
}
void StringReverser::setProblem(string prob) { this->problem = prob; }