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
        // if reached target vertex, return the path from start vertex to target vertex
        if (searchable->isGoalState(state)) {
            return createPath(state);
        }
        // mark this vertex as visited
        visited[state->getState()] = true;
        vector<State<T>*> allNeighbours = searchable->getNeighbours(state);
        // if the neighbour list is empty, we have reached a dead end, and we will return empty vector
        if (allNeighbours.empty()) {
            vector<State<T>*> vec;
            return vec;
        }
        // iterate through neighbours and try to find a path to target vertex
        for (auto s : allNeighbours) {
            T vertex = s->getState();
            // if this neighbour has not been visited yet
            if (visited.find(vertex) == visited.end()) {
                // set the total cost to get to this neighbour and current vertex to be neighbours parent
                s->setCost(state->getCost() + searchable->getCost(state, s));
                s->setCameFrom(state);
                // run DFS recursively on the neighbour vertex
                auto path = DFSOper(s, searchable, visited);
                // if the path is empty, it means we have reached a dead end, so we will try to find a path
                // to target vertex from the next neighbour, otherwise, meaning we found a path from the neighbour
                // to target vertex, we will return the total path from start vertex to target vertex
                if (path.empty()) {
                    continue;
                } else {
                    return path;
                }
            }
        }
        //
        // reaching this code means current vertex has neighbours but they have all been visited in the past and
        // therefore it is useless to visit them again, meaning we reached a dead end, therefore returning
        // an empty path
        vector<State<T>*> vec;
        return vec;




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
};


#endif //MILESTONE2_DFS_H
