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
        loop = 600000, 
        count = 0;
    
    float three = 0, 
          four = 0, 
          twoPair = 0, 
          onePair = 0;

    for(int i = 0; i < loop; ++i)
    {
        vector<int> deck(13, 0);
        int pairs = 0;

        for(int i = 0; i < 4; ++i)
        {
            deck[rand()%13]++;
        }

        for(int j = 0; j < deck.size(); ++j)
        {
            switch(deck[j]) 
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
    
    cout << "Simulations of card combinations: " << endl;
    cout << "One Pair:       " << onePair/loop * 100 << "%" << endl;
    cout << "Two Pair:       " << twoPair/loop * 100 << "%" << endl;
    cout << "Three Pair:     " << three/loop * 100 << "%" << endl;
    cout << "Four of a kind: " << four/loop * 100 << "%" << endl;
    
    return 0;
}
