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
#include <ctime>
using namespace std;



int main(int argc, char** argv) 
{
    //the enum automatically assigns a 0 to heads and a 1 to tails
    enum Coin {HEADS, TAILS}; 
    
    auto coinToss = []() // the return typ is automatically detected. 
    {
    return (rand() % 2) ? Coin::HEADS : Coin::TAILS;
    //return (rand() % 2)
    };
   
    srand(time(NULL));
    int n = 0;
    
    cout << "Flipping a coin 4 times and recording every event the coin lands "
            "heads 3 times and tails once. We will do this 10,000 times" << endl;
    
    for (int i = 0; i<10000; i++)
    {
        int h = 0;
        int t = 0;
        for (int j = 0; j < 4; j++)
        {
        if (coinToss() == Coin::HEADS)
            h++;
        else
            t++;     
        }
        if (h == 3 && t == 1)
        n++;
    }
    cout << "n = " <<  n   << endl;
    cout << "The probability of 3 heads and 1 tails for four flips done" <<
            " 10000 times is  " << n/10000.0 << endl;
    
    
    return 0;
}

