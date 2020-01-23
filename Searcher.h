//
// Created by dorgamliel on 14/01/2020.
//

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H

#include <string>
#include "Searchable.h"
template <typename T>
class Searcher {
public:
    virtual vector<State<T>*> search(Searchable<T>* s) = 0;

    //  iterate through vertex's parents in order to create a path from start vertex to target vertex
    vector<State<T>*> createPath(State<T> *goal) {
        vector<State<T> *> path;
        State<T>* s = goal;
        while (s != NULL) {
            path.push_back(s);
            s = s->getCameFrom();
        }
        return path;
    }


    virtual Searcher* clone() = 0;
};


#endif //MILESTONE2_SEARCHER_H
