//
// Created by dorgamliel on 11/01/2020.
//

#ifndef MILESTONE2_FILECACHEMANAGER_H
#define MILESTONE2_FILECACHEMANAGER_H

#include <unordered_map>
#include <list>
#include "CacheManager.h"
class FileCacheManager : public CacheManager{
    unordered_map<string, string> _cacheMap;
public:
    void insert(string key, string obj);
    string get(string key);
};


#endif //MILESTONE2_FILECACHEMANAGER_H
