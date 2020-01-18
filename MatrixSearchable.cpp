//
// Created by dorgamliel on 16/01/2020.
//

#include "MatrixSearchable.h"
#include "DFS.h"

vector<State<pair<int, int>>> MatrixSearchable::getNeighbours(State<pair<int, int>> s){
    vector<State<pair<int, int>>> vector;
    auto iterator = vector.begin();
    int i = s.getState().first;
    int j = s.getState().second;
    State<pair<int, int>> s1({i+1, j});
    State<pair<int, int>> s2({i-1, j});
    State<pair<int, int>> s3({i, j+1});
    State<pair<int, int>> s4({i, j-1});
    vector.insert(iterator, s1);
    vector.insert(iterator, s2);
    vector.insert(iterator, s3);
    vector.insert(iterator, s4);
    return vector;
}

int MatrixSearchable::getNumberOfStates() { //??need to see how to operate dfs.
    //DFS<pair<int, int>> d;
    DFS<pair<int, int>>* dfs;
    auto vector = dfs->search(this);
    //delete dfs;
    return vector.size();
}

void MatrixSearchable::addToTotalCost(){}
State<pair<int, int>> MatrixSearchable::getInitialState(){}
bool MatrixSearchable::isGoalState (State<pair<int, int>> s){}
