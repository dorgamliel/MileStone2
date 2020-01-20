//
// Created by dorgamliel on 16/01/2020.
//

#ifndef MILESTONE2_MATRIXSEARCHABLE_H
#define MILESTONE2_MATRIXSEARCHABLE_H

#include <fstream>
#include <sstream>
#include "Searchable.h"
#include "DFS.h"
#include "SearcherAdapter.h"

class MatrixSearchable : public Searchable<pair<int, int>> {
    pair<int, int> size;
    vector<vector<int>>* costs;
public:
    vector<State<pair<int,int>>*> getNeighbours(State<pair<int, int>>* s) override;
    //int getNumberOfStates();
    //void addToTotalCost();
    void setSize(pair<int, int>);
    double getCost(State<pair<int, int>>*, State<pair<int, int>>*) override;
    void setCosts(vector<vector<int>>* c);
};

namespace test1 { // ? delete it
    class Main {
    public:
        // testing DFS algorithm by reading matrix for 'matrix_test.txt' file and running DFS on it
        int main(int, char*[]){


            ifstream file;
            file.open("matrix_test.txt", ios::in);
            int i = 0;
            int j = 0;
            string line;
            istringstream valueStream;
            string singleValue;
            vector<vector<int>> costs;
            // read file by lines
            while (file) {
                vector<int> singleRow;
                getline(file, line);
                valueStream = istringstream(line);
                if (line == "end") {
                    break;
                }
                // split each line into cells and put each cell cost into 'costs' vector
                while (std::getline(valueStream, singleValue, ','))
                {
                    singleRow.push_back(stoi(singleValue));
                }
                costs.push_back(singleRow);
            }
            // get start and target cells, and remove
            pair<int, int> target(costs[costs.size()-1][0], costs[costs.size()-1][1]);
            pair<int, int> start(costs[costs.size()-2][0], costs[costs.size()-2][1]);
            // remove start and target info lines from 'costs' vector
            costs.pop_back();
            costs.pop_back();
            // initialize searchable matrix problem
            State<pair<int, int>> startState(start);
            State<pair<int, int>> targetState(target);
            // size of matrix (starting from 0)
            i = costs[0].size() - 1;
            j = costs.size() - 1;
            MatrixSearchable m;
            m.setInitialState(&startState);
            m.setGoalState(&targetState);
            pair<int, int> size(i, j);
            m.setSize(size);
            m.setCosts(&costs);
            // find a path from start cell to target cell using DFS
            DFS<pair<int, int>> dfs;
            SearcherAdapter<pair<int, int>>* sa = new SearcherAdapter<pair<int, int>>(&dfs);
            sa->setProblem(&m);
            vector<State<pair<int,int>>*> resPath = sa->solveProblem();
            string direction;
            int count = 0;
            // print to console the path
            while (!resPath.empty()) {
                count++;
                auto s = resPath[resPath.size()-1];
                resPath.pop_back();
                auto parent = s->getCameFrom();
                if (parent == NULL) {
                    direction = "";
                } else if (parent->getState().first == s->getState().first + 1) {
                    direction = "Up";
                } else if (parent->getState().first == s->getState().first - 1) {
                    direction = "Down";
                } else if (parent->getState().second == s->getState().second + 1) {
                    direction = "Left";
                } else if (parent->getState().second == s->getState().second - 1) {
                    direction = "Right";
                }
                cout << "Direction: " + direction +  ";    Location: [" + to_string(s->getState().first) + ", " +
                to_string(s->getState().second) + "];      " + "Total cost: " + to_string(s->getCost()) << endl;
            }
            cout << "Total cells visited: " + to_string(count);
            return 0;
        }
    };
}
#endif //MILESTONE2_MATRIXSEARCHABLE_H
