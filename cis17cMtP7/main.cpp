#include<iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <algorithm>
 
 using namespace std;
 
int main () 
{
    srand(static_cast<unsigned int>(time(0)));
   
    int faces = 13,
        loopCnt = 600000; 
    
    float three = 0, 
          four = 0, 
          twoPair = 0, 
          onePair = 0;

    for(int i = 0; i < loopCnt; ++i)
    {
        vector<int> deck(13, 0);
        int pairs = 0;

        for(int i = 0; i < 4; ++i)
        {
            deck[rand()%13]++;
        }

        for(int i = 0; i < deck.size(); ++i)
        {
         
            switch(deck[i]) 
            {
                case 2: 
                    ++pairs;
                    break;
                case 3:
                    ++three;
                    break;
                case 4:
                    ++four;
                    break;
            }
        }

        if(pairs == 1)
        {
            onePair++;
        }
        else if(pairs == 2)
        {
            twoPair++;
        }
    }
    
    cout << "Simulated Probability of Card Combinations: " << endl;
    cout << "One Pair:       " << onePair/loopCnt * 100 << "%" << endl;
    cout << "Two Pair:       " << twoPair/loopCnt * 100 << "%" << endl;
    cout << "Three Pair:     " << three/loopCnt * 100 << "%" << endl;
    cout << "Four of a kind: " << four/loopCnt * 100 << "%" << endl;
    
    return 0;
}
