/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
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
#include "Object.h"       //2D Objects
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here
int main(int argc, char** argv) 
{
    const int SIZE = 2;
    int loopCnt = 10000;
    long long operations = 0LL;
    SimpleVector<Object> v;
    time_point<system_clock> start, end;
    
    //Input loopCnt
    cout<<"Loops: "<<loopCnt<<endl;
    
    for(int i = 1; i <= loopCnt; ++i) 
    {
        if(i % 1000 == 0) 
        {
            start = system_clock::now();
        }
        
        Object o(SIZE);
        operations = v.push(o);
        
        if(i % 1000 == 0) {
            duration<float> t = system_clock::now() - start;
            cout<<"Element Number       "<<i<<" pushed\n";
            cout<<"Operations to push:  "<<operations<<"\n\n";
            cout<<"Time to push:        "<<t.count()<<" Seconds\n\n";
        }
    }
    return 0;
}