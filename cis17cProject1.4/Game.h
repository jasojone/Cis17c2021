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

void displayWelcome();
void mainMenu();
void gameLoop();
void rules();
void scoreBoard();



#endif /* GAME_H */

