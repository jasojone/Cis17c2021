/* 
 * File:   Game.cpp
 * Author: Jason
 *
 * Created on April 17, 2021, 9:04 PM
 * 
 * Game.cpp will contain the games main loop and all the games functions
 */

#include "Game.h"

ofstream scoreB ("scoreBoard.txt");

  /****************************************************************************\
  * displayWelcom                                                              *
  * This function will simply display the welcome screen and message.          *  
  \****************************************************************************/
void Game::displayWelcome()
{
    cout << string(50, '\n');
    cout <<"`7MMF'     A     `7MF'     `7MM                            "
        "                      mm                 \n";
    cout <<"  `MA     ,MA     ,V         MM                            "
        "                      MM                 \n";
    cout <<"   VM:   ,VVM:   ,V .gP\"Ya   MM  ,p6\"bo   ,pW\"Wq.`7MMpMM"
        "Mb.pMMMb.  .gP\"Ya      mmMMmm ,pW\"Wq.  \n"; 
    cout <<"    MM.  M' MM.  M',M'   Yb  MM 6M'  OO  6W'   `Wb MM    MM"
        "    MM ,M'   Yb       MM  6W'   `Wb      \n";
    cout <<"    `MM A'  `MM A' 8M''''''  MM 8M       8M     M8 MM    MM"
        "    MM 8M''''''       MM  8M     M8      \n";
    cout <<"     :MM;    :MM;  YM.    ,  MM YM.    , YA.   ,A9 MM    MM"
        "    MM YM.    ,       MM  YA.   ,A9      \n";
    cout <<"      VF      VF    `Mbmmd'.JMML.YMbmd'   `Ybmd9'.JMML  JMM"
        "L  JMML.`Mbmmd'       `Mbmo`Ybmd9'       \n";
    this_thread::sleep_for (chrono::seconds(1));
    cout << string(100, '\n');

    cout << "\t`7MMF'     A     `7MF' db      `7MM''''Mq.  \n";
    cout << "\t  `MA     ,MA     ,V  ;MM:       MM   `MM.  \n";
    cout << "\t   VM:   ,VVM:   ,V  ,V^MM.      MM   ,M9   \n";
    cout << "\t    MM.  M' MM.  M' ,M  `MM      MMmmdM9    \n";
    cout << "\t    `MM A'  `MM A'  AbmmmqMA     MM  YM.    \n";
    cout << "\t     :MM;    :MM;  A'     VML    MM   `Mb.  \n";
    cout << "\t      VF      VF .AMA.   .AMMA..JMML. .JMM. \n\n";
    this_thread::sleep_for (chrono::seconds(1));
    cout << string(100, '\n');

    cout << "\t  mm   `7MM                  \n";
    cout << "\t  MM     MM                  \n";
    cout << "\tmmMMmm   MMpMMMb.  .gP\"Ya   \n";
    cout << "\t  MM     MM    MM ,M'   Yb   \n";
    cout << "\t  MM     MM    MM 8M''''''   \n";
    cout << "\t  MM     MM    MM YM.    ,   \n";
    cout << "\t  `Mbmo.JMML  JMML.`Mbmmd'   \n\n";

    cout << "\t   .g8'''bgd                      `7MM      .g8'''bgd       \n";
    cout << "\t .dP'     `M                        MM    .dP'     `M       \n";
    cout << "\t dM'       ` ,6'Yb.  `7Mb,od8  ,M''bMM    dM'       `  ,6\"Yb."
            "  `7MMpMMMb.pMMMb.  .gP\"Ya \n";
    cout << "\t MM         8)   MM    MM' \"',AP    MM    MM          8)   MM"
            "    MM    MM    MM ,M'   Yb \n";
    cout << "\t MM.         ,pm9MM    MM    8MI    MM    MM.    `7MMF',pm9MM"
            "    MM    MM    MM 8M''''''  \n";
    cout << "\t `Mb.     ,'8M   MM    MM    `Mb    MM    `Mb.     MM 8M   MM"
            "    MM    MM    MM YM.    ,  \n";
    cout << "\t   `''bmmmd' `Moo9^Yo..JMML.   `Wbmd'MML. `''bmmmdPY  `Moo9^Yo"
            "..JMML  JMML  JMML.`Mbmmd'  \n\n";
    this_thread::sleep_for (chrono::seconds(1));
    cout << string(100, '\n');
}
  /****************************************************************************\
  * mainMenu                                                                   *
  * This function will display the main menu. The use will have options to     *
  * play war, see the rules, check the score board and exit the game.          *
  * Variables: userChoice holds the users menu choice, userName holds the user *
  * name for high scores,                                                      *
  \****************************************************************************/
void Game::mainMenu()
{
    srand(time(0)); // Random seed for the shuffle algorithm. 
    int userChoice = 0; // Sets the user choice outside the range of the menu.
    
    while(userChoice != 4) 
    {
        //Main menu output
        cout << "---------------------------\n";
        cout << "|        Main Menu        |\n";
        cout << "---------------------------\n";
        cout << "1) Play WAR\n";
        cout << "2) Rules\n";
        cout << "3) Score Board\n";
        cout << "4) Exit Game ";
        cout << string(10, '\n'); //moves menu up a bit from the bottom      
        // Takes user input for main menu.
        cin >> userChoice;
        // Clear the screen completely with printing out 100 new lines.
        cout << string (100, '\n');

        // Switch statement handles the main menu.
        switch (userChoice)
        {
            case 1: // starts the game loop.
                cout << "Lets play WAR!\n";
                gameLoop();
                break;

            case 2: // will display the rules.
                rules();
                break;

            case 3: // will display the Score Board.
                cout << "Score Board";
                break;
            case 4: // end the game and exit.
                cout << "Thank you for playing!\n";
                break;
        }
    }
}
void Game::gameLoop()
{
    // userName holds the username for high scores, the following line will 
    // clear the input buffer and the following will gather the user input
    // for the userName.
    string userName; 
    cout << "Enter your Name:\n";
    cin.ignore();
    getline(cin, userName);
    int playCount = 0;
    // gameOver bool controls the game over sequence, this is part of the 
    // do while conditions in the game loop.
    bool gameOver = false; 
    
    // Deck class instantiation refer to Deck.h for build and implementation.
    Deck gameDeck; 
    // Creating the instance of the player and cpu player, refer to the 
    // Player.h for build and implementation.
    Player p1;
    Player cpu;
      
    cout << "Dealing Cards...\n\n";
    
    // dealCards() is called and deal the deck 26 cards to each player.
    gameDeck.dealCards(p1);
    //p1.printHand();

    gameDeck.dealCards(cpu);
    //cpu.printHand();    
    
    cout << "The Battle Begins!\n\n";
   
    // The do while loop is the main game loop that will contain all the 
    // game logic. 
    
    do
    {
        // Output the card total of each player
        cout << "You have " 
                << p1.cardsWon.size()+p1.currHand.size() << " cards total\n";
        cout << "The CPU has " 
                << cpu.cardsWon.size()+cpu.currHand.size() << " cards total\n";
        cout << "Play count " << playCount << endl;
        cout << "Your hand in play " << p1.currHand.size() << '\n';
        cout << "your winnings " << p1.cardsWon.size() << '\n';
        cout << "CPU's hand in play " << cpu.currHand.size() << '\n';
        cout << "CPU's winnings " << cpu.cardsWon.size() << '\n';
        cout << "WAR queue " << p1.war.size() + cpu.war.size() << endl;
        cout << "Total cards in play " << p1.cardsWon.size()+p1.currHand.size()
                + cpu.cardsWon.size()+cpu.currHand.size() << '\n';
        cout << "Your Cards" << endl;
        //p1.printHand();
        cout << "cpu's cards" << endl;
        //cpu.printHand();
        
        // shuffleIn will check currHand Size to see if any player still has 
        // cards on the stack to play with, if not shuffle the cardsWon and 
        // pop them onto the currHand stack for play.
        shuffleIn(p1, cpu);
        
        // Crates a new card instance that is a place holder for the top 
        // card of the current hand in play this will be used to push back
        // the cards when won.
        Card p1Top = p1.currHand.top();
        Card cpuTop = cpu.currHand.top();        

        // This will display the cards in play. 
        cout << "Your Card:\n";
        p1.displayTopCard();
        
        cout << "VS\n"; 
        // count the hand
        playCount++;
        
        cout << "Computers Card:\n";
        cpu.displayTopCard();
        
        // if p1s hand is the winning hand
        if (p1Top.cPower > cpuTop.cPower)
        {
            cout << "You won the round!\n";
            cout << "Press Enter to continue\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Taking your winnings.\n";
            
            // push the cards in play that are won onto the cardsWon pile
            p1.cardsWon.push_back(p1Top);
            p1.cardsWon.push_back(cpuTop);
            // pop the cards off the hands in play
            p1.currHand.pop();
            cpu.currHand.pop();
            // clear the screen
            cout << string (100, '\n');
        }
        
        // if cpu wins the hand
        else if (cpuTop.cPower > p1Top.cPower)
        {
            cout << "You lost the round.\n";
            cout << "Press Enter to continue\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "CPU takes the winnings.\n";
            
            // push the cards in play that are won to the cpu cards won pile
            cpu.cardsWon.push_back(p1Top);
            cpu.cardsWon.push_back(cpuTop);
            // pop the cards off the hands in play
            p1.currHand.pop();
            cpu.currHand.pop(); 
            cout << string (100, '\n');         
        }
        
        // if the cards are equal then go to war
        else
        {   
            // condition for war
            while (p1.currHand.top().cPower == cpu.currHand.top().cPower)
            {
                // check if p1 has enough cards for war
                if (p1.currHand.size() + p1.cardsWon.size() <= 4)
                {
                cout << "You do not have Cards to go to war with.\n"
                     << "You forfeit the Game." << endl;
                gameOver = true; // end game loop
                }

                // check if cpu has enough cards for war
                else if (cpu.currHand.size() + cpu.cardsWon.size() <= 4)
                {
                cout << "The CPU has no Cards to go to war with.\n"
                     << "The CPU forfeits the Game." << endl;
                gameOver = true; // end game loop
                }
                // call war loop
                war(p1, cpu, playCount);
            }
        }
        
        // check to see if players have cards to play the game
        if (p1.currHand.size() + p1.cardsWon.size() <= 1)
        {
        cout << "You do not have Cards.\n"
             << "You forfeit the Game." << endl;
        gameOver = true; // end game loop
        }

        else if (cpu.currHand.size() + cpu.cardsWon.size() <= 1)
        {
        cout << "The CPU has no Cards.\n"
             << "The CPU forfeits the Game." << endl;
        gameOver = true; // end game loop
        }
    }
    
    // condition that ends the game loop if eihter player has 52 cards &
    // the gmae over loop is true.
    while (((p1.currHand.size() + p1.cardsWon.size()) != 52 
            && (cpu.currHand.size() + cpu.cardsWon.size()) !=52)
            || gameOver == false);

    if (p1.cardsWon.size() + p1.currHand.size() > 4)
    {
        cout << "Congratulations You won the game of WAR" << endl;
    }
    
    else
    {
        cout << "You lost the game of WAR" << endl;        
    
        cout << "This game took " << playCount << " hands to complete." << endl;
        cout << "Thank you for playing war\n";
        cout << "Press Enter to return to main" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //writeScoresToFile();
    }
      
}

void Game::war(Player &p1, Player &cpu, int &playCount)
{
        //Check curHand Size to see if any player still has cards to play with
        shuffleIn(p1, cpu);

        //display war function
        cout << "\t`7MMF'     A     `7MF' db      `7MM''''Mq.    OO\n";
        cout << "\t  `MA     ,MA     ,V  ;MM:       MM   `MM.    88\n";
        cout << "\t   VM:   ,VVM:   ,V  ,V^MM.      MM   ,M9     ||\n";
        cout << "\t    MM.  M' MM.  M' ,M  `MM      MMmmdM9      ||\n";
        cout << "\t    `MM A'  `MM A'  AbmmmqMA     MM  YM.      `'\n";
        cout << "\t     :MM;    :MM;  A'     VML    MM   `Mb.    ''\n";
        cout << "\t      VF      VF .AMA.   .AMMA..JMML. .JMM.   db\n\n";

        cout << "The offerings of war\n";

        for (int i = 0; i < 2; i++)
        {
            cout << "\n.------.\n| **** |\n| **** |"
                "\n| **** |\n| **** |\n`------'\n";
        }
        // 
        Card p1Top = p1.currHand.top();
        Card cpuTop = cpu.currHand.top(); 

        p1.war.push(p1Top);
        cpu.war.push(cpuTop);

        p1.currHand.pop();
        cpu.currHand.pop();

        //Check curHand Size to see if any player still has cards to play with
        shuffleIn(p1, cpu);

        //Facedown need to be pulled off the stack
        p1Top = p1.currHand.top();
        cpuTop = cpu.currHand.top(); 

        p1.war.push(p1Top);
        cpu.war.push(cpuTop);

        p1.currHand.pop();
        cpu.currHand.pop();

        shuffleIn(p1, cpu);

        //This is where the new face up cards are drawn
        p1Top = p1.currHand.top();
        cpuTop = cpu.currHand.top(); 

        //Check curHand Size to see if any player still has cards to play with
        shuffleIn(p1, cpu);

        cout << "Your Card for WAR:\n";
        p1.displayTopCard();
        cout << "VS\n\n";   
        playCount++;
        cout << "Computers Card for WAR:\n";
        cpu.displayTopCard();

        if (p1Top.cPower > cpuTop.cPower)
        {
            cout << "You won the WAR!\nTaking the spoils of WAR.\n";
            cout << "Press Enter to continue\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << string (100, '\n');
            p1.cardsWon.push_back(p1Top);
            p1.cardsWon.push_back(cpuTop);

            while(!p1.war.empty())
            {
                p1.cardsWon.push_back(p1.war.front());
                p1.war.pop();
            }
            
            while(!cpu.war.empty())
            {
                p1.cardsWon.push_back(cpu.war.front());
                cpu.war.pop();
            }

            p1.currHand.pop();
            cpu.currHand.pop();
        }

        else if (cpuTop.cPower > p1Top.cPower)
        {
            cout << "You Lost the WAR!\nCPU takes the spoils of WAR.\n";
            cout << "Press Enter to continue\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << string (100, '\n');

            cpu.cardsWon.push_back(p1Top);
            cpu.cardsWon.push_back(cpuTop);

            while(!p1.war.empty())
            {
                cpu.cardsWon.push_back(p1.war.front());
                p1.war.pop();
            }

            while(!cpu.war.empty())
            {
                cpu.cardsWon.push_back(cpu.war.front());
                cpu.war.pop();
            }

            p1.currHand.pop();
            cpu.currHand.pop();
        }
}

  /****************************************************************************\
  * rules                                                                      *
  * This function will display the rules of the game                           *                                                                           *  
  \****************************************************************************/
void Game::rules()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "The goal is to be the first player to win all 52 cards\n\n"
    "----------------------------THE DEAL----------------------------\n"
    "The deck is divided evenly, with each player receiving 26 cards,\n"
    "dealt one at a time, face down. Anyone may deal first. Each\n"
    "player places their stack of cards face down, in front of\n"
    "them.\n\n"
    "----------------------------THE PLAY----------------------------\n"
    "Each player turns up a card at the same time and the player\n"
    "with the higher card takes both cards and puts them, face down,\n"
    "on the bottom of his stack.\n\n"
    "If the cards are the same rank, it is War. Each player turns up\n"
    "one card face down and one card face up. The player with the\n"
    "higher cards takes both piles (six cards). If the turned-up\n"
    "cards are again the same rank, each player places another card\n"
    "face down and turns another card face up. The player with the\n"
    "higher card takes all 10 cards, and so on.\n\n"
    "-----------------------HOW TO KEEP SCORE-----------------------\n"
    "The game ends when one player has won all the cards.\n\n"
    "Press Enter to return to Main Menu\n\n";
    
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Game::scoreBoard()
{
   // Loop though both maps to display the scores tot he user. 
   // use for each loops to read from the map 
    map<int, int> testScores;
    
    map<int, int>::iterator itr = testScores.begin();
    for(;itr != testScores.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    
    itr = testScores.find(3);
    
    if(itr != testScores.end())
        cout << "Found that thing in the map!" << endl;
    else
        cout << "That thing isnt in the map!" << endl;
   
    string line;
    ifstream scoreB ("scoreBoard.txt");
    if (scoreB.is_open())
    {
        while ( getline (scoreB,line) )
        {
        cout << line << '\n';
        }
        scoreB.close();
    }

    else cout << "Unable to open file";
}

void Game::shuffleIn(Player &p1, Player &cpu)
{
    if (p1.currHand.size() == 0)
    {
        p1.shuffleIn();
    }

   if (cpu.currHand.size() == 0)
    {
       cpu.shuffleIn();
    } 
}

//void checkIfEnough(Player &p1, Player &cpu, bool &gameOver)
//{
//    if (p1.currHand.size() + p1.cardsWon.size() == 2)
//    {
//    cout << "You do not have Cards to go to war with.\n"
//         << "You forfeit the Game." << endl;
//    gameOver = true;
//    }
//
//    else if (cpu.currHand.size() + cpu.cardsWon.size() == 2)
//    {
//    cout << "The CPU has no Cards to go to war with.\n"
//         << "The CPU forfeits the Game." << endl;
//    gameOver = true;
//    } 
//}

void Game::writeScoresToFile()
{
        //----------
    //Check the current playCount to see if it worthy to be enter into the scores
    //myMapLognest.end()
    
    //Check longest
    
    //Check lowest 
}