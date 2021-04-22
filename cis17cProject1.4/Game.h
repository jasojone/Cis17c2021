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

void displayWelcome();
void mainMenu();
void gameLoop();
void rules();
void scoreBoard();
void pressAnyKey();
void war(Player &p1, Player &cpu);
void shuffleIn(Player &p1, Player &cpu);

#endif /* GAME_H */

