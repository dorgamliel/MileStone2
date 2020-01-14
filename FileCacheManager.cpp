//
// Created by dorgamliel on 30/11/2019.
//
#ifndef EX2_EX2_H
#define EX2_EX2_H
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "FileCacheManager.h"


using namespace std;
void FileCacheManager::insert(string key, string obj){
    ofstream file(key, ios::binary);
    if (!file) {
        //update filesystem.
        throw "Error opening file";
    }
    //write object to file.
    file<<obj;
    _cacheMap.insert(pair<string, string>(key, obj));
    file.close();
}
//returns the object.
string FileCacheManager::get(string key){
    auto iter = _cacheMap.find(key);
    //if object not fount in cache
    if (iter == _cacheMap.end()) {
        string obj;
        //look up in filesystem. if not found return -1.
        string fileName(key);
        ifstream file(fileName,ios::binary);
        if (!file) {
            throw "File does not exist.";
        }
        //read it from file.
        //file.read(test, sizeof(test));
        getline(file, obj, '\r');
        if (!file) {
            throw "Error while trying to read from file";
        }
        //file.close();
        //return object from file.
        return obj;
        //if file is found in cache.
    }
    //return object from cache.
    return _cacheMap.find(key)->second;
}
#endif //EX2_EX2_H
