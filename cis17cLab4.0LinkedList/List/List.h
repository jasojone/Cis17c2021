/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: Jason
 *
 * Created on April 3, 2021, 9:50 AM
 */

#ifndef LIST_H
#define LIST_H
#include "Link.h"

class List 
{
private:
    
public:
    List();
    List(const List& orig);
    virtual ~List();
    
    //Prototype function you are to consider for Wednesday
    Link *create(int);    //Create a Link with Data
    void pshFrnt(Link *); //Push a link to the front
    void pshBack(Link *); //Push a link to the end
    Link *popFrnt();      //Pull/pop a link from the front
    Link *popBack();      //Pull/pop a link from the back
};

#endif /* LIST_H */

