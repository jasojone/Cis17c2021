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
    int loopCnt = 100000;
    long long operations = 0LL;
    SimpleVector<Object> svp(1);
    time_point<system_clock> start, end;
    
    start = system_clock::now();
    for (int i = 0; i < loopCnt; i++)
    {
        Object o(SIZE);
        operations += svp.push(o);
    }
        
    duration<float> t = system_clock::now() - start;
    cout<<"Object Size  "<<loopCnt<<endl;
    cout<<"Operations:  "<<operations<<endl;
    cout<<"Push Time:   "<<t.count()<<" Seconds"<<endl;
    
    return 0;
}
