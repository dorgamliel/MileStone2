//
// Created by dorgamliel on 20/01/2020.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H

#include <queue>
#include <map>
#include "Searcher.h"

template <typename T>
class BFS : public Searcher<T>{
public:
    vector<State<T>*> search(Searchable<T>* searchable) {
        State<T>* state = searchable->getInitialState();
        queue<State<T>*> queue;
        map<T, bool> visited;
        visited[state->getState()] = true;
        queue.push(state);
        while (!queue.empty()){
            state = queue.front();
            queue.pop();
            //list neighbours of state in a vector.
            vector<State<T>*> allNeighbours = searchable->getNeighbours(state);
            //if reached goal state, return path from beginning to it.
            if (searchable->isGoalState(state)) {
                return Searcher<T>::createPath(state);
            }
            //iterate all neighbours of state.
            for (State<T>* s : allNeighbours) {
                T vertex = s->getState();
                // if this neighbour has not been visited yet
                if (visited.find(vertex) == visited.end()) {
                    // set the total cost to get to this neighbour and current vertex to be neighbours parent
                    s->setCost(state->getCost() + searchable->getCost(state, s));
                    s->setCameFrom(state);
                    //set state as visited
                    visited[s->getState()] = true;
                    queue.push(s);
                }
            }
        }

    }
};


#endif //MILESTONE2_BFS_H
