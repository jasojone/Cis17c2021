/* 
 * File:   Player.h
 * Author: Jason
 *
 * Created on April 1, 2021, 8:25 AM
 */
#include "Player.h"

void Player::displayTopCard()
{
    Card topCard = currHand.top();
    if (topCard.cPower < 11)
    {
        cout << topCard.cPower << " of " <<topCard.suit << endl;
    }

    else if (topCard.cPower == 11)
    {
        cout << "Jack" << " of " <<topCard.suit << endl;
    }

    else if (topCard.cPower == 12)
    {
        cout << "Queen" << " of " <<topCard.suit << endl;
    }

    else if (topCard.cPower == 13)
    {
        cout << "King" << " of " <<topCard.suit << endl;
    }

    else if (topCard.cPower == 14)
    {
        cout << "Ace" << " of " <<topCard.suit << endl;
    }
    cout << topCard.cardArt[topCard.suit][topCard.cPower] << endl;
}

void Player::printHand()
{
    stack<Card> tmp = this->currHand;
    while (!tmp.empty())
    {
    Card topCard = tmp.top();
    cout << topCard.cardArt[topCard.suit][topCard.cPower] << endl;
    cout << topCard.cPower << " of " <<topCard.suit << endl;
    tmp.pop();
    }
}

void Player::shuffleIn()
{
    
    random_shuffle(cardsWon.begin(), cardsWon.end());
    
    for (int i = cardsWon.size(); i > 0; i--)
    {
        currHand.push(cardsWon.back());
        cardsWon.pop_back();
    }
}


void Player::setName(string outName)
{
    playerName = outName;
}

string Player::getName()
{
    return playerName;

}
