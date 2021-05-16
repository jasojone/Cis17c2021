/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on May 10, 2021, 4:52 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
// this will return n^1/2 
void sqrtN(long)
{
    cout << "n^1/2" << endl;
    cout << pow(s, 2) << endl; 
    cout << pow(m, 2) << endl;
    cout << pow(h, 2) << endl; 
    cout << pow(d, 2) << endl; 
    cout << pow(mon, 2) << endl; 
    cout << pow(y, 2) << endl; 
    cout << pow(cen, 2) << endl; 
    cout << pow(dec, 2) << endl << endl; 
}
// this will return n^1/3 
void cbrtN(long s, long m, long h, long d, long mon, long y, long cen, long dec)
{
    cout << "n^1/3" << endl;
    cout << pow(s, 3) << endl; 
    cout << pow(m, 3) << endl;
    cout << pow(h, 3) << endl; 
    cout << pow(d, 3) << endl; 
    cout << pow(mon, 3) << endl; 
    cout << pow(y, 3) << endl; 
    cout << pow(cen, 3) << endl; 
    cout << pow(dec, 3) << endl << endl; 
}
// this will return n*log(n) 
void logN(long s, long m, long h, long d, long mon, long y, long cen, long dec)
{
    cout << "n*log(n)" << endl;
    cout << s*log(s) << endl; 
    cout << s*log(m) << endl;
    cout << s*log(h) << endl; 
    cout << s*log(d) << endl; 
    cout << s*log(mon) << endl; 
    cout << s*log(y) << endl; 
    cout << s*log(cen) << endl; 
    cout << s*log(dec) << endl << endl; 
}


int main(int argc, char** argv) {


    // in milliseconds 
    unsigned long s = 1000;
    unsigned long m = s * 60;
    unsigned long h = m * 60;
    unsigned long d = h * 24 ;
    unsigned long mon = d * 30;
    unsigned long y = d * 365;
    unsigned long dec = y * 10;
    unsigned long cen = dec * 10;
    
    sqrtN( s,  m,  h,  d,  mon,  y,  cen,  dec);
    
    cbrtN( s,  m,  h,  d,  mon,  y,  cen,  dec);
    
    logN( s,  m,  h,  d,  mon,  y,  cen,  dec);
    
    cout << "n^2" << endl;
    sqrtN(s);
    sqrtN(m);
    sqrtN(h);
    sqrtN(d);
    sqrtN(mon);
    sqrtN(y);
    sqrtN(dec);
    sqrtN(cen);
    
    cout << "2^n" << endl;
    twoSqrtN(s);
    twoSqrtN(m);
    twoSqrtN(h);
    twoSqrtN(d);
    twoSqrtN(mon);
    twoSqrtN(y);
    twoSqrtN(dec);
    twoSqrtN(cen);
    
    



    
    

    
    return 0;
}

