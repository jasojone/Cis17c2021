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

void flipCoin()
{
    return (rand() > RAND_MAX/2) ? Coin::HEADS : Coin::TAILS;
}

int main(int argc, char** argv) 
{
    srand(time(NULL));
    int n = 0;
    cout << " probability" << endl;
    
    for (int i = 0; 1<10000; i++)
    {
        int h = 0;
        int t = 0;
        for (int j = 0; j < 4; j++)
        {
        if (flipCoin() == Coin::HEADS)
            h++;
        else
            t++;     
        }
        if (h == 3 && t == 1)
        n++;
    }


    
    
    return 0;
}

