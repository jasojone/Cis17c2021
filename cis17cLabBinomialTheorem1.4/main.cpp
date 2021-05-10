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
    // ternary operator although it is not needed
    return (rand() % 10 < 6) ? Coin::HEADS : Coin::TAILS;
    //return (rand() % 2)
    };
    
    srand(time(NULL));
    int n = 0;
    
       cout << "Flipping a loaded coin with a 60% probability of landing on " <<
               "heads 4 times and recording every\nevent the coin lands on " <<
               "heads 3 times and tails once. We will do this trial 10,000 times.\n" << endl;
       
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
    cout << "In 10,000 trials with the loaded coin there were " << n << 
            " occurrences where there was 3 heads and 1 tail.\n" << endl << endl;
    
    cout << "The probability of a loaded coin with a 60% chance for heads " <<
            "getting an occurrence of 3 heads and 1 tails is:\n" << 
            n/10000.0 << endl;
    
    
    return 0;
}

