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
    // The currDack is a vector of cards which will be used to populate the 
    // 52 cards that will be used for the game. A vector was used for the
    // purpose of random_shuffle 
    vector<Card> currDeck;
    // The suits are held in a list container to allow us to assign the 
    // 14 cards of each suit typ. A list was used to fulfill the requirements
    // of a list as well as iterators. 
    list<string> suits = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
    
public:
    Deck(); // default constructor will create the deck when instantiated. 
    void dealCards(Player &currPlayer); // deals the card 26 per player.
    void merge(vector<Card> &vec, int l, int m, int r);
    void mergeSort(vector<Card> &vec, int l, int r);
};
#endif /* DECK_H */

