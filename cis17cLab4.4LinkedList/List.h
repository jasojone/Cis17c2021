/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: Jason
 *
 * Created on April 5, 2021, 9:12 PM
 */
#include <iostream>
#include "Link.h"

using namespace std;

#ifndef LIST_H
#define LIST_H

class List
{
    
public:
    Link* head;
    List(Link* fillList)
    {
        head = fillList;
    }
    //Prototype function you are to consider for Wednesday
    Link* create(int num)    //Create a Link with Data
    {
        Link* newLink = new Link;
        newLink->data = num;
        newLink->lnkNext = nullptr;

        return newLink;
    }
    void pshFrnt() //Push a link to the front
    {
        Link* newLink = create((rand() % 9 + 1));
        cout << "Pushing a " << newLink->data << " to the front of list..." << endl;
        newLink->lnkNext = head;
        head = newLink;
    }
    void pshBack() //Push a link to the end
    {
        Link* newLink = create((rand() % 10 + 1));
        cout << "Pushing a " << newLink->data << " to the back of list..." << endl;
        if (head == nullptr)
        {            
            head = newLink;
            return;
        }
        //temp node 
        Link* t = head;
        //traversing the list 
        for (; t->lnkNext != nullptr; t = t->lnkNext);
        //placing the node at the end
        t->lnkNext = newLink;
    }
    Link* popFrnt()      //Pull/pop a link from the front
    {
        if (head == nullptr)
            return nullptr;

        Link* victim = head;
        head = head->lnkNext;
        delete victim;
    }
    Link* popBack()      //Pull/pop a link from the back
    {
        if (head == nullptr)
            return nullptr;
        //traverses the list to find the last node to delete 
        for (Link* prev = head; prev != NULL; prev = prev->lnkNext)
        {
            if (prev->lnkNext->lnkNext == NULL)
            {
                //once the node is found replace the nullptr on the new last node
                //and delete the victim
                Link* victim = prev->lnkNext;
                prev->lnkNext = nullptr;
                victim->lnkNext = nullptr;
                delete victim;
            }
        }
    }
};

#endif /* LINK_H */