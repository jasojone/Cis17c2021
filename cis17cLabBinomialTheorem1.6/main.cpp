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
    float x = 0.6f;
    
    cout << "Using binomial theorem to simulate the, " <<
            "flipping of a loaded coin with a 60% probability of landing on\n" <<
            "heads 4 times and recording every event the coin lands on " <<
            "heads 3 times and tails once.\nWe will do this 10,000 times\n" << endl;
    
    
    float probability = choose(4, 3) * powf(x, 3) * powf(1-x, 4-3);
    
    cout << "The probability of a loaded coin with a 60% chance for heads " <<
            "getting an occurrence of 3 heads and 1 tails\nfor 10,000 trials is: " <<  
            probability << " and the percentage is " << probability*100 << "%\n" << endl;
    
    return 0;
}

