/* 
 * File:   Deck.h
 * Author: Jason
 *
 * Created on April 1, 2021, 8:25 AM
 */
#ifndef DECK_H
#define DECK_H
#include "Player.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
//#include <deque>
#include <list>

using namespace std;

class Deck 
{
private:
    vector<Card> currDeck;
    const string suits[4] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
    
public:
    Deck();
    void dealCards(Player &currPlayer);
    //void collectWon();
};
#endif /* DECK_H */

