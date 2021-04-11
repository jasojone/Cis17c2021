/* 
 * File:   main.cpp
 * Author: Jason
 * Created on April 10, 2021, 4:42 PM
 */

#include <cstdlib>
#include <list>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    list<int> vRev;
    //check the list to see if it is empty 
    if (vRev.empty() == false)
    {
        cout << "\nList is not empty" << endl;
    }
    else
    {
        cout << "\nList is empty" << endl;
    }
    //fill the list 
    for (int i = 1; i <= 10; i++)
    {
        vRev.push_back(i); //use of push_back()
    }
    cout << endl;
    cout << "Output using the begin() and end() iterators\n ";
    for (auto i = vRev.begin(); i != vRev.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << "\nOutput using the cbegin() and cend() iterators\n ";
    for (auto i = vRev.cbegin(); i != vRev.cend(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << "\nOutput using the rbegin() and rend() iterators\n ";
    for (auto ir = vRev.rbegin(); ir != vRev.rend(); ++ir)
    {
        cout << *ir << " ";
    }
    cout << endl;
    cout << "\nOutput using crbegin() and crend() iterators\n ";
    for (auto ir = vRev.crbegin(); ir != vRev.crend(); ++ir)
    {
        cout << *ir << " ";
    }
    cout << endl;
    
    cout << "\nHere is output using a for each loop\n";
    for (int forEach : vRev)
    {
        cout << forEach << " ";
    }
    cout << endl;
    
    //print the size using the .size() function
    cout << "\nSize : " << vRev.size()<< endl;

    //maz_sizer will show the maximum size of the list
    cout << "\nMax_Size : " << vRev.max_size() << endl;
  
    // resizes the list size to 4
    vRev.resize(4);
  
    // prints the list size after resize()
    cout << "\nRe Size to : " << vRev.size() << endl;
  
    // checks if the list is empty or not using empty()
    if (vRev.empty() == false)
    {
        cout << "\nList is not empty" << endl;;
    }
    else
    {
        cout << "\nList is empty";
    }
  
    // Shrinks the list
    //vRev.shrink_to_fit();
    cout << "\nList elements are: ";
    for (auto it = vRev.begin(); it != vRev.end(); it++)
    {
        cout << *it << " ";
    }    
    cout << "\n" << endl;
 
    return 0;
}

