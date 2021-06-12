/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   HashMap.h
  * Author: Jason
  *
  * Created on June 9, 2021, 9:28 AM
  */



#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <ctime>
#include <map>
#include <iomanip>

using namespace std;

class MyHashMap
{
private:
    class HashNode
    {
    private:
        int _key;
        int _nodeSize;
        string _initials;


    public:
        HashNode* next;
        HashNode()
        {
            _key = -1;
            _initials = "";
            next = NULL;
            _nodeSize = 0;
        }

        HashNode(int key, string val)
        {
            this->_key = key;
            this->_initials = val;
            next = NULL;
        }

        void setKey(int key)
        {
            _key = key;
        }

        void setVal(string val)
        {
            _initials = val;
        }

        int getKey()
        {
            return _key;
        }

        string getInitial()
        {
            return _initials;
        }

        int getSize()
        {
            return _nodeSize;
        }

        void setSize(int size)
        {
            _nodeSize = size;
        }
    };

    int _size = 512;
    HashNode* myHash;
    map<int, int> collisoins;

public:
    /** Initialize your data structure here. */
    MyHashMap();
    /** value will always be non-negative. */
    void put(int key, string value);
    /* Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    string get(int key);
    /* Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key, string initials);
    int search(int key, string initials);
    map<int, int> getCollisions();
    int hashIdx(int key);
    int getSize();


};

#endif /* HASHMAP_H */