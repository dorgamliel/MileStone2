//
// Created by dorgamliel on 15/01/2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <string>
#include <iostream>

using namespace std;
template <typename T>
class State {
    T state;
    double cost;
    State<T>* cameFrom;
public:
    State(T state){ this->state = state; }
    T getState(){ return this->state; }
    bool operator==(State<T> const &secondState) const { return state == secondState.state; }
};


#endif //MILESTONE2_STATE_H
