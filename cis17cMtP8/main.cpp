/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on May 17, 2021, 4:22 PM
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
 
 
int main(int argc, char** argv) 
{
   
    srand(static_cast<unsigned int>(time(0)));
   
    float passes = 0;
   
    for(int i = 0; i < pow(10,6); i++)
    {
        int bit = 0;
        
        vector<int> v(100, 0);
        for(int i = 0; i < 40; i++)
        {
            v[i] = 1;
        }
        
        for(int i = 0; i < 5; i++)
        {
            int pos = rand()%100;
            if(v[pos] == 1)
            {
                bit++;
            }
        }
        if(bit == 5)
        {
            passes++;
        }
    }
   
    cout<<"Given a biased coin analogy, if a bit vector is 40% full\n"
        <<"the odds that 5 bits randomly chosen fall within section are: "
        <<(passes/pow(10,6))*100<<"%\n"
        <<"The Calculated Probability: "<<pow(0.4, 5) * 100<<"%"<<endl;
 
    return 0;
}


