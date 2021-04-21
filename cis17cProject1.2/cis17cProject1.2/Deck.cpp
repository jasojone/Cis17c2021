/*
 * File:   Deck.cpp
 * Author: Jason
 *
 * Created on April 17, 2021, 9:04 PM
 *
 *
 */
#include "Deck.h"

Deck::Deck()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 2; j <= 14; j++)
        {
            currDeck.emplace_back(Card(suits[i], j));
        }
    }
    random_shuffle(currDeck.begin(), currDeck.end());
}

void Deck::dealCards(Player& currPlayer)
{
    for (int i = 0; i < 26; i++)
    {
        currPlayer.currHand.push(currDeck.back());
        currDeck.pop_back();
    }
}

