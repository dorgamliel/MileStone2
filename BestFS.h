/*
//
// Created by dorgamliel on 14/01/2020.
//

#ifndef MILESTONE2_BESTFS_H
#define MILESTONE2_BESTFS_H

#include <map>
#include "Searcher.h"
#include <queue>
template<typename T>
class BestFS : public Searcher<T> {
    vector<State<T> *> search(Searchable<T> *searchable) {
        map<T, bool> visited;
        State<T> *first = searchable->getInitialState();
        priority_queue<State<T> *> pq;
        vector<State<T> *> closed;
        pq.push(first);
        while (!pq.empty()) {
            //current state is the state we pop from priority queue.
            State<T> *currentState = pq.top();
            pq.pop;
            closed.insert(first);
            if (searchable->isGoalState(currentState)) {
                return createPath(currentState);
            }
            vector<State<T>*> neighbours = searchable->getNeighbours(currentState);
            //iterate current state's neighbours and push to priority queue if not visited already.
            for(auto s : neighbours){
                T vertex = s->getState();
                //if neighbour wasn't iterated before, mark it as "visited" and push to priority queue.
                if (visited.find(vertex) == visited.end() &&
                find(closed.begin(), closed.end(), vertex) == closed.end()){
                    visited[s->getState()] = true;
                    s.setCameFrom(currentState);
                    pq.push(s);
                } else {
                    if (*/
/*if new path is better than previous one*//*
){ //?? check implementation of getCost of matrixsearchable ??
                        if (visited.find(vertex) == visited.end()){
                            visited[s->getState()] = true;
                            pq.push(s);
                        } else { // adjust priority in queue.
                            pq.pop(s);
                            pq.push(s);
                        }
                    }
                }
            }
        }
    }

    vector<State<T>*> createPath(State<T> *goal) { //?? move it to searcher.h ?
        vector<State<T> *> path;
        State<T>* s = goal;
        while (s != NULL) {
            path.push_back(s);
            s = s->getCameFrom();
        }
        return path;
    }
};


#endif //MILESTONE2_BESTFS_H
*/
