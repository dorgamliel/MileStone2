//
// Created by dorgamliel on 11/01/2020.
//

#ifndef TEMPFORSERVER_CACHEMANAGER_H
#define TEMPFORSERVER_CACHEMANAGER_H
#include <string>
using namespace std;

class CacheManager {
public:
    virtual void insert(string key, string obj) = 0;
    virtual string get(string key) = 0;
};


#endif //TEMPFORSERVER_CACHEMANAGER_H
