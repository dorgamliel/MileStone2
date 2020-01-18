//
// Created by dorgamliel on 14/01/2020.
//

#include "DFS.h"
template<typename T>
//DFS search algorithm.
vector<State<T>*> DFS<T>::search(Searchable<T>* searchable){
    State<T> start = searchable->getInitialState();
    int verticesCount = searchable->getNumberOfStates();
    bool *visited = new bool[verticesCount];
    //update all nodes as "unvisited".
    for (int i=0; i< verticesCount; i++){
        visited[i] = false;
    }
    DFSOper(start, searchable, visited);
}
template<typename T>
//Recursive part of DFS.
void DFS<T>::DFSOper(State<T> state,Searchable<T>* searchable , bool visited[]){
    visited[searchable->getNumberOfStates()] = true;
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
    }
}
