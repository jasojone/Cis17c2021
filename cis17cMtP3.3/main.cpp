/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 *           Also overloading the == operator in this version of Object
 *           Simple Vector using Linked List
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;
using namespace chrono;

//User Libraries
#include "Object.h"       //2D Object
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    const int SIZE = 2;
    int loopCnt = 1000;
    long long operations = 0LL;
    SimpleVector<Object> svl(1);
    time_point<system_clock> start, end;
    
    start = system_clock::now();
    for(int i = 1; i <= loopCnt; ++i)
    {
        Object o(SIZE);
        operations += svl.push(o);
    }
    duration<float> dur = system_clock::now() - start;
    cout<<"Object Size:     "<<loopCnt<<" Pushed"<<endl;
    cout<<"Operations:      "<<operations<<endl;
    cout<<"Time to Push:    "<<dur.count()<<" Seconds"<<endl;;

    return 0;
}