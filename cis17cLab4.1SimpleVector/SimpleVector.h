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
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int arrayCapacity; //crate the capacity 
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   void timesTwo();  // Doubles the array size when capacity is reached 
   void reduceToQtr(); // Reduces the array size when there is 1/4 of total size

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }
   
   //Accessor to return the count
   int getCount() const {return this->arrayCapacity;}

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
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
void SimpleVector<T>::timesTwo()
{
    //Create a temporary array double the size of the original
    T *tmp=new T[this->arraySize*2];
    
    //Copy the array over to the temporary array
    for(int i=0;i<this->arraySize;i++){
        tmp[i]=this->aptr[i];
    }
    
    //Delete the old array
    delete [] this->aptr;
    
    //assign the new array and double
    this->aptr=tmp;
    this->arraySize*=2;
}

//***********************************************************
// 
//
//***********************************************************

template <class T>
void SimpleVector<T>::reduceToQtr(){
    //Create a temporary array 1/4 the size of the original
    T *tmp=new T[this->arraySize/4];
    
    //Copy the array over to the temporary array
    for(int i=0;i<this->count;i++){
        tmp[i]=this->aptr[i];
    }
    
    //Delete the old array
    delete [] this->aptr;
    
    //assign the new array and quarter 
    this->aptr=tmp;
    this->arraySize/=4;
}

//***********************************************************
// 
//
//***********************************************************

template <class T>
void SimpleVector<T>::push_back(T val)
{
    
    //Create an array 1 size larger than the old array
    T *tmpV = new T[arraySize+1];
    
    //Copy the old array in to the new
    for(int i = 0; i <= arraySize; i++)
        *(tmpV + i) = *(aptr + i);
    
    //Place the new value at the end of the new array
    *(tmpV + arraySize+1) = val;
        
    //Delete the old array
    delete[] aptr;
    
    //Increment the array size by 1 and set the old pointer to 
    //  the new array pointer
    arraySize++;
    aptr = tmpV;
}

//***********************************************************
// 
//
//***********************************************************

template <class T>
void SimpleVector<T>::pop_back()
{
    //Create an array 1 size smaller than the old array
    T *tmpV = new T[arraySize-1];
    
    //Copy the old array in to the new
    for(int i = 0; i < arraySize-1; i++)
        *(tmpV + i) = *(aptr + i);
      
    //Delete the old array
    delete[] aptr;
    
    //Decrement the array size by 1 and set the old pointer to 
    //  the new array pointer
    arraySize--;
    aptr = tmpV;      
}

//***********************************************************
// 
//
//***********************************************************

template <class T>
void SimpleVector<T>::push_front(T val)
{
    //Create an array 1 size larger than the old array
    T *tmpV = new T[arraySize+1];
    
    //Copy the old array in to the new
    for(int i = 1; i <= arraySize; i++)
        *(tmpV + i) = *(aptr + i - 1);
    
    //Place the new value at the front of the new array
    tmpV[0] = val;
    
    //Delete the old array
    delete[] aptr;
    
    //Increment the array size by 1 and set the old pointer to 
    //  the new array pointer
    arraySize++;
    aptr = tmpV; 
}

//***********************************************************
// 
//
//***********************************************************

template <class T>
void SimpleVector<T>::pop_front()
{
    //Create an array 1 size larger than the old array
    T *tmpV = new T[arraySize-1];
    
    //Copy the old array in to the new
    for(int i = 0; i <= arraySize; i++)
        tmpV[i] = *(aptr + i); 
    
    //Delete the old array
    delete[] aptr;
    
    //Increment the array size by 1 and set the old pointer to 
    //  the new array pointer
    arraySize--;
    aptr = tmpV;     
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int i = 0; i < arraySize; i++)
      *(aptr + i) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int i = 0; i < arraySize; i++)
      *(aptr + i) = *(obj.aptr + i);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
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

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif