//
// Created by dorgamliel on 14/01/2020.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H

#include <map>
#include "Searcher.h"
template<typename T>
class DFS : public Searcher<T>{
public:
  vector<State<T>*> search(Searchable<T>* searchable){
      State<T>* start = searchable->getInitialState();
      map<T, bool> visited;
      return DFSOper(start, searchable, visited);
  }
  vector<State<T>*> DFSOper(State<T>* state, Searchable<T>* searchable , map<T, bool> visited) {
        if (searchable->isGoalState(state)) {
            return createPath(state);
        }
        visited[state->getState()] = true;
        vector<State<T>*> allNeighbours = searchable->getNeighbours(state);
        for (auto s : allNeighbours) {
            T vertex = s->getState();
            if (visited.find(vertex) == visited.end()) {
                s->setCost(state->getCost() + searchable->getCost(state, s));
                s->setCameFrom(state);
                DFSOper(s, searchable, visited);
            }
        }




        /*visited[searchable->getNumberOfStates()] = true;
        vector<State<T>> allNeighbours = searchable->getNeighbours(state);
        //iterating vertex neighbours
        for (auto & iter : allNeighbours) {
            State<T> neighbour = iter;
            //add cost to total cost.
            searchable->addToTotalCost(neighbour);
            //if we have reached goal state, return total cost.
            if (searchable->isGoalState(neighbour)){
                //end algorithm.
            }
            //if neighbour was not visited, visit it (an do DFSOper on it and its neighbours).
            if (!visited[neighbour]){
                DFSOper(neighbour, searchable, visited);
            }
        }*/
    }
    vector<State<T>*> createPath(State<T> *goal) {
        vector<State<T> *> path;
        State<T>* s = goal;
        while (s != NULL) {
            path.push_back(s);
            s = s->getCameFrom();
        }
        return path;
    }
};


#endif //MILESTONE2_DFS_H
