//
// Created by dorgamliel on 14/01/2020.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H


#include "Searcher.h"
template<typename T>
class DFS : public Searcher<T>{
public:
    vector<State<T>*> search(Searchable<T>* searchable);
    void DFSOper(State<T> state, Searchable<T>* searchable, bool* visited);
};


#endif //MILESTONE2_DFS_H
