//
// Created by dorgamliel on 14/01/2020.
//

#ifndef TEMPFORSERVER_SEARCHABLE_H
#define TEMPFORSERVER_SEARCHABLE_H

#include <vector>
#include <string>

using namespace std;

class Searchable {
public:
    virtual vector<string> getNeighbours() = 0;
    virtual int countVertices() = 0;
    virtual string getPath() = 0;
    virtual int getTotalCost() =0;
};


#endif //TEMPFORSERVER_SEARCHABLE_H
