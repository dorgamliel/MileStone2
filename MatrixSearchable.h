//
// Created by dorgamliel on 16/01/2020.
//

#ifndef MILESTONE2_MATRIXSEARCHABLE_H
#define MILESTONE2_MATRIXSEARCHABLE_H


#include "Searchable.h"

class MatrixSearchable : public Searchable<pair<int, int>> {
public:
    vector<State<pair<int, int>>> getNeighbours(State<pair<int, int>> s);
    int getNumberOfStates();
    void addToTotalCost();
    State<pair<int, int>> getInitialState();
    bool isGoalState (State<pair<int, int>> s);


};

namespace test1 { // ? delete it
    class Main {
    public:
        int main(int, char*[]){
            MatrixSearchable m;
            int x = m.getNumberOfStates();
            return 0;
        }
    };
}
#endif //MILESTONE2_MATRIXSEARCHABLE_H
