/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HashMap.h"

MyHashMap::MyHashMap()
{
    myHash = new HashNode[_size];
}

void MyHashMap::put(int key, string initials)
{
    int i = hashIdx(key);

    if (myHash[i].getKey() == -1)
    {
        myHash[i].setKey(key);
        myHash[i].setVal(initials);
        myHash[i].setSize(1);
    }
    else
    {
        HashNode* tmp;
        int size = 1;
        for (tmp = &myHash[i]; tmp->next != NULL; tmp = tmp->next)
        {
            size++;
        }
        tmp->next = new HashNode(key, initials);
        size++;
        myHash[i].setSize(size);
    }
}

string MyHashMap::get(int key)
{
    int i = hashIdx(key);
    return (myHash[i].getKey() == -1) ? "Key is Empty" : myHash[i].getInitial();
}

void MyHashMap::remove(int key, string initials)
{
    int i = hashIdx(key);

    if (myHash[i].getKey() != -1)
    {
        myHash[i].setKey(-1);
        myHash[i].setVal("");
    }
}

int MyHashMap::search(int key, string initials)
{
    int i = hashIdx(key);

    if (myHash[i].getKey() == key && myHash[i].getInitial() == initials)
    {
        return 1;
    }
    else
    {
        int t = 1;
        for (HashNode* tmp = &myHash[i]; tmp != NULL; tmp = tmp->next, t++)
        {
            if (tmp->getKey() == key && tmp->getInitial() == initials)
                return t;
        }
    }

    return 0;
}

map<int, int> MyHashMap::getCollisions()
{
    map<int, int> returnMap;

    for (int i = 0; i < _size; i++)
    {
        cout << i << ": ";
        cout << myHash[i].getInitial();

        if (myHash[i].next != NULL)
        {
            for (HashNode* tmp = myHash[i].next; tmp != nullptr; tmp = tmp->next)
            {
                cout << ", " << tmp->getInitial();
            }
        }

        cout << endl;
    }

    for (int i = 0; i < _size; i++)
    {
        if (myHash[i].getKey() != -1)
        {
            returnMap[myHash[i].getSize()]++;
        }
        else
        {
            returnMap[0]++;
        }
    }

    return returnMap;
}

int MyHashMap::hashIdx(int key)
{
    return (key % _size);
}

int MyHashMap::getSize()
{
    return _size;
}

