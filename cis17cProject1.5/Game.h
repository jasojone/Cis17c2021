/* 
 * File:   Game.h
 * Author: Jason
 *
 * Created on April 1, 2021, 9:04 PM
 */

#ifndef GAME_H
#define GAME_H
#include <thread> 
#include <chrono>
#include <fstream>          
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <queue>
#include "Player.h"
#include "Card.h"
#include "Game.h"
#include "Deck.h"
#include "Player.h"
 /*****************************************************************************\
 * Game                                                                        *
 * This class is a designed to hold all the attributes of the game. This will  *
  * allow for the main function to maintain a minimalistic appearance.         *
 \*****************************************************************************/
class Game
{
public:
    // the default constructor will call the function that reads scores from 
    // the text file and populate the map to print the scores. 
    Game()
    {
        readScoresFromFile();
    }

    multimap<int, string> highScores; // high scores container.
    void displayWelcome(); // displays the welcome intro.
    void mainMenu(); // displays the main menu and begins to gain user input.
    void gameLoop(); // the main game loop.
    void rules(); // displays the rules. 
    double readInput(int userChoice); // checks if user input is valid for main menu.
    void war(Player &p1, Player &cpu, int &playCount); // runs the logic for war loop.
    void playerShuffleIn(Player &p1, Player &cpu); // shuffles cards from won cards and puts them into the hand in play.
    void scoreBoard(); // displays the score board.
    void readScoresFromFile(); // reads scores from the file and populates the score board multimap
    void writeScoresToFile(); // writes scores from the multimap to file 
    void displayWar(); // displays was acsii art to reduce redundancy. 
    void testCounters(Player p1, Player cpu, int playCount); // test function to count all cards in their respective containers. 
};
#endif /* GAME_H */

