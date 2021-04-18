/* 
 * File:   Deck.h
 * Author: Jason
 *
 * Created on April 14, 2021, 8:25 AM
 */
#ifndef DECK_H
#define DECK_H
#include "Player.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class Deck 
{
private:
    vector<Card> currDeck;
    const string suits[4] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
    
public:
    Deck()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j <= 14; j++)
            {
                currDeck.emplace_back(Card(suits[i], j));
            }
        }
        random_shuffle(currDeck.begin(), currDeck.end());
    }
    //virtual ~deck();
    void dealCards(Player &currPlayer)
    {
        for (int i = 0; i < 26; i++)
        {
            currPlayer.currHand.push(currDeck.back());
            currDeck.pop_back();
        }
    }
};
#endif /* DECK_H */

