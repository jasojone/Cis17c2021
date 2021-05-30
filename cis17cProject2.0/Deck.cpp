/* 
 * File:   Deck.cpp
 * Author: Jason
 *
 * Created on April 4, 2021, 9:04 PM
 * 
 * 
 */
#include "Deck.h"

 /*****************************************************************************\
 * Deck Constructor                                                            *
 * The default constructor will create the 52 cards using the card class       *
 * elements                                                                    *
 \*****************************************************************************/
Deck::Deck()
    {
        // Due to the decks private variable of suits being a list an iterator
        // was used to traverses through the suits, there is a total of four 
        // suits traversing through the list from the begin and end will reach 4
        for (list<string>::iterator itr = suits.begin(); itr != suits.end(); itr++)
        {
            // traverses though the powers of each suit and populates the deck
            // with suited cards.
            for (int j = 2; j <= 14; j++)
            {
                // emplace is used over 
                currDeck.emplace_back(Card(*itr, j));
            }
        }
        // once the deck is populated it is then shuffled for play.
        // using the random access iterator 
        random_shuffle(currDeck.begin(), currDeck.end());
    }

 /*****************************************************************************\
 * dealCards                                                                   *
 * This function will take the deck of 52 cards and populate each players hand *
 * with 26 cards each.                                                         *
 \*****************************************************************************/
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

