/* 
 * File:   main.cpp
 * Author: Jason
 * Created on April 10, 2021, 4:42 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    vector<int> vRev;
    //check the vector to see if it is empty 
    if (vRev.empty() == false)
    {
        cout << "\nVector is not empty" << endl;
    }
    else
    {
        cout << "\nVector is empty" << endl;
    }
    //fill the vector 
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
    //print out the capacity of the vector using the capacity() function
    cout << "\nCapacity : " << vRev.capacity() << endl;
    //maz_sizer will show the maximum size of the vector
    cout << "\nMax_Size : " << vRev.max_size() << endl;
  
    // resizes the vector size to 4
    vRev.resize(4);
  
    // prints the vector size after resize()
    cout << "\nRe Size to : " << vRev.size() << endl;
  
    // checks if the vector is empty or not using empty()
    if (vRev.empty() == false)
    {
        cout << "\nVector is not empty" << endl;;
    }
    else
    {
        cout << "\nVector is empty";
    }
  
    // Shrinks the vector
    vRev.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = vRev.begin(); it != vRev.end(); it++)
    {
        cout << *it << " ";
    }    
    cout << "\n" << endl;
    // Assign vector
    vector<int> vRev2;
  
    // fill the array with 10 five times using assign()
    cout << "Filling the vector with five 10s" << endl;
    vRev2.assign(5, 10);
  
    cout << "The vector elements are: ";
    for (int i = 0; i < vRev2.size(); i++)
        cout << vRev2[i] << " ";
    cout << "\n" << endl;
    
    // inserts 20 to the last position using push_back()
    vRev2.push_back(20);
    cout << "Inserting a 20 a the end of the vector";
    int n = vRev2.size();
    //using size as a placeholder to easily determine the last element 
    cout << "\nThe last element is: " << vRev2[n - 1];
    cout << endl;
    // removes last element with pop_back()
    cout << "Removing the 20 from the end using pop_back()";
    vRev2.pop_back();
  
    // prints the vector
    cout << "\nThe vector elements are: ";
    for (int i = 0; i < vRev2.size(); i++)
        cout << vRev2[i] << " ";
    cout << endl;
    // inserts 5 at the beginning
    cout << "\nInserting a 5 at the beginning using insert()" << endl;
    vRev2.insert(vRev2.begin(), 5);
  
    cout << "The first element is: " << vRev2[0] << endl;
  
    cout << "The vector with a 5 inserted at the beginning \n ";
    for (auto i = vRev2.begin(); i != vRev2.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << "\nRemoving the 5 from the beginning" << endl;
    // removes the first element
    vRev2.erase(vRev2.begin());
    
    cout << "The vector with the 5 removed at the beginning \n ";
    for (auto i = vRev2.begin(); i != vRev2.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << "\nThe first element is now: " << vRev2[0] << endl;
  
    // inserts at the beginning
    cout << "\nInserting a 5 at the beginning using emplace()" << endl;
    vRev2.emplace(vRev2.begin(), 5);
    cout << "The first element is: " << vRev2[0]<<endl;
    
    cout << "The vector with a 5 emplaced at the beginning \n ";
    for (auto i = vRev2.begin(); i != vRev2.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
      
    // Inserts 20 at the end
    cout << "\nThe vector with a 20 emplaced at the end \n";
    vRev2.emplace_back(20);
    n = vRev2.size();
    cout << "The last element is: " << vRev2[n - 1]<<endl;
    for (auto i = vRev2.begin(); i != vRev2.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    // erases the vector
    cout << "\nErasing the vector" << endl;
    vRev2.clear();
    cout << "Vector size after erase(): " << vRev2.size();
  
    // two vector to perform swap
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
  
    cout << "\n\nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
  
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
  
    // Swaps v1 and v2 with the swap()
    v1.swap(v2);
  
    cout << "\nAfter Swap \nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
  
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    return 0;
}

