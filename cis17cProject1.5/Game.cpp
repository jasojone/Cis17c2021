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
            {
                cout << "Lets play WAR!\n";
                gameLoop();
                break;
            }

            case 2: // display the rules.
            {
                rules();
                break;
            }

            case 3: // display the Score Board.
            {
                scoreBoard();
                break;
            }
            case 4: // end the game and exit.
            {
                cout << string(5, '\n');
                cout << "Thank you for playing,\n"<< endl;
                displayWar();
                break;
            }
        }
    }
}

  /****************************************************************************\
  * gameLoop                                                                   *
  * This function holds the game loop and logic for the game. The game loop    *
  * will run on a do while loop with an end of game condition gameover true    *
  \****************************************************************************/
void Game::gameLoop()
{
    // Deck class instantiation refer to Deck.h for build and implementation.
    Deck gameDeck; 
    
    // Creating the instance of the player and cpu player, refer to the 
    // Player.h for build and implementation.
    Player p1;
    Player cpu;
    
    // playCount hold the number of hands played for high scores.
    int playCount = 0;
    
    // gameOver bool controls the game over sequence, this is part of the 
    // do while conditions in the game loop.
    bool gameOver = false; 
    
    // userName holds the username for high scores this will be set to the 
    // playerName private variable in the Player class.
    string userName; 
    
    cout << "Enter your Name:\n";
    // clear the input buffer.
    cin.ignore();
    // gather the user input for the userName.
    getline(cin, userName);
    // use the setter to set name.
    p1.setName(userName);
    
    cout << "Dealing Cards...\n\n";
    
    // dealCards() is called and deal the deck 26 cards to each player.
    gameDeck.dealCards(p1);
    // test by printing the hand to see if there are still 52 individual cards.
    //p1.printHand();

    gameDeck.dealCards(cpu);
    //cpu.printHand();    
    
    cout << "The Battle Begins!\n\n";
   
    // The do while loop is the main game loop that will contain all the game logic. 
    do
    {

        //p1.printHand();
        //cpu.printHand();
        
        countAces(p1);
        // Output the card total for each player.
        cout << "You have " << p1.cardsWon.size()+p1.handInPlay.size() << " cards total\n";
        
        //p1.printHand(); for testing 
        cout << "The CPU has " << cpu.cardsWon.size()+cpu.handInPlay.size() << " cards total\n";
        //cpu.printHand(); for testing 
        // Test counters to work on the game loop. 
        //testCounters(p1, cpu, playCount);
        
        // shuffleIn will check currHand Size to see if any player still has 
        // cards on the stack to play with, if not shuffle the cardsWon and 
        // pop them onto the currHand stack for play.
        playerShuffleIn(p1, cpu);
        
        // Crates a new card instance that is a place holder for the top 
        // card of the current hand in play this will be used to push back 
        // the cards when won. Pulling the card off the deck and putting it 
        // on the table.
        Card p1Top = p1.handInPlay.top();
        Card cpuTop = cpu.handInPlay.top();        

        // This will display the cards in play. 
        cout << "Your Card:\n";
        p1.displayTopCard();
        
        cout << "VS\n"; 
        // count the hand this will be used for the high scores.
        playCount++;
        
        cout << "Computers Card:\n";
        cpu.displayTopCard();
        
        // if player 1's hand is the winning hand.
        if (p1Top.cPower > cpuTop.cPower)
        {
            cout << "You won the round!\n";
            cout << "Press Enter to continue\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Taking your winnings.\n";
            
            // push the cards in play that are won onto the cardsWon pile.
            p1.cardsWon.push_back(p1Top);
            p1.cardsWon.push_back(cpuTop);
            // pop the cards off the hands in play.
            p1.handInPlay.pop();
            cpu.handInPlay.pop();
            // clear the screen.
            cout << string (100, '\n');
        }
        
        // if cpu wins the hand.
        else if (cpuTop.cPower > p1Top.cPower)
        {
            cout << "You lost the round.\n";
            cout << "Press Enter to continue\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "CPU takes the winnings.\n";
            
            // push the cards in play that are won to the cpu cards won pile.
            cpu.cardsWon.push_back(p1Top);
            cpu.cardsWon.push_back(cpuTop);
            // pop the cards off the hands in play.
            p1.handInPlay.pop();
            cpu.handInPlay.pop(); 
            cout << string (100, '\n');         
        }
        
        // if the cards are equal then go to war.
        else
        {   
            // The war queue will hold the face two war cards 
            // and the two face down cards
            // Push the war cards onto the war queue and pop them
            // off the hands to move onto the war offerings
            p1.war.push(p1Top);
            p1.handInPlay.pop();
            cpu.war.push(cpuTop);
            cpu.handInPlay.pop();
            
            // condition for war within a war.
            while ((p1Top.cPower == cpuTop.cPower) && gameOver == false)
            {
                // temporarily change the top cards to carry on with the war
                // by not continuing the while loop. 
                p1Top.cPower = -1;
                cpuTop.cPower = -2;
                
                // check if p1 has enough cards for war.
                if (p1.handInPlay.size() + p1.cardsWon.size() <= 2)
                {
                cout << "You do not have Cards to go to war with.\n" << "You must forfeit the game." << endl;
                gameOver = true; // end game loop.
                }

                // check if cpu has enough cards for war.
                else if (cpu.handInPlay.size() + cpu.cardsWon.size() <= 2)
                {
                cout << "The CPU has no Cards to go to war with.\n" << "The CPU must forfeit the Game." << endl;
                gameOver = true; // end game loop
                }
                // call war loop.
                if(gameOver == false)
                {
                    war(p1, cpu, playCount);
                }
            }
        }
        
        // check to see if players have cards to play the game.
        if (p1.handInPlay.size() + p1.cardsWon.size() <= 1)
        {
        gameOver = true; // end game loop
        }

        else if (cpu.handInPlay.size() + cpu.cardsWon.size() <= 1)
        {
        gameOver = true; // end game loop
        }
    }

    // condition that ends the game loop if either player does not have 
    // enough cards to continue the game over loop is true.
    while (gameOver == false);

    if (p1.cardsWon.size() + p1.handInPlay.size() > 4)
    {
        // print the statistics of the game
        cout << "Congratulations "<< userName << " You won the game of WAR" << endl;
        cout << "This game took " << playCount << " hands to complete." << endl;
        // write the statistics to the multimap that holds the high scores to be 
        // written to the text file.
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
    }
    // calls the function that writes the scores to the text file. 
    writeScoresToFile();      
}

  /****************************************************************************\
  * war                                                                        *
  * This function hold the logic of a war instance. When the cards are equal   * 
  * the war function is called.                                                *
  \****************************************************************************/
void Game::war(Player &p1, Player &cpu, int &playCount)
{
    // Check current handsSize to see if any player still has cards 
    // to play with if not shuffle the cards won and repopulate 
    // the current hand stack
    playerShuffleIn(p1, cpu);

    // display war function
    displayWar();

    cout << "The offerings of war\n";

    // Two "cards" that will simply just be for display purpose
    for (int i = 0; i < 2; i++)
    {
        cout << "\n.------.\n| **** |\n| **** |"
            "\n| **** |\n| **** |\n`------'\n";
    }

    //Check currHand Size to see if any player still has cards to play with
    playerShuffleIn(p1, cpu);

    // Facedown will be pulled off the stack and the next cards will be
    // placed on for the next battle
    Card p1Top = p1.handInPlay.top();
    Card cpuTop = cpu.handInPlay.top(); 

    // Add the face down cards to the war queue  
    p1.war.push(p1Top);
    cpu.war.push(cpuTop);

    // pop off the face down cards form the current hand 
    p1.handInPlay.pop();
    cpu.handInPlay.pop();

    //Check currHand Size to see if any player still has cards to play with 
    playerShuffleIn(p1, cpu);

    // This is where the new face up cards are drawn to compare and display
    // to settle the war
    p1Top = p1.handInPlay.top();
    cpuTop = cpu.handInPlay.top(); 

    // Check curHand Size to see if any player still has cards to play with
    playerShuffleIn(p1, cpu);

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
        // take the winnings from the last play.
        p1.cardsWon.push_back(p1Top);
        p1.cardsWon.push_back(cpuTop);
        // take the winnings from the war queues.
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
        // remove the last cards played.
        p1.handInPlay.pop();
        cpu.handInPlay.pop();
    }

    else if (cpuTop.cPower > p1Top.cPower)
    {
        cout << "You Lost the WAR!\nCPU takes the spoils of WAR.\n";
        cout << "Press Enter to continue\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << string (100, '\n');

        // cpu takes the winnings from the last play.
        cpu.cardsWon.push_back(p1Top);
        cpu.cardsWon.push_back(cpuTop);

        // cpu takes the winnings from the war queues.
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
        // remove the last cards played.
        p1.handInPlay.pop();
        cpu.handInPlay.pop();
    }
}
  /****************************************************************************\
  * readInput                                                                  *
  * Takes the user input and tests it to see if its an integer within range.   *
  * Precondition: int userChoice 0                                             *
  * Postcondition: dependent upon the user input, valid options are 1,2,3,4    *
  \****************************************************************************/
double Game::readInput(int userChoice)
{
    // temporarily set choice to -1
    int choice = -1;
    // do while condition
    bool valid= false;
    
    do
    {
        cout << "Select your option and press enter.\n" << flush;
        cin >> choice;
        // if choice is an integer set loop condition to break and return the 
        // user selection.
        if (choice <=4 && choice > 0 && cin.good())
        {
            //user input choice was valid.
            valid = true;
        }
        else
        {
            //something went wrong, reset the buffer.
            cin.clear();
            // empty it
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, please select 1-4." << endl;
        }
    } while (!valid);

    return (choice);
}

  /****************************************************************************\
  * countAces                                                                  *
  * This function will count the number of aces that the player has. This will *
  * show the player that the aces may not be the determining factor of who     *
  * will win the game of war.                                                  *
  \****************************************************************************/
void Game::countAces(Player p1)
{
    // create a temporary card that will be used for the count algorithm.
    Card tmpCard("CLUBS", 14);
    // the algorithm count was used here to count the number of Aces in the 
    // players cards won. 
    int tmp = count(p1.cardsWon.begin(), p1.cardsWon.end(), tmpCard);
    // then create a temporary stack to hold the actual stack to be used for
    // traversing through to add the aces that are in the hand. 
    stack<Card> tmpStack = p1.handInPlay;
    
    // use of the while loop to traverse through the temp stack and add all
    // the aces held to the count. 
    while (!tmpStack.empty())
    {
        if (tmpStack.top() == tmpCard) tmp++;
        tmpStack.pop();
    }
    // display the total aces at the players disposal.
    cout << "You Have " << tmp << " Aces" << endl;
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
    "This can take a long time. If you don't have enough cards to complete the\n"
    "war, you lose. If neither player has enough cards, the one who runs out\n"
    "first loses. If both run out simultaneously, it's a draw. Example: Players\n"
    "A and B both play sevens, so there is a war. Each player plays a card face\n"
    "down, but this is player B's last card. Player A wins, since player B does\n"
    "not have enough cards to fight the war.\n\n" 
            
    "--------------------------------SCOREBOARD--------------------------------\n"
    "The scores will be kept based on play counts regardless of win or loss.\n"
    "There will be two top ten brackets. One for the longest game which took\n"
    "the most hands to complete. And another for the shortest game which took\n"
    "the least amount of hands to top ten least hands to complete a game.\n\n" 
    "Press enter to continue\n" << endl;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

  /****************************************************************************\
  * compMap                                                                    *
  * This function will compare two pairs and return the result of the smaller  *
  * of the two                                                                 *
  \****************************************************************************/
bool compMap(pair<int,string> a, pair<int,string> b)
{
    return a.first < b.first;
}

  /****************************************************************************\
  * scoreBoard                                                                 *
  * This function will display the rules of the game                           *
  \****************************************************************************/
void Game::scoreBoard()
{
    cout << string (100, '\n');
    
    // declare two maps that will be used to implement the max and min algorithm
    // two iterators that are being used are bidirectional and the compMap function
    pair<int, string> max = *max_element(highScores.begin(),highScores.end(), compMap);
    pair<int, string> min = *min_element(highScores.begin(),highScores.end(), compMap);
    cout << "The Hall of Fame:" << endl;
    cout << "Longest Game of all Time" << endl;
    // print the name ans the score
    cout << max.second << ": "<< max.first << endl << endl;
    cout << "Shortest Game of all Time" << endl;
    cout << min.second << ": "<< min.first << endl << endl;
    
    int count = 0;
    cout << "The 10 Longest Games:" << endl;
    // The for loop will traverse the list from the end of the list to a count 
    // of 10 this will display the top ten highest hand count games. In order 
    // to do this a reverse_iterator is used to start at the end of the multi map.
    for (multimap<int, string>::reverse_iterator itr = highScores.rbegin(); count < 10; itr++, count++)
    {
        cout << "Name: " << itr->second << endl;
        cout << "Score: " << itr->first << endl << endl;
    }
    
    count = 0;
    cout << "The 10 Shortest Games:" << endl;
    // The for loop will traverse the list from the beginning of the list to a count 
    // of 10 this will display the top ten lowest hand count games. In order 
    // to do this a iterator is used to start at the beginning of the multi map.
    for (multimap<int, string>::iterator itr = highScores.begin(); count < 10; itr++, count++)
    {
        cout << "Name: " << itr->second << endl;
        cout << "Score: " << itr->first << endl << endl;
    }

}


  /****************************************************************************\
  * playerShuffleIn 
  * This function is called periodically in the game to check if the player/cpu*
  * has depleted the cards in their hand in play. If the stack in play is      *
  * empty the function calls shuffle in (part of the Player class) which       *
  * shuffles the cards won pile and moves it to the hand in play.              *
  * Precondition: hand in play state                                           *
  * Postcondition: if hand in play is not 0 same, otherwise repopulates the    *
  * hand in play with cards won shuffled.                                      *
  \****************************************************************************/
void Game::playerShuffleIn(Player &p1, Player &cpu)
{
    // if player hand is 0 call shuffleIn
    if (p1.handInPlay.size() == 0)
    {
        p1.shuffleIn();
    }

   // if cpu hand is 0 call shuffleIn
   if (cpu.handInPlay.size() == 0)
    {
       cpu.shuffleIn();
    } 
}

  /****************************************************************************\
  * readScoresFromFile                                                         *
  * This function is called when the user selects the score board option on    *
  * the main menu. When called it will read the contents from the save file    *
  * and populate the high scores multimap                                      *
  \****************************************************************************/
void Game::readScoresFromFile()
{
    ifstream inFile("scoreBoard.txt");
    
    if(inFile.is_open())
    {
        // Holds the line being processed from the file.
        string curLine;
        
        // traverses the file getting one line at a time until reaching the end.
        while(getline(inFile, curLine))
        {
            // points to the current char of the current line.
            int start = 0;
            
            // sets the stop at the comma 
            string del = ",";
            
            // finds the location of the comma
            int end = curLine.find(del);  
            
            // turns the string (score) back into an int, then creates a 
            // substring from start to comma.
            int curScore = stoi(curLine.substr(start, end - start));
            // moves the start to the char after the comma (name)
            start = end + del.size();
            
            // the new end will look for another comma
            end = curLine.find(del, start);
            
            // fills the name using the subsrting from the new start location to
            // the end of the line. 
            string curName = curLine.substr(start, end - start);
            
            // Populate the map from the files saved scores.
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

  /****************************************************************************\
  * writeScoresFromFile                                                        *
  * This function is called when a game has ended and a new score needs to be  * 
  * saved.                                                                     *
  \****************************************************************************/
void Game::writeScoresToFile()
{
    ofstream outFile("scoreBoard.txt");
  
    // Execute a loop If file successfully opened
    if (outFile.is_open())
    {
        // using an iterator here to traverser though the map in its entirety  to write the 
        // scores to the text file. 
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

  /****************************************************************************\
  * displayWar                                                                 *
  * This function will simply display the word war this is used in the welcome *
  * message and the war game loop.                                             *  
  \****************************************************************************/
void Game::displayWar()
{
    cout << "\t`7MMF'     A     `7MF' db      `7MM''''Mq.    \n";
    cout << "\t  `MA     ,MA     ,V  ;MM:       MM   `MM.    \n";
    cout << "\t   VM:   ,VVM:   ,V  ,V^MM.      MM   ,M9     \n";
    cout << "\t    MM.  M' MM.  M' ,M  `MM      MMmmdM9      \n";
    cout << "\t    `MM A'  `MM A'  AbmmmqMA     MM  YM.      \n";
    cout << "\t     :MM;    :MM;  A'     VML    MM   `Mb.    \n";
    cout << "\t      VF      VF .AMA.   .AMMA..JMML. .JMM.   \n\n";
}

  /****************************************************************************\
  * displayWelcome                                                             *
  * This function will simply display the welcome screen and message.          *  
  \****************************************************************************/
void Game::displayWelcome()
{
    cout << string(50, '\n');
    cout <<"`7MMF'     A     `7MF'     `7MM                                                  mm                 \n";
    cout <<"  `MA     ,MA     ,V         MM                                                  MM                 \n";
    cout <<"   VM:   ,VVM:   ,V .gP\"Ya   MM  ,p6\"bo   ,pW\"Wq.`7MMpMMMb.pMMMb.  .gP\"Ya      mmMMmm ,pW\"Wq.  \n"; 
    cout <<"    MM.  M' MM.  M',M'   Yb  MM 6M'  OO  6W'   `Wb MM    MM    MM ,M'   Yb       MM  6W'   `Wb      \n";
    cout <<"    `MM A'  `MM A' 8M''''''  MM 8M       8M     M8 MM    MM    MM 8M''''''       MM  8M     M8      \n";
    cout <<"     :MM;    :MM;  YM.    ,  MM YM.    , YA.   ,A9 MM    MM    MM YM.    ,       MM  YA.   ,A9      \n";
    cout <<"      VF      VF    `Mbmmd'.JMML.YMbmd'   `Ybmd9'.JMML  JMML  JMML.`Mbmmd'       `Mbmo`Ybmd9'       \n";
    this_thread::sleep_for (chrono::seconds(1));
    cout << string(100, '\n');

    displayWar();
    this_thread::sleep_for (chrono::seconds(1));
    cout << string(100, '\n');

    cout << "\t  mm   `7MM                  \n";
    cout << "\t  MM     MM                  \n";
    cout << "\tmmMMmm   MMpMMMb.  .gP\"Ya   \n";
    cout << "\t  MM     MM    MM ,M'   Yb   \n";
    cout << "\t  MM     MM    MM 8M''''''   \n";
    cout << "\t  MM     MM    MM YM.    ,   \n";
    cout << "\t  `Mbmo.JMML  JMML.`Mbmmd'   \n\n";

    cout << "   .g8'''bgd                      `7MM      .g8'''bgd       \n";
    cout << " .dP'     `M                        MM    .dP'     `M       \n";
    cout << " dM'       ` ,6'Yb.  `7Mb,od8  ,M''bMM    dM'       `  ,6\"Yb. `7MMpMMMb.pMMMb.  .gP\"Ya  \n";
    cout << " MM         8)   MM    MM' \"',AP    MM    MM          8)   MM   MM    MM    MM ,M'   Yb  \n";
    cout << " MM.         ,pm9MM    MM    8MI    MM    MM.    `7MMF',pm9MM    MM    MM    MM 8M''''''  \n";
    cout << " `Mb.     ,'8M   MM    MM    `Mb    MM    `Mb.     MM 8M   MM    MM    MM    MM YM.    ,  \n";
    cout << "   `''bmmmd' `Moo9^Yo..JMML.   `Wbmd'MML. `''bmmmdPY  `Moo9^Yo..JMML  JMML  JMML.`Mbmmd'  \n\n";
    this_thread::sleep_for (chrono::seconds(1));
    cout << string(100, '\n');
}
  /****************************************************************************\
  * testCounters                                                               *
  * This function is called to test the specific number of cards each container*
  * has. This was used for testing to validate the game loop logic.            *
  \****************************************************************************/
void testCounters(int playCount, Player p1, Player cpu)
{
        // print play count
        cout << "Play count " << playCount << endl;
        // print card count held in player's stack in play.
        cout << "Your hand in play " << p1.handInPlay.size() << '\n';
        // print the card count in player's pile of won cards.
        cout << "your winnings " << p1.cardsWon.size() << '\n';
        // print card count held in cpu's stack in play.
        cout << "CPU's hand in play " << cpu.handInPlay.size() << '\n';
        // print the card count in cpu's pile of won cards.
        cout << "CPU's winnings " << cpu.cardsWon.size() << '\n';
        // print the card count in the war queue.
        cout << "WAR queue " << p1.war.size() + cpu.war.size() << endl;
        // add all the cards up and print them.
        cout << "Total cards in play " << p1.cardsWon.size()+p1.handInPlay.size() + cpu.cardsWon.size()+cpu.handInPlay.size() + p1.war.size() + cpu.war.size() << '\n';
        // print the suit, value and ascii art for all card held by player. 
        cout << "Your Cards" << endl;
        p1.printHand();
        // print the suit, value and ascii art for all card held by cpu. 
        cout << "cpu's cards" << endl;
        cpu.printHand();   
}