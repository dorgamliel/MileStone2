//
// Created by alon on 20/01/2020.
//

#ifndef MILESTONE2__SEARCHERADAPTER_H_
#define MILESTONE2__SEARCHERADAPTER_H_

#include "Solver.h"
#include "Searcher.h"
template <typename T>
class SearcherAdapter : public Solver<Searchable<T>, vector<State<T>*>> {
    Searcher<T>* searcher;
 public:
    SearcherAdapter(Searcher<T>* searcher) {
        this->searcher = searcher;
    }

    void setProblem(Searchable<T>* problem) {
        this->problem = problem;
    }
    vector<State<T>*> solveProblem() {
        this->solution = this->searcher->search(this->problem);
        return this->solution;
    }
};



#endif //MILESTONE2__SEARCHERADAPTER_H_
