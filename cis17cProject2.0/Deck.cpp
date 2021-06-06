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
Deck Constructor                                                            
The default constructor will create the 52 cards using the card class       
elements                                                                    
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
        
        //Sort using a recurisive mergeSort
        mergeSort(currDeck, 0, currDeck.size()-1);

        // using the random access iterator 
        random_shuffle(currDeck.begin(), currDeck.end());
    }

/*****************************************************************************\
dealCards                                                                   
This function will take the deck of 52 cards and populate each players hand 
with 26 cards each.                                                         
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

/*****************************************************************************\
merge  

Merges two subvectorss of vec[] First subvectors is vec[l..m] Second subvectors is 
vec[m+1..r]
\*****************************************************************************/
void Deck::merge(vector<Card> &vec, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp vectors 
    vector<Card> L(n1);
    vector<Card> R(n2);

    // Copy data to temp vectors
    for (int i = 0; i < n1; i++)
        L[i] = vec[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[m + 1 + j];

    // Merge the temp vectors back into vec[l..r]

    // Initial index of first subvectors
    int i = 0;

    // Initial index of second subvectors
    int j = 0;

    // Initial index of merged subvectors
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i].cPower <= R[j].cPower) {
            vec[k] = L[i];
            i++;
        }
        else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}


/*****************************************************************************\
mergeSort
 l is for left index and r is right index of the subvectors of vec to be sorted 
\*****************************************************************************/
void  Deck::mergeSort(vector<Card> &vec, int l, int r) {
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(vec, l, m);
        mergeSort(vec, m + 1, r);
        merge(vec, l, m, r);
    }
}
