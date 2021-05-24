/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on May 18, 2021, 11:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

float fg(float);

int main(int argc, char** argv) 
{

    for (int x = -10; x <= 10; x++)
    {
        cout << "g(" << x / 10.0 << ") = ";
        cout <<  fg(x / 10.0) << endl;
    }
    return 0;
}

float fg(float x)
{
    if(abs(x) < 1e-6)
    {
        return x - (pow(x,3) / 6);
    }
    
    x /= 2;
    float fgx = fg(x);
    return 2*fgx / (1+pow(fgx, 2));
}

