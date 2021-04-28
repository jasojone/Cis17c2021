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

class Player 
{
private:
    string playerName;
public:
    stack<Card> currHand;
    vector<Card> cardsWon;
    queue<Card> war;
    
    void displayTopCard();
    void collectWon();
    void printHand();
    void shuffleIn();
    void setName(string );
    string getName();
};

#endif /* PLAYER_H */
