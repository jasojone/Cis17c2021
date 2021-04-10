/*
 * To change head license header, choose License Headers in Project Properties.
 * To change head template file, choose Tools | Templates
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
#include "Link.h"
class List
{
private:
public:
    //creating the head of the list
    Link* head;
    
    
    //call fill list to fill the list
    List(Link* fillList)
    {
        head = fillList;
        
        for(Link* tmp = head; tmp->lnkNext != nullptr; tmp = tmp->lnkNext)
        {
            tmp->lnkNext->lnkPrv = tmp;
        }
    }
    //Prototype function you are to consider for Wednesday
    Link* create(int num)    //Create a Link with Data
    {
        Link* newLink = new Link;
        newLink->data = num;
        newLink->lnkNext = nullptr;
        newLink->lnkPrv = nullptr;

        return newLink;
    }
    ~List(){
        delete head;
    }
    void pshFrnt() //Push a link to the front
    {
        Link* newLink = create(1);
        cout << "Pushing a " << newLink->data << " to the front of list..." << endl;
        head->lnkPrv = newLink;
        newLink->lnkNext = head;        
        head = newLink;
    }
    void pshBack() //Push a link to the end
    {
        Link* newLink = create(6);
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
        newLink->lnkPrv = linkPtr;
    }
    Link* popFrnt()      //Pull/pop a link from the front
    {   
        //if link is not head do nothing
        if (head == nullptr)
            return nullptr;

        Link* victim = head;
        head = head->lnkNext;
        head->lnkPrv = nullptr;
        delete victim;
    }
    Link* popBack()      //Pull/pop a link from the back
    {
        //if empty do  nothing
        if (head == nullptr)
            return nullptr;
        //traverses the list to find the last node to delete             
        for (Link* prevLink = head; prevLink != nullptr; prevLink = prevLink->lnkNext)
        {
            if (prevLink->lnkNext->lnkNext == nullptr)
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
        Link* newLink = create((rand() % 5 + 1));
        Link* prevLink = nullptr;
        Link* linkPtr;
        int num = newLink->data;
        cout<< "Pushing a "<< num <<" on the list" << endl;
        
        //if there is no links create one and make it the head
        if (!head)
        {
            head = newLink;
            newLink->lnkNext = nullptr;
            newLink->lnkPrv = nullptr;
            
        }
        else //otherwise insert the new link
        {
            //position linkPtr a the head of the list
            Link* linkPtr = head;
            Link* prevPrevLink = nullptr;
            
            //initialize prevLinkious link to nullptr
            prevLink = nullptr;
            
            //skip all values which are less than link to be inserted 
            while (linkPtr != nullptr && linkPtr->data < num)
            //while (linkPtr != nullptr && linkPtr->data < linkPtr->data)
            {
                if (prevLink != nullptr)
                {
                    prevPrevLink = prevLink;
                }
                prevLink = linkPtr;
                linkPtr = linkPtr->lnkNext;
                    
            }
            //if the new node is to be the first node in the list,
            //insert it before all other links
            if (prevLink == nullptr)
            {
                head = newLink;
                newLink->lnkNext = linkPtr;
                newLink->lnkPrv = nullptr;
            }
            else //otherwise insert after the prevLinkious link
            {
                prevLink->lnkNext = newLink;
                newLink->lnkNext = linkPtr;
                newLink->lnkPrv = prevPrevLink;
            }
        }
        return nullptr; 
    }
    
    void deleteLink(int num)
    {
        Link* linkPtr; //To traverse the list
        Link* prevLink; // to point to the previous link
        
        //If the list is empty do nothing
        if (!head)
            return;
        
        //Determine if the first node is the one
        if (head->data == num)
        {
            linkPtr = head->lnkNext;
            cout << "Deleted the " << &head << 
                        " from the linked list" << endl; 
            delete head;
            head = linkPtr;
        }
        
        else 
        {
            //Initialize linkPtr to head of list
            linkPtr = head;
            //Skip all links whose value member is
            // not equal to num
            while (linkPtr != nullptr && linkPtr->data != num)
            {
                prevLink = linkPtr;
                linkPtr = linkPtr->lnkNext;
            }
            
            //If linkPtr is not at the end of the list
            //link the previous link to the link after
            //linkPtr, then delete linkPtr
            if (linkPtr)
            {
                prevLink->lnkNext = linkPtr->lnkNext;
                cout << "Deleted the " << linkPtr->data << 
                        " from the linked list" << endl;
                delete linkPtr;
            }
        }
    }

};

#endif /* LINK_H */




        
        