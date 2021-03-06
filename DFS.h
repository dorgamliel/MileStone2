//
// Created by dorgamliel on 14/01/2020.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H

#include <map>
#include <set>

#include "Searcher.h"
template<typename T>
class DFS : public Searcher<T>{
public:
  vector<State<T>*> search(Searchable<T>* searchable){
      State<T>* start = searchable->getInitialState();
      start->setCost(searchable->getCost(NULL, start));
      set<T> vis;
      return DFSOper(start, searchable, &vis);
  }
  vector<State<T>*> DFSOper(State<T>* state, Searchable<T>* searchable , set<T>* vis) {
        // if reached target vertex, return the path from start vertex to target vertex
        if (searchable->isGoalState(state)) {
            return Searcher<T>::createPath(state);
        }
        // mark this vertex as visited
        vis->insert(state->getState());
        vector<State<T>*> allNeighbours = searchable->getNeighbours(state);
        // iterate through neighbours and try to find a path to target vertex
        for (State<T>* s : allNeighbours) {
            T vertex = s->getState();
            // if this neighbour has not been visited yet
            if (vis->find(vertex) == vis->end()) {
                // set the total cost to get to this neighbour and current vertex to be neighbours parent
                s->setCost(state->getCost() + searchable->getCost(state, s));
                s->setCameFrom(state);
                // run DFS recursively on the neighbour vertex
                auto path = DFSOper(s, searchable, vis);
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


    Searcher<T>* clone() {
      return new DFS<T>();
  }
};


#endif //MILESTONE2_DFS_H
