//
// Created by dorgamliel on 14/01/2020.
//

#ifndef TEMPFORSERVER_SEARCHER_H
#define TEMPFORSERVER_SEARCHER_H

#include <string>
#include "Searchable.h"

using namespace std;

class Searcher {
    virtual string search(Searchable* s) = 0;
};


#endif //TEMPFORSERVER_SEARCHER_H
