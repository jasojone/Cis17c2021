/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on June 6, 2021, 9:28 PM
 * Problem 3 - Queues
Let us say you are in a line at the grocery store
or bank like I was last weekend.  One line, 
yet there are 3 clerks/tellers which service
the same line.  Simulate the following,
Clerk 1 - Services customers on the average 1/min
Clerk 2 - Services customers on the average 0.5/min
Clerk 3 - Services customers on the average 0.75/min
Customers - Arrive at 4/minute intervals.
When the line gets to 5 customers add one more Clerk
with the same service rate as Clerk 1. Add one more
clerk similarly for each 5 customers. Take tellers
away when they have serviced the line according to
how they were added. For instance, if a 4th clerk
was added to the line because there were 5 customers
waiting then remove the clerk when the customer count 
in line goes to zero.
What is my average customer wait time?
What is the max number of customers in the line.
If you randomize servicing and arrival times by +-50%
how does this change the results.
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
    srand(time(NULL));
    int seconds = 0;
    queue <int> cust;
    int addClerk = 0;
    int totalCust = 0;
    int totalTime = 0;
    int maxCust = 0;

    while (seconds < 3600) {
        if (seconds % 60 == 0) {
            if (cust.size() % 5 == 0) {
                addClerk++;
            }

            totalCust += 4;
            for (int i = 0; i < 4; i++) {
                cust.push(seconds);
            }
            maxCust = max(maxCust, static_cast<int> (cust.size()));
        }

        for (int i = 0; i < 1 + addClerk; ++i) {
            if (seconds % 60 == 0 && !cust.empty()) {
                totalTime += seconds - cust.front();
                cust.pop();
            }
        }

        if (seconds % 120 == 0 && !cust.empty()) {
            totalTime += seconds - cust.front();
            cust.pop();
        }

        if (seconds % 240 == 0 && !cust.empty()) {
            for (int i = 0; i < 3; ++i) {
                totalTime += seconds - cust.front();
                cust.pop();
            }
        }

        if (cust.empty()) {
            addClerk = 0;
        }
        seconds += 15;
    }
    int avgCnt = totalTime / totalCust;

    cout << "The average customer wait time is: " << avgCnt / 60.0 << " minutes" << endl;
    cout << "The longest customer queue is: " << maxCust << endl << endl;
    
    int r_seconds = 0;
    int r_addClerk = 0;
    int r_totalCust = 0;
    int r_totalTime = 0;
    int r_maxCust = 0;
    
    while (!cust.empty()) {
        cust.pop();
    }

    while (r_seconds < 3600) {
        if (r_seconds % (60 / 2 + rand() % 60) == 0) {
            if (cust.size() % 5 == 0) {
                r_addClerk++;
            }

            r_totalCust += 4;
            for (int i = 0; i < 4; i++) {
                cust.push(r_seconds);
            }
            r_maxCust = max(r_maxCust, static_cast<int> (cust.size()));
        }

        int random = 60 / 2 + rand() % 60;
        for (int i = 0; i < 1 + r_addClerk; ++i) {
            if (r_seconds % random == 0 && !cust.empty()) {
                r_totalTime += r_seconds - cust.front();
                cust.pop();
            }
        }

        if (r_seconds % 120 / 2 + rand() % 120 == 0 && !cust.empty()) {
            r_totalTime += r_seconds - cust.front();
            cust.pop();
        }

        if (r_seconds % (240 / 2 + rand() % 240) == 0 && !cust.empty()) {
            for (int i = 0; i < 3; ++i) {
                if (!cust.empty()) {
                    r_totalTime += r_seconds - cust.front();
                    cust.pop();
                }
            }
        }

        if (cust.empty())
            r_addClerk = 0;
        r_seconds += 1/.6;
    }
    avgCnt = r_totalTime / r_totalCust;

    cout << "After +-50% servicing and arrival times randomization: " << endl;
    cout << "The average customer wait time is: " << avgCnt / 60.0 << " minutes" << endl;
    cout << "The longest customer queue is: " << r_maxCust << endl;
    return 0;
}

