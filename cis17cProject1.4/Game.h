/* 
 * File:   Game.h
 * Author: Jason
 *
 * Created on April 17, 2021, 9:04 PM
 */

#ifndef GAME_H
#define GAME_H
#include <thread>         // this_thread::sleep_for
#include <chrono>         // chrono::seconds
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

class Game
{
private:
    //Map for Shortest Games
    //Map for Longest Games
public:
    Game()
    {
       //Read from the file and fill in maps for the scores
        //readScoresFromFile();
    }
    ~Game()
    {
        //Write the maps for scores into the file
       //writeScoresToFile();
    }
    void displayWelcome();
    void mainMenu();
    void gameLoop();
    void rules();
    void scoreBoard();
    void pressAnyKey();
    void war(Player &p1, Player &cpu, int &playCount);
    void shuffleIn(Player &p1, Player &cpu);
    void checkIfEnough(Player &p1, Player &cpu, bool &gameOver);
    
    // work to be done
    void writeScoresToFile();
    void readScoresFromFile();
};
#endif /* GAME_H */

