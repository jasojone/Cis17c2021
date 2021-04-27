/* 
 * File:   Game.h
 * Author: Jason
 *
 * Created on April 1, 2021, 9:04 PM
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
    //make everything private and use getters and setters
    //map<int, string> longestHighScores;
public:
    Game()
    {
        //inFile("inFile.in"), outFile("outFile.out");
        //Read from the file and fill in maps for the scores
        readScoresFromFile();
    }
    ~Game()
    {
       //Write the maps for scores into the file
       //writeScoresToFile();
    }
    // Map for Shortest Games score for key value for player name this will 
    // sort the scores for you as maps 
    // Map for Longest Games
    multimap<int, string> highScore;
    //ifstream inFile;
    //ofstream outFile;
    void displayWelcome();
    void mainMenu();
    void gameLoop();
    void rules();
    double readInput(int userChoice);
    void war(Player &p1, Player &cpu, int &playCount);
    void shuffleIn(Player &p1, Player &cpu);
    //void checkIfEnough(Player &p1, Player &cpu, bool &gameOver);
    
    // work to be done
//    void scoreBoard();
    void readScoresFromFile();
    void writeScoresToFile(int, string);
};
#endif /* GAME_H */

