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
    vector<int> vecReview;
    //check the vector to see if it is empty 
    if (vecReview.empty() == false)
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
        vecReview.push_back(i); //use of push_back()
    }
    cout << endl;
    cout << "Output using the begin() and end() iterators\n ";
    for (auto i = vecReview.begin(); i != vecReview.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << "\nOutput using the cbegin() and cend() iterators\n ";
    for (auto i = vecReview.cbegin(); i != vecReview.cend(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << "\nOutput using the rbegin() and rend() iterators\n ";
    for (auto ir = vecReview.rbegin(); ir != vecReview.rend(); ++ir)
    {
        cout << *ir << " ";
    }
    cout << endl;
    cout << "\nOutput using crbegin() and crend() iterators\n ";
    for (auto ir = vecReview.crbegin(); ir != vecReview.crend(); ++ir)
    {
        cout << *ir << " ";
    }
    cout << endl;
    cout << "\nSize : " << vecReview.size()<< endl;
    cout << "\nCapacity : " << vecReview.capacity() << endl;
    cout << "\nMax_Size : " << vecReview.max_size() << endl;
  
    // resizes the vector size to 4
    vecReview.resize(4);
  
    // prints the vector size after resize()
    cout << "\nRe Size to : " << vecReview.size() << endl;
  
    // checks if the vector is empty or not
    if (vecReview.empty() == false)
    {
        cout << "\nVector is not empty" << endl;;
    }
    else
    {
        cout << "\nVector is empty";
    }
    // Shrinks the vector
    vecReview.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = vecReview.begin(); it != vecReview.end(); it++)
    {
        cout << *it << " ";
    }
    
    vecReview.resize(5);
    for (auto it = vecReview.begin(); it != vecReview.end(); it++)
    {
        cout << *it << " ";
    }
    
    
    
    
    return 0;
}

