/* 
 * File:   Deck.cpp
 * Author: Jason
 *
 * Created on April 4, 2021, 9:04 PM
 * 
 * 
 */
#include "Deck.h"

Deck::Deck()
    {
        // traverses through the suits of the deck.
        for (list<string>::iterator itr = suits.begin(); itr != suits.end(); itr++)
        {
            // traverses though the powers of each suit and populates the deck
            // with suited cards.
            for (int j = 2; j <= 14; j++)
            {
                currDeck.emplace_back(Card(*itr, j));
            }
        }
        // once the deck is populated it is then shuffled for play.
        random_shuffle(currDeck.begin(), currDeck.end());
    }

void Deck::dealCards(Player &currPlayer)
{
    // for loop deals the cards to each player 26 to each player
    for (int i = 0; i < 26; i++)
    {
        // pushes the cards to the hand in play form the deck then pops them 
        // off the current deck. 
        currPlayer.handInPlay.push(currDeck.back());
        currDeck.pop_back();
    }
}

