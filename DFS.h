//
// Created by dorgamliel on 14/01/2020.
//

#ifndef TEMPFORSERVER_DFS_H
#define TEMPFORSERVER_DFS_H


#include "Searcher.h"

class DFS : public Searcher{
    vector<pair <int, int>> search(Searchable* searchable);
};


#endif //TEMPFORSERVER_DFS_H
