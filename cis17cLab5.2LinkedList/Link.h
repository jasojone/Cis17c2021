/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose:Linked from first principles
 */

#ifndef LINK_H
#define LINK_H

struct Link
{
    int data;     //Some type of data
    int size;      //
    Link *lnkNext; //Next Link in the chain
    Link *lnkPrv; //pointer to the previous link
};

#endif /* LINK_H */

