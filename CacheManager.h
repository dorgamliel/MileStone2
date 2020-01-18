//
// Created by dorgamliel on 11/01/2020.
//

#ifndef MILESTONE2_CACHEMANAGER_H
#define MILESTONE2_CACHEMANAGER_H
#include <string>
using namespace std;

class CacheManager {
public:
    virtual void insert(string key, string obj) = 0;
    virtual string get(string key) = 0;
};


#endif //MILESTONE2_CACHEMANAGER_H
