//
// Created by dorgamliel on 14/01/2020.
//

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H

#include <string>
#include "Searchable.h"
template <typename T>
class Searcher {
public:
    virtual vector<State<T>*> search(Searchable<T>* s) = 0;
};


#endif //MILESTONE2_SEARCHER_H
