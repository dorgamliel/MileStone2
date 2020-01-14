//
// Created by dorgamliel on 11/01/2020.
//

#ifndef TEMPFORSERVER_FILECACHEMANAGER_H
#define TEMPFORSERVER_FILECACHEMANAGER_H

#include <unordered_map>
#include <list>
#include "CacheManager.h"
class FileCacheManager : public CacheManager{
    unordered_map<string, string> _cacheMap;
public:
    void insert(string key, string obj);
    string get(string key);
};


#endif //TEMPFORSERVER_FILECACHEMANAGER_H
