/* 
 * File:   main.cpp
 * Author: Jason
 * Created on April 10, 2021, 4:42 PM
 */

#include <queue>
#include <iostream>
using namespace std;
// printQue will print the queue 
// while queue is not empty loop
void printQue(queue<int> queCopy)
{
    queue<int> que = queCopy;
    
    while (!que.empty()) {
        cout << " " << que.front() << ",";
        que.pop();
    }
    cout << '\n';
}
  
int main()
{
    queue<int> qRev;
    // use push to fill the queue
    qRev.push(10);
    qRev.push(20);
    qRev.push(30);
  
    cout << "The queue qRevs contents are: ";
    printQue(qRev);
  
    
    cout << "\nqRev.size() : " << qRev.size();
    
    cout << "\nqRev.front() : " << qRev.front();
    
    cout << "\nqRev.back() : " << qRev.back();
  
    cout << "\nqRev.pop() : ";
    
    qRev.pop();
    
    printQue(qRev);
  
    return 0;
}
