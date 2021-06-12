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

using namespace std;

/*
 psudo
for (int i = 1; i < 1000; i++)
queue.push(0);
queue.push(0);
queue.push(0);
queue.push(0);
int maxCust = max(maxCust, queue.size());
totalWaitTime += queue.size();
queue.pop(); // Clerk 1
if(cust >= 5) //Do clerk 2
if(cust >= 10) // Do clerk 3
if(cust >= 15) {
  cust -= 10; 
  int howManyNewClerks = (cust + 4) / 5;//take the celling 
  //Then remove that many clerks
}
average
sum of the queuesize at every interation/((4) * (# of iterations)) 
change the # of +-.5 to each 
 */
int main(int argc, char** argv) {
    deque<int> mydeck(4, 1);
    queue <int> cust(mydeck);
    queue<int> extraClerks;
    int maxCust = 0;
    int maxExtraClerks = 0;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int otherClerks = 0;

    for (int i = 1; i < 3600; i++) //3600 seconds = 1 hour
    {
        if (i % 60 == 0) //Check to see if 1 minute has passed, if so add 4 more cust to the que
        {
            for (int j = 0; j < 4; j++)
                cust.push(1);

            if (cust.size() > maxCust) //Check to see how many people are in que, if bigger than maxCust then cust.size becomes new max of cust that were in line
                maxCust = cust.size();
        }
            
        if ((cust.size() % 5 == 0) && (i % 60 == 0)) //Check cust que to see if we need more clerks to help out
        {
            extraClerks.push(1);

            if (extraClerks.size() > maxExtraClerks) //Keep track of how many extra clerks we needed
                maxExtraClerks = extraClerks.size();
        }
        
        if (i % 60 == 0 || i == 1) // check to see if 1 minute passes to pop one cust off cuz clerk 1 is done with them
        {
            if (!cust.empty()) {
                c1++;
                cust.pop();
            }
        }
        if (i % 120 == 0 || i == 1) //check to see if 30 second has passed because clerk 2 works on 1 cust every 30 seconds
        {
            if (!cust.empty()) {
                c2++;
                cust.pop();
            }
        }
        if (i % 45 == 0 || i == 1) //Check to see if .75 minutes passed to pop off cust that clerk 3 has worked on
        {
            if (!cust.empty()) {
                c3++;
                //c3 += 0.75;
                cust.pop();
            }
        }
        
        if (i % 60 == 0) //Extra clerk processing if statement
        {
            for (int j = 0; j < extraClerks.size(); j++) //For loop for each etra clerk to process a cust
            {
                if (!cust.empty()) {
                    otherClerks++;
                    cust.pop();
                }
            }
        }

        if (cust.size() == 0) //If our cust que is 0 we don't need the extra clerks anymore so remove them all
        {
            while (!extraClerks.empty())
                extraClerks.pop();
        }       
    }

    cout << "que size: " << cust.size() << endl;
    cout << "clerk 1  " << c1 << endl;
    cout << "clerk 2  " << c2 << endl;
    cout << "clerk 3  " << c3 << endl;
    cout << "Additional clerk " << otherClerks << endl;
    cout << "Maximum clerks " << maxExtraClerks + 3 << endl;
    cout << "Maximum customer que " << maxCust << endl;
    //cout << "Average customer wait time " <<  << endl;
    

    return 0;
}

