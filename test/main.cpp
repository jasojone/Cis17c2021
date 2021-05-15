/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on May 14, 2021, 11:05 PM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int n = 1;
    int x = 1;
    
    while(n*x <= 1000)
    {
        x++;
        n*=x;
    }
    cout << n << " " << x << endl;

    return 0;
}

