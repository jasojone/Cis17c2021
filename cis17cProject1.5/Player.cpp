/* 
 * File:   Player.h
 * Author: Jason
 *
 * Created on April 1, 2021, 8:25 AM
 */
#include "Player.h"

  /****************************************************************************\
  * displayTopCard                                                             *
  * This function will display the top card in play. It will use an if         *
  * statement to print the text description of the card. After the text we     *
  * will print the ascii art with subscript random access operators.           *
  \****************************************************************************/
void Player::displayTopCard()
{
    Card topCard = handInPlay.top();
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
    //
}

  /****************************************************************************\
  * readInput                                                                  *
  * Takes the user input and tests it to see if its an integer within range.   *
  * Precondition: int userChoice 0                                             *
  * Postcondition: dependent upon the user input, valid options are 1,2,3,4    *
  \****************************************************************************/
void Player::printHand()
{
    // creating a temporary clone of the stack of cards.
    stack<Card> tmp = this->handInPlay;
    
    // traverses though the entire list untill its empty.
    while (!tmp.empty())
    {
    Card topCard = tmp.top();
    cout << topCard.cardArt[topCard.suit][topCard.cPower] << endl;
    cout << topCard.cPower << " of " <<topCard.suit << endl;
    tmp.pop();
    }
}

  /****************************************************************************\
  * shuffleIn                                                                  *
  * This function is called periodically in the game to check if the player/cpu*
  * has depleted the cards in their hand in play. If the stack in play is      *
  * empty the function calls shuffle in (part of the Player class) which       *
  * shuffles the cards won pile and moves it to the hand in play.              *
  * Precondition: hand in play state                                           *
  * Postcondition: if hand in play is not 0 same, otherwise repopulates the    *
  * hand in play with cards won shuffled.                                      *
  \****************************************************************************/
void Player::shuffleIn()
{
    // shuffles the cards from beginning to end
    random_shuffle(cardsWon.begin(), cardsWon.end());
    
    // populates the hand in play with the freshly shuffled card. 
    // a for loop traverses through the entire won cards. 
    for (int i = cardsWon.size(); i > 0; i--)
    {
        handInPlay.push(cardsWon.back());
        cardsWon.pop_back();
    }
}

  /****************************************************************************\
  * setName                                                                    *
  * a setter to set a private variable of the user name.                       *
  \****************************************************************************/
void Player::setName(string outName)
{
    playerName = outName;
}

  /****************************************************************************\
  * getName                                                                    *
  * a getter for the playerName.                                               *
  \****************************************************************************/
string Player::getName()
{
    return playerName;

}
