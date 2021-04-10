/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 16, 2020, 7:50 PM
 * Edited: Jason Jones 
 * 3/15/21   
 * Purpose:  To Test and Modify the Simple Vector
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Global Constants

//Function prototypes
void fillVec(SimpleVector<unsigned char> &);
void prntVec(SimpleVector<unsigned char> &,int);

//Execution Begins Here
int main(int argc, char** argv) 
{
    //Declare Variables
    unsigned char size=50;
    unsigned int nPush=5; 
    //SimpleVector<unsigned char> sv();
    Link<int> List;
//    //Fill the Vector
//    fillVec(sv);
//    
//    //Print the Vector
//    cout << "The Vector before the alterations:\n";
//    prntVec(sv,10);
    
    //Push a random value into the array
    for(int i=0;i<nPush;i++)
    {
        //sv.push_back(rand()%26+65);
       SimpleVector->push_back(rand()%26+65);
    }
    //Print the Vector
    cout << "The Vector after the push back:\n";
    prntVec(sv,10);
    
    //pop the last value off the array
    for(int i=0;i<nPush;i++)
    {
        sv.pop_back();
    }
    //Print the Vector
    cout << endl << "The Vector after the pop back:\n";
    prntVec(sv,10);
    
    for(int i=0;i<nPush;i++)
    {
        sv.push_front(rand()%26+65);
    }
    //Print the Vector
    
    cout << endl << "The Vector after the push front:\n";
    prntVec(sv,10);
    
     for(int i=0;i<nPush;i++)
    {
        sv.pop_front();
    }
    //Print the Vector
    cout << endl << "The Vector after the pop front:\n";
    prntVec(sv,10);
    
    
//    //Copy the Vector
//    SimpleVector<unsigned char> copysv(sv);
//    
//    //Print the Vector
//    prntVec(copysv,10);

    return 0;
}

void prntVec(Link<int> &sv,int perLine){
    cout<<endl;
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
//
//void fillVec(SimpleVector<unsigned char> &sv){
//    for(int i=0;i<sv.size();i++){
//        sv[i]=rand()%26+65;
//    }
//}


