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
    return tgamma(n+1) / (tgamma(m+1) * tgamma(n-m+1));
}

int main(int argc, char** argv) 
{    
    float x = 0.5f;
        
    cout << "Using binomial theorem to simulate the, flipping of a coin 4 times "
            " and recording every event\nthe coin lands on heads 3 times and "
            "1 tails per trial. We will do this trial 10,000 times.\n" << endl;
    
    float probability = choose(4, 3) * powf(x, 3) * powf(1-x, 4-3);
    
    cout << "The probability of the trail getting the occurrence of 3 heads and" <<
            " 1 tails for four flips for\n10,000 trials is " << probability << 
            " and the percentage is " << probability*100 << "%\n" << endl;
    
    return 0;
}

