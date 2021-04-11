/* 
 * File:   main.cpp
 * Author: Jason
 * Created on April 10, 2021, 4:42 PM
 */

#include <map>
#include <iostream>
#include <iterator>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    // empty map container
    map<int, int> mapRev;
    // inserting elements 
    mapRev.insert(pair<int, int>(1, 40));
    mapRev.insert(pair<int, int>(2, 30));
    mapRev.insert(pair<int, int>(3, 60));
    mapRev.insert(pair<int, int>(4, 20));
    mapRev.insert(pair<int, int>(5, 50));
    mapRev.insert(pair<int, int>(6, 50));
    mapRev.insert(pair<int, int>(7, 10));

    // printing mapRev
    map<int, int>::iterator itr;
    cout << "\nThe map mapRev is : \n";
    cout << "\tKEY\tELEMENT\n";
    
    for (itr = mapRev.begin(); itr != mapRev.end(); ++itr) 
    {
        cout << '\t' << itr->first
        << '\t' << itr->second << '\n';
    }
    cout << endl;
    
    cout << "Copy the mapRev over to mapRev2"<< endl;
    
    // assigning the elements from mapRev to mapRev2
    map<int, int> mapRev2(mapRev.begin(), mapRev.end());
    cout << "\nThe map mapRev2 is : \n";
    cout << "\tKEY\tELEMENT\n";
    
    for (itr = mapRev2.begin(); itr != mapRev2.end(); ++itr) 
    {
        cout << '\t' << itr->first
        << '\t' << itr->second << '\n';
    }
    cout << endl;
    
    // remove all elements up to
    // element with key=3 in mapRev2
    cout << "\nmapRev2 after removal of"
            " elements less than key a 3 : \n";
    cout << "\tKEY\tELEMENT\n";
    mapRev2.erase(mapRev2.begin(), mapRev2.find(3));
    for (itr = mapRev2.begin(); itr != mapRev2.end(); ++itr) 
    {
        cout << '\t' << itr->first
        << '\t' << itr->second << '\n';
    }
    
    // remove a specific element
    cout << "\nmapRev2 after removal of Key 5 \n";
    cout << "\tKEY\tELEMENT\n";
    mapRev2.erase(5);
    for (itr = mapRev2.begin(); itr != mapRev2.end(); ++itr) 
    {
        cout << '\t' << itr->first
        << '\t' << itr->second << '\n';
    }
    
    
    
    
    return 0;
}

