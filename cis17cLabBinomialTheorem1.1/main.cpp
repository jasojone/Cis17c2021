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

enum Coin {HEADS, TAILS}

Coin coinToss()
{
    
    const int MIN_VALUE = 1, MAX_VALUE = 2;
    
    
    int coin;
    
    coin = (rand() % (MAX_VALUE - MIN_VALUE +1)) + MIN_VALUE;
    
    return (coin == MIN_VALUE) ? Coin::HEADS : Coin::TAILS;
    
}

int main(int argc, char** argv) 
{
    srand(time(NULL));
    int n = 0;
    
    for (int i = 0; 1<10000; i++)
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
        f (h == 3 && t == 1)
        n++;
    
    }

    
    
    return 0;
}

