//
// Created by dorgamliel on 16/01/2020.
//

#include "MatrixSearchable.h"

#include <utility>
#include "DFS.h"

vector<State<pair<int, int>>*> MatrixSearchable::getNeighbours(State<pair<int, int>>* s){
    vector<State<pair<int, int>>*> vector;
    // location of current cell
    int i = s->getState().first;
    int j = s->getState().second;
    /*
     * create a list of all possible neighbours by this order:
     * 1. neighbour below
     * 2. neighbour above
     * 3. neighbour to the right
     * 4. neighbour to the left
     * an adjacent cell with a cost of -1 is considered unreachable and therefore not considered a neighbour
     */
    if (i != this->size.first)  {
        if ((*costs)[i+1][j] != -1) {
            auto *s1 = new State<pair<int, int>>({i + 1, j});
            vector.push_back(s1);
        }
    }
    if (i != 0) {
        if ((*costs)[i-1][j] != -1) {
            auto *s2 = new State<pair<int, int>>({i - 1, j});
            vector.push_back(s2);
        }
    }
    if (j != this->size.second) {
        if ((*costs)[i][j+1] != -1) {
            auto *s3 = new State<pair<int, int>>({i, j + 1});
            vector.push_back(s3);
        }
    }
    if (j != 0) {
        if ((*costs)[i][j-1] != -1) {
            auto *s4 = new State<pair<int, int>>({i, j - 1});
            vector.push_back(s4);
        }
    }
    return vector;
}

/*int MatrixSearchable::getNumberOfStates() { //??need to see how to operate dfs.
    //DFS<pair<int, int>> d;
    DFS<pair<int, int>>* dfs;
    auto vector = dfs->search(this);
    //delete dfs;
    return vector.size();
}*/

// set the size of the matrix
void MatrixSearchable::setSize(pair<int, int> si) {
    this->size = si;
}

// get cost of the edge from origin to dest
double MatrixSearchable::getCost(State<pair<int, int>> *origin, State<pair<int, int>> *dest) {
    return (*costs)[dest->getState().first][dest->getState().second];
}

// set the costs table
void MatrixSearchable::setCosts(vector<vector<int>>* c) {
    this->costs = c;
}
