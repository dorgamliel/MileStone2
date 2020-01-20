//
// Created by dorgamliel on 13/01/2020.
//

#include <cstring>
#include "StringReverser.h"

string* StringReverser::solveProblem() {
    string* s = this->problem;
    *s = s->substr(0, this->problem->find("\r"));
    this->problem = s;
    int n = this->problem->length();
    string* temp = this->problem;
    for (int i=0; i < n/2;i++){
        swap(temp[i], temp[n-i-1]);
    }
    this->solution = temp;
    return this->solution;
}
void StringReverser::setProblem(string* prob) { this->problem = prob; }