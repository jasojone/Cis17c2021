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
#include <list>
using namespace std;

 /*****************************************************************************\
 * Deck                                                                        *
 * The Deck class will contain the attributes of the deck of cards.            *
 * Attributes: a vector of cards, a string array with suits for map keys.      *
 \*****************************************************************************/
class Deck 
{
private:
    vector<Card> currDeck;
    //const string suits[4] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
    list<string> suits = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
    
public:
    Deck(); // default constructor will create the deck when instantiated. 
    void dealCards(Player &currPlayer); // deals the card 26 per player.
};
#endif /* DECK_H */

