/*
* File:   SimpleVector.h
 * Author: rcc
 *
 * Created on September 16, 2020, 8:10 PM
 * Edited: Jason Jones 
 * 4/5/21   
 */

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include "Link.h"
using namespace std;

template <class T>
class List
{
private:
   Link<T> *head;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int arrayCapacity; //crate the capacity 
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   List()
      { head = nullptr; arraySize = 0;}
      
//   // Constructor declaration
   List(int size)
   {
       head = nullptr;
       arraySize = size;
       for (int i = 0; i < size; i++)
       {
           push_back(static_cast<T>(rand()%26+65));
       }
   }
//   
//   // Copy constructor declaration
//   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~List();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }
   
   //Accessor to return the count
   int getCount() const {return this->arrayCapacity;}

   // Accessor to return a specific element
   //T getElementAt(int position);

   // Overloaded [] operator declaration
   //T &operator[](const int &);
   
   // Push a value onto the end of the array
   void push_back(T);
   // Pop a value off the end of the array
   void pop_back();
   // Push a value onto the front of the array
   void push_front(T);
   // Pop a value off the front of the array
   void pop_front();
   
};

//***********************************************************
// 
//
//***********************************************************
template <class T>
Link<T>* create(T num)    //Create a Link with Data
{
    Link<T>* newLink = new Link<T>;
    newLink->data = num;
    newLink->lnkNext = nullptr;

    return newLink;
}

template <class T>
void SimpleVector<T>::push_back(T val)
    {
        Link<T>* newLink = create(val);
        cout << "Pushing a " << newLink->data << " to the back of list..." << endl;
        if (head == nullptr)
        {            
            head = newLink;
            return;
        }
        //temp node 
        Link<T>* linkPtr = head;
        //traversing the list 
        for (; linkPtr->lnkNext != nullptr; linkPtr = linkPtr->lnkNext);
        //placing the node at the end
        linkPtr->lnkNext = newLink;
        
        arraySize++;
    }

//***********************************************************
//                                                          *
//                                                          *
//***********************************************************

template <class T>
void SimpleVector<T>::pop_back()
{
    if (head != nullptr)
    {
        //traverses the list to find the last node to delete 
        for (Link<T>* prevLink = head; prevLink != nullptr; prevLink = prevLink->lnkNext)
        {
            if (prevLink->lnkNext->lnkNext == nullptr)
            {
                //once the node is found replace the nullptr on the new last node
                //and delete the victim
                Link<T>* victim = prevLink->lnkNext;
                prevLink->lnkNext = nullptr;
                victim->lnkNext = nullptr;
                delete victim;
            }
        }  

        arraySize--;
    }
}

//***********************************************************
// 
//
//***********************************************************

template <class T>
void SimpleVector<T>::push_front(T val)
{
    Link<T>* newLink = create(val);
    cout << "Pushing a " << newLink->data << " to the front of list..." << endl;
    newLink->lnkNext = head;
    head = newLink;
    arraySize++;
}
//***********************************************************
// 
//
//***********************************************************

template <class T>
void SimpleVector<T>::pop_front()
{
    if (head != nullptr)
    {
        Link<T>* victim = head;
        head = head->lnkNext;
        delete victim;
        arraySize--;
    }
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

//template <class T>
//SimpleVector<T>::SimpleVector(int s)
//{
//   arraySize = s;
//   // Allocate memory for the array.
//   try
//   {
//      aptr = new T [s];
//   }
//   catch (bad_alloc)
//   {
//      memError();
//   }
//
//   // Initialize the array.
//   for (int i = 0; i < arraySize; i++)
//      *(aptr + i) = 0;
//}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

//template <class T>
//SimpleVector<T>::SimpleVector(const SimpleVector &obj)
//{
//   // Copy the array size.
//   arraySize = obj.arraySize;
//   
//   // Allocate memory for the array.
//   aptr = new T [arraySize];
//   if (aptr == 0)
//      memError();
//      
//   // Copy the elements of obj's array.
//   for(int i = 0; i < arraySize; i++)
//      *(aptr + i) = *(obj.aptr + i);
//}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
       delete head;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

//template <class T>
//T SimpleVector<T>::getElementAt(int sub)
//{
//   if (sub < 0 || sub >= arraySize)
//      subError();
//   return aptr[sub];
//}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

//template <class T>
//T &SimpleVector<T>::operator[](const int &sub)
//{
//   if (sub < 0 || sub >= arraySize)
//      subError();
//   
//   return head[sub];
//}
#endif