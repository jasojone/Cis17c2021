/* 
 * File:   Game.cpp
 * Author: Jason
 *
 * Created on April 4, 2021, 9:04 PM
 * 
 * Game.cpp will contain the games main loop and all the games functions
 */

#include "Game.h"

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
        cout << string(3, '\n'); //moves menu up a bit from the bottom   
        
        // Takes user input for main menu uses input validation.
        userChoice = readInput(userChoice);

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
                scoreBoard();
                break;
            case 4: // end the game and exit.
                cout << "Thank you for playing!\n";
                break;
        }
    }
}
void Game::gameLoop()
{
    // Deck class instantiation refer to Deck.h for build and implementation.
    Deck gameDeck; 
    // Creating the instance of the player and cpu player, refer to the 
    // Player.h for build and implementation.
    Player p1;
    Player cpu;
    
    // userName holds the username for high scores, the following line will 
    // clear the input buffer and the following will gather the user input
    // for the userName.
    string userName; 
    cout << "Enter your Name:\n";
    cin.ignore();
    getline(cin, userName);
    p1.setName(userName);
    
    int playCount = 0;
    // gameOver bool controls the game over sequence, this is part of the 
    // do while conditions in the game loop.
    bool gameOver = false; 
    

      
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
        cout << "You have " << p1.cardsWon.size()+p1.currHand.size() << " cards total\n";
        cout << "The CPU has " << cpu.cardsWon.size()+cpu.currHand.size() << " cards total\n";
//        cout << "Play count " << playCount << endl;
//        cout << "Your hand in play " << p1.currHand.size() << '\n';
//        cout << "your winnings " << p1.cardsWon.size() << '\n';
//        cout << "CPU's hand in play " << cpu.currHand.size() << '\n';
//        cout << "CPU's winnings " << cpu.cardsWon.size() << '\n';
//        cout << "WAR queue " << p1.war.size() + cpu.war.size() << endl;
//        cout << "Total cards in play " << p1.cardsWon.size()+p1.currHand.size() + cpu.cardsWon.size()+cpu.currHand.size() + p1.war.size() + cpu.war.size() << '\n';
//        cout << "Your Cards" << endl;
//        p1.printHand();
//        cout << "cpu's cards" << endl;
//        cpu.printHand();
        
        // shuffleIn will check currHand Size to see if any player still has 
        // cards on the stack to play with, if not shuffle the cardsWon and 
        // pop them onto the currHand stack for play.
        shuffleIn(p1, cpu);
        
        // Crates a new card instance that is a place holder for the top 
        // card of the current hand in play this will be used to push back 
        // the cards when won. Pulling the card off the deck and putting it 
        // on the table.
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
            // The war queue will hold the face two war cards 
            // and the two face down cards
            // Push the war cards onto the war queue and pop them
            // off the hands to move onto the war offerings
            p1.war.push(p1Top);
            p1.currHand.pop();
            cpu.war.push(cpuTop);
            cpu.currHand.pop();
            
            // condition for war within a war
            while ((p1Top.cPower == cpuTop.cPower) && gameOver == false)
            {
                // temporarily change the top cards to carry on with the war 
                p1Top.cPower = -1;
                cpuTop.cPower = -2;
                
                // check if p1 has enough cards for war
                if (p1.currHand.size() + p1.cardsWon.size() <= 2)
                {
                cout << "You do not have Cards to go to war with.\n"
                     << "You must forfeit the game." << endl;
                gameOver = true; // end game loop
                }

                // check if cpu has enough cards for war
                else if (cpu.currHand.size() + cpu.cardsWon.size() <= 2)
                {
                cout << "The CPU has no Cards to go to war with.\n"
                     << "The CPU must forfeit the Game." << endl;
                gameOver = true; // end game loop
                }
                // call war loop
                if(gameOver == false)
                    war(p1, cpu, playCount);
            }
        }
        
        // check to see if players have cards to play the game
        if (p1.currHand.size() + p1.cardsWon.size() <= 1)
        {
        gameOver = true; // end game loop
        }

        else if (cpu.currHand.size() + cpu.cardsWon.size() <= 1)
        {
        gameOver = true; // end game loop
        }
    }
        
//        if(gameOver == true)
//            cout << "Game should be over!" << endl;
    
    
    // condition that ends the game loop if either player has 52 cards &
    // the game over loop is true.
    while (gameOver == false);

    if (p1.cardsWon.size() + p1.currHand.size() > 4)
    {
        cout << "Congratulations "<< userName << 
                " You won the game of WAR" << endl;
        cout << "This game took " << playCount << " hands to complete." << endl;
        highScores.insert(pair<int,string> (playCount, userName));
        cout << "Thank you for playing WAR\n";
        cout << "Press Enter to return to main" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    else
    {
        cout << "You lost the game of WAR" << endl;        
        cout << "This game took " << playCount << " hands to complete." << endl;
        highScores.insert(pair<int,string> (playCount, userName));
        cout << "Thank you for playing WAR\n";
        cout << "Press Enter to return to main" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //writeScoresToFile();
    }
    writeScoresToFile();      
}

void Game::war(Player &p1, Player &cpu, int &playCount)
{
        // Check current handsSize to see if any player still has cards 
        // to play with if not shuffle the cards won and repopulate 
        // the current hand stack
        shuffleIn(p1, cpu);

        //display war function
        displayWar();

        cout << "The offerings of war\n";
        
        // Two "cards" that will simply just be for display purpose
        for (int i = 0; i < 2; i++)
        {
            cout << "\n.------.\n| **** |\n| **** |"
                "\n| **** |\n| **** |\n`------'\n";
        }

        //Check currHand Size to see if any player still has cards to play with
        shuffleIn(p1, cpu);

        // Facedown will be pulled off the stack and the next cards will be
        // placed on for the next battle
        Card p1Top = p1.currHand.top();
        Card cpuTop = cpu.currHand.top(); 

        // Add the face down cards to the war queue  
        p1.war.push(p1Top);
        cpu.war.push(cpuTop);

        // pop off the face down cards form the current hand 
        p1.currHand.pop();
        cpu.currHand.pop();

        //Check currHand Size to see if any player still has cards to play with 
        shuffleIn(p1, cpu);

        // This is where the new face up cards are drawn to compare and display
        // to settle the war
        p1Top = p1.currHand.top();
        cpuTop = cpu.currHand.top(); 

        //Check curHand Size to see if any player still has cards to play with
        shuffleIn(p1, cpu);

        // print cards for the war
        cout << "Your Card for WAR:\n";
        p1.displayTopCard();
        cout << "VS\n\n";   
        playCount++;
        cout << "The CPU's Card for WAR:\n";
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
  * This function will display the rules of the game                           *
  \****************************************************************************/
void Game::rules()
{
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout <<"-------------------------------THE RULES-------------------------------\n"
    "In the basic game there are two players and you use a standard 52 card\n"
    "pack. Cards rank as usual from high to low: A K Q J T 9 8 7 6 5 4 3 2.\n"
    "Suits are ignored in this game.\n\n"
     
    "--------------------------------THE DEAL--------------------------------\n"
    "Deal out all the cards, so that each player has 26. Players do not look\n"
    "at their cards, but keep them in a packet face down. The object of the\n"
    "game is to win all the cards.\n\n"
            
    "--------------------------------THE PLAY--------------------------------\n"   
    "Both players now turn their top card face up and put them on the table.\n"
    "Whoever turned the higher card takes both cards and adds them (face down)\n"
    "to the bottom of their packet. Then both players turn up their next card\n"
    "and so on. Once a player runs out of cards in their packet they will\n"
    "shuffle the cards won and use them to continue to play.\n\n"
            
    "--------------------------------THE WAR--------------------------------\n"       
    "If the turned up cards are equal there is a war. The tied cards stay on\n"
    "the table and both players play the next card of their pile face down\n"
    "and then another card face-up. Whoever has the higher of the new face-up\n"
    "cards wins the war and adds all six cards face-down to the bottom of\n"
    "their packet. If the new face-up cards are equal as well, the war \n"
    "continues: each player puts another card face-down and one face-up.\n"
    "The war goes on like this as long as the face-up cards continue to be\n"
    "equal. As soon as they are different the player of the higher card wins\n"
    "all the cards in the war.\n\n"
      
    "--------------------------------THE WIN--------------------------------\n"
    "The game continues until one player has all the cards and wins.\n"
    "This can take a long time.\n"
           
    "If you don't have enough cards to complete the war, you lose. If\n"
    "neither player has enough cards, the one who runs out first loses.\n"
    "If both run out simultaneously, it's a draw. Example: Players A and B\n"
    "both play sevens, so there is a war. Each player plays a card face down,\n"
    "but this is player B's last card. Player A wins, since player B does not\n"
    "have enough cards to fight the war.\n\n" 
            
    "--------------------------------SCOREBOARD--------------------------------"
    "The scores will be kept based on play counts regardless of win or loss.\n"
    "There will be two top ten brackets. One for the longest game which took\n"
    "the most hands to complete. And another for the shortest game which took\n"
    "the least amount of hands to top ten least hands to complete a game.\n\n" 
    "Press enter to continue\n" << endl;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Game::scoreBoard()
{
    int count = 0;
    cout << "The Longest High Scores:" << endl;
    for (multimap<int, string>::reverse_iterator itr = highScores.rbegin(); count < 10; itr++, count++)
    {
        cout << "Name: " << itr->second << endl;
        cout << "Score: " << itr->first << endl << endl;
    }
    
    
    count = 0;
    cout << "The Shortest High Scores:" << endl;
    for (multimap<int, string>::iterator itr = highScores.begin(); count < 10; itr++, count++)
    {
        cout << "Name: " << itr->second << endl;
        cout << "Score: " << itr->first << endl << endl;
    }
}

double Game::readInput(int userChoice)
{
    int choice = -1;
    bool valid= false;
    do
    {
        cout << "Select your option \n" << flush;
        cin >> choice;
        if (choice == 1,2,3,4 && cin.good())
        {
            //user input choice was valid
            valid = true;
        }
        else
        {
            //something went wrong, we reset the buffer's state to good
            cin.clear();
            // empty it
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, please select 1-4." << endl;
        }
    } while (!valid);

    return (choice);
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

void Game::readScoresFromFile()
{
    ifstream inFile("scoreBoard.txt");
    
    if(inFile.is_open())
    {
        string curLine;

        while(getline(inFile, curLine))
        {
            int start = 0;
            string del = ",";
            int end = curLine.find(del);        

            int curScore = stoi(curLine.substr(start, end - start));
            start = end + del.size();
            end = curLine.find(del, start);
            string curName = curLine.substr(start, end - start);
            
//            cout << "Test" << endl;
//            cout << curScore << endl;
//            cout << curName << endl;

            //highScore
            pair<int, string> tmp = make_pair(curScore, curName);
            highScores.insert(tmp);        
        }
    }
    else 
    {
        cout << "File is not open." << endl;
    }
    inFile.close();
}


void Game::writeScoresToFile()
{
    ofstream outFile("scoreBoard.txt");
  
    // Execute a loop If file successfully opened
    if (outFile.is_open())
    {
        for(multimap<int, string>::iterator itr = highScores.begin(); itr != highScores.end(); itr++)
        {
            outFile << itr->first << "," << itr->second << endl;
        }
    }
    else
    {
       cout << "File is not open." << endl;
    }
    outFile.close();
}
void Game::displayWar()
{
    cout << "\t`7MMF'     A     `7MF' db      `7MM''''Mq.    OO\n";
    cout << "\t  `MA     ,MA     ,V  ;MM:       MM   `MM.    88\n";
    cout << "\t   VM:   ,VVM:   ,V  ,V^MM.      MM   ,M9     ||\n";
    cout << "\t    MM.  M' MM.  M' ,M  `MM      MMmmdM9      ||\n";
    cout << "\t    `MM A'  `MM A'  AbmmmqMA     MM  YM.      `'\n";
    cout << "\t     :MM;    :MM;  A'     VML    MM   `Mb.    ''\n";
    cout << "\t      VF      VF .AMA.   .AMMA..JMML. .JMM.   db\n\n";
}