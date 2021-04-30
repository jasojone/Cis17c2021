/* 
 * File:   Player.h
 * Author: Jason
 *
 * Created on April 1, 2021, 8:25 AM
 */
 /*****************************************************************************\
 * This header will contain the players hands and the display of the card in   *
 * play                                                                        *
 \*****************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

 /*****************************************************************************\
 * Player                                                                      *
 * The Player class will contain the attributes of the player.                 *
 * Attributes: players name string, hand in play stack, cards won vector,      *
 * war cards queue.                                                            *
 \*****************************************************************************/
class Player 
{
private:
    string playerName; // hold players name.
public:
    // hand in play used to pull cards from for each play a stack was used 
    // for its simple nature only the top card needs to be accessed. 
    stack<Card> handInPlay; 
    // cards won is used to hold all the cards won from battles and wars
    // a vector was used so that once the cards in hand in play run out
    // we can simply use an algorithm to shuffle the cards before returning
    // them to the hand in play. 
    vector<Card> cardsWon; 
    // the war queue is used to hold the cards offered for war as well as 
    // the cards that initiate the war in the first place. A queue was used
    // to fulfill the assignment requirements. 
    queue<Card> war;
    
    void displayTopCard(); // displays top card.
    void printHand(); // used to print the hand for testing.
    void shuffleIn(); // shuffles the cards won and returns them to the hand in play.
    void setName(string ); // setter for the player name.
    string getName(); // getter for the player name. 
};

#endif /* PLAYER_H */

