/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on May 19, 2021, 12:01 AM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

float c(float x);
float s(float x);


int main(int argc, char** argv) 
{

    float x = atan(1);
    cout << c(x) << endl;
    return 0;
}

float c(float x)
{
    if(abs(x) < 1e-6)
    {
        return (1/x) + (x/6);
    }
    x /= 2;
    float ci = c(x), si = s(x);
    return 0.5 * (ci * si);
}

float s(float x)
{
    if(abs(x) < 1e-6)
    {
        return 1 + (pow(x,2)/2);
    }
    x /= 2;
    float ci = c(x), si = s(x);
    return (pow(ci,2) * pow(si,2)) / (pow(ci,2) - pow(si,2));
}