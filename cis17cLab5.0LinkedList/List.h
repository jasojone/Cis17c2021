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
        Link* linkPtr = head;
        //traversing the list 
        for (; linkPtr->lnkNext != nullptr; linkPtr = linkPtr->lnkNext);
        //placing the node at the end
        linkPtr->lnkNext = newLink;
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
        for (Link* prevLink = head; prevLink != NULL; prevLink = prevLink->lnkNext)
        {
            if (prevLink->lnkNext->lnkNext == NULL)
            {
                //once the node is found replace the nullptr on the new last node
                //and delete the victim
                Link* victim = prevLink->lnkNext;
                prevLink->lnkNext = nullptr;
                victim->lnkNext = nullptr;
                delete victim;
            }
        }
    }
    
    Link* insertNode()
    {
        Link* newLink = create((rand() % 10 + 1));
        Link* prevLink = nullptr;
        Link* linkPtr;
        int num;
        newLink->data = num;
        cout << num << endl;
        //if there is no links create one and make it the head
        if (!head)
        {
            head = newLink;
            newLink->lnkNext = nullptr;          
        }
        else //otherwise insert the new link
        {
            //position linkPtr a the head of the list
            Link* linkPtr = head;
            
            //initialize prevLinkious link to nullptr
            prevLink = nullptr;
            
            //skip all values which are less than link to be inserted 
            //while (linkPtr != nullptr && linkPtr->data < num)
            while (linkPtr != nullptr && linkPtr->data < linkPtr->data)
            {
                prevLink = linkPtr;
                linkPtr = linkPtr->lnkNext;
            }
            //if the new node is to be the first node in the list,
            //insert it before all other links
            if (prevLink == nullptr)
            {
                head = newLink;
                newLink->lnkNext = linkPtr;
            }
            else //otherwise insert after the prevLinkious link
            {
                prevLink->lnkNext = newLink;
                newLink->lnkNext = linkPtr;
            }

        }
    }
    
    Link* deleteNode()
    {
        if (head == nullptr)
            return nullptr;
        
        Link* victim = head;
        
        
    }
    
};

#endif /* LINK_H */