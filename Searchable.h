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
    string path;
public:
    virtual vector<State<T>> getNeighbours(State<T> s) = 0;
    virtual State<T> getInitialState() = 0;
    virtual bool isGoalState (State<T> s) = 0;
    virtual int getNumberOfStates() = 0;
    virtual void addToTotalCost() = 0;
    //virtual string getPath() = 0;
    //virtual int getTotalCost() = 0;
};


#endif //MILESTONE2_SEARCHABLE_H
