/* 
 * File:   main.cpp
 * Author: Jason Jones
 * Created on April 01, 2021, 10:14 AM
 * 
 * Cis17c Project1.0 WAR
 * 
 /*****************************************************************************\
 * This program will consist of the card game War. One of my favorite card     *
 * games growing up War has a special place in my memories. This program will  *
 * demonstrate the use of concepts in the Object Orientated methodology of     *
 * programming and the use of the Standard Template Library.                   *
 \*****************************************************************************/

#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include "Game.h"

int main(int argc, char** argv) 
{
    // Creates a new games instance.
    Game curGame;
    // Display the welcome ASCII art message.
    curGame.displayWelcome();
    // Calls the main menu for the game. 
    curGame.mainMenu();

    return 0;
}


  



