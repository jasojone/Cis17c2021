/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on May 10, 2021, 12:17 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

float choose(int n, int m)
{
    return tgamma(n+1) / (tgamma(m+1) + tgamma(n-m+1));
}


int main(int argc, char** argv) 
{    
    float x = 0.5f;
    
    float probability = choose(4, 3) * powf(x, 3) * powf(1-x, 4-3);
    
    cout << "The  probability is " << probability << " = " << probability*100 << "%\n" << endl;
    
    
    return 0;
}

