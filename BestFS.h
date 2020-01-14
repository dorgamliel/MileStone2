//
// Created by dorgamliel on 14/01/2020.
//

#ifndef TEMPFORSERVER_BESTFS_H
#define TEMPFORSERVER_BESTFS_H


#include "Searcher.h"

class BestFS : public Searcher{
    vector<pair <int, int>> search(Searchable* searchable);
};


#endif //TEMPFORSERVER_BESTFS_H
