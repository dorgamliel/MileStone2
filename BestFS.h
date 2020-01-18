//
// Created by dorgamliel on 14/01/2020.
//

#ifndef MILESTONE2_BESTFS_H
#define MILESTONE2_BESTFS_H


#include "Searcher.h"
template<typename T>
class BestFS : public Searcher<T>{
    void search(Searchable<T>* searchable);
};


#endif //MILESTONE2_BESTFS_H
