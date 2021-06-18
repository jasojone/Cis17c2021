/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
 * File:   main.cpp
 * Author: Jason
 *
 * Created on June 6, 2021, 9:28 PM
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;
typedef long long ll;
//Function Prototypes Here
void fillAry(int [],int,int,int);
void swap(int *a, int *b);
int selectionSort(int arr[], int n, ll &ops);
//int swap(int *xp, int *yp);

//Program Execution Begins Here
int main(int argc, char** argv) 
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=1000;
    int *array = new int[SIZE];
    int n = sizeof(array) / sizeof(array[0]);
    int lowRng=0,highRng=SIZE;
    int loopCnt = 1000;
    ll ops = 0;
    int p = 10000;
    
    //start time
    time_point<system_clock> start, end;
    duration<float> t = duration<float>::zero();
        
    //Loop through the array 1000 times
    for(int i = 0; i < loopCnt; ++i) 
    {
        fillAry(array,SIZE,highRng,lowRng);
        start = system_clock::now();
        selectionSort(array, p, ops);
        //operation += selSort(array,SIZE);
        t += system_clock::now() - start;
    }
    
    //Output operations
    cout<<"Array Size:      "<<SIZE<<endl;
    cout<<"Loop Count:      "<<p<<endl;
    cout<<"Operations:      "<<ops / loopCnt<<endl;
    cout<<"Average Time:    "<<t.count() / loopCnt<<" Seconds"<<endl;
    
    //Exit
    delete [] array;
    return 0;
}

//void swap(int *xp, int *yp)
//{
//    int temp = *xp;
//    *xp = *yp;
//    *yp = temp;
//    return 5;
//}
 
int selectionSort(int arr[], int n, ll &ops)
{
//    int ops = 3;
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    ops += 3;
    for (i = 0; i < n; i++)
    {
        // Find the minimum element in unsorted array
        ops += 4;
        min_idx = i;
        for (j = i+1; j < n; j++)
        {

          ops += 3;
          if (arr[j] < arr[min_idx])
            {
              ops ++;
              min_idx = j;
            }
          ops++;
        }
        // Swap the found minimum element with the first element
        ops+=4;
        swap(arr[min_idx], arr[i]);
    }
    return ops;
}
void fillAry(int a[],int n,int hr,int lr)
{
    for(int indx=0;indx<n;indx++)
    {
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}