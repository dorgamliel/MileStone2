//
// Created by dorgamliel on 14/01/2020.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include <vector>
#include <string>
#include <list>
#include "State.h"

using namespace std;

template <typename T>
class Searchable {
    State<T>* initialState;
    State<T>* goalState;
public:
    virtual vector<State<T>*> getNeighbours(State<T>* s) = 0;
    virtual double getCost(State<T>*, State<T>*) = 0;
    State<T>* getGoalState() {return goalState;}
    State<T>* getInitialState() {
        return this->initialState;
    }
    bool isGoalState (State<T>* s) {
      return (*s == *(this->goalState));
  }
    void setInitialState(State<T>* s) {
        this->initialState = s;
    }
    void setGoalState(State<T>* s) {
        this->goalState = s;
    }
    virtual int getDistancefromEnd(T) = 0;

};


#endif //MILESTONE2_SEARCHABLE_H
