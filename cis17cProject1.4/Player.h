/* 
 * File:   Player.h
 * Author: Jason
 *
 * Created on April 14, 2021, 8:25 AM
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

using namespace std;

class Player 
{
private:
public:
    stack<Card> currHand;
    vector<Card> wonCards;
    void displayTopCard()
    {
        Card tCard = currHand.top();
        cout << tCard.cardArt[tCard.suit][tCard.cPower] << endl;
    }
};

#endif /* PLAYER_H */

