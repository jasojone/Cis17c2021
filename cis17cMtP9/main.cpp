/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on May 17, 2021, 5:49 PM
 */

#include <cstdlib>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

float recOn(float, int);
float recOlogN(float, int);


int main(int argc, char** argv) 
{
    
    int base, 
        exponent;
    
//    float ops1, 
//          ops2;
    
//    time_point<system_clock> start, end;
    
    cout << "Input a base:"<<endl;
    cin >> base;
    cout << "Input an exponent: "<< endl;
    cin >> exponent;
//    start = system_clock::now();
    cout << "O(n):       " << recOn(base, exponent) << endl;
//    cout << "Operations: " << ops1 << endl << endl;
//    duration<float> t = system_clock::now() - start;
//    cout<<"Time to run O(n):    "<<t.count()<<" Seconds"<<endl;
//    
//    start = system_clock::now();
    cout << "O(logn):    " << recOlogN(base, exponent) << endl;
//    cout << "Operations: " << ops2 << endl << endl;
//    cout<<"Time to run O(log2(n)):    "<<t.count()<<" Seconds"<<endl;
    
    return 0;
}


float recOn(float num, int exponent)
{
    if(exponent>1)
    {
//        ops1 += 3;
        return recOn(num, exponent-1) * num;
    }
    return num;
}

float recOlogN(float num, int exponent)
{
    if(exponent%2==0 && exponent> 0)
    {
//        ops2 += 4;
        float i = recOlogN(num, exponent/2);
        return i*=i;
    }
    
    else if (exponent> 0)
    {
//        ops2 += 3;
        return recOlogN(num, exponent-1) * num;
    }
    
    else return 1;
}
