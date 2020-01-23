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
    int cost = 0;
    State<T>* cameFrom = NULL;
    int heuristicCost = 0;
public:
    State(T state){ this->state = state; }
    T getState(){ return this->state; }
    bool operator==(State<T> const &secondState) const { return state == secondState.state; }
    void setCost(double c) {
        this->cost = c;
    }
    void setCameFrom(State<T>* parent) {
        this->cameFrom = parent;
    }
    int getCost() {
        return this->cost;
    }
    State<T>* getCameFrom() {
        return this->cameFrom;
    }
    int getHeuristicCost(){return this->heuristicCost;}
    void setHeuristicCost(int c){ this->heuristicCost = c;}
};


#endif //MILESTONE2_STATE_H
