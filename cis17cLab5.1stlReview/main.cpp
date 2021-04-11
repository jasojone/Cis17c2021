/* 
 * File:   main.cpp
 * Author: Jason
 * Created on April 10, 2021, 4:42 PM
 */

#include <map>
#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char** argv)
{
    // empty multimap container
    multimap<int, int> multimapRev;
    // inserting elements 
    multimapRev.insert(pair<int, int>(1, 50));
    multimapRev.insert(pair<int, int>(1, 50));
    multimapRev.insert(pair<int, int>(1, 50));
    multimapRev.insert(pair<int, int>(1, 50));
    multimapRev.insert(pair<int, int>(1, 50));
    multimapRev.insert(pair<int, int>(1, 50));
    multimapRev.insert(pair<int, int>(1, 50));

    // printing multimapRev
    multimap<int, int>::iterator itr;
    cout << "\nThe multimap multimapRev is : \n";
    cout << "\tKEY\tELEMENT\n";
    
    for (itr = multimapRev.begin(); itr != multimapRev.end(); ++itr) 
    {
        cout << '\t' << itr->first
        << '\t' << itr->second << '\n';
    }
    cout << endl;
    
    cout << "Copy the multimapRev over to multimapRev2"<< endl;
    
    // assigning the elements from multimapRev to multimapRev2
    multimap<int, int> multimapRev2(multimapRev.begin(), multimapRev.end());
    cout << "\nThe multimap multimapRev2 is : \n";
    cout << "\tKEY\tELEMENT\n";
    
    for (itr = multimapRev2.begin(); itr != multimapRev2.end(); ++itr) 
    {
        cout << '\t' << itr->first
        << '\t' << itr->second << '\n';
    }
    cout << endl;
    
    return 0;
}

