/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the main function for running/
 testing a game called Fugitive.
 
 **************************************/

//files needed
#include "FinalGame.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "choiceFunction.hpp"
#include "intVal.hpp"

//libraries needed
#include <time.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

main()
{

    //menu function
    int playOrNaw;
    playOrNaw = choiceFunction("::FUGITIVE:", "Play game", "Quit");
    if (playOrNaw == 1)
    {
        //game intro/instructions
        cout << endl << "Welcome to Fugitive!" << endl << endl;
        cout << "You are an officer of the streets, and you just received word that a fugitive has escaped custody, and is on the loose." << endl <<endl;
        cout << "There's no time to call for back-up, so it's up to you to catch the fugitive. Be careful, Officer, this one is armed and dangerous!" << endl << endl;
        cout << "The fugitive is hiding somewhere nearby! Can you find them in time?" << endl << endl;
        cout << "Collect items as you go, and store them on your utility belt. However, you can only hold 2 items at a time, so choose carefully." << endl << endl;
	
	cout << "The map/search area may display the following symbols:" << endl << endl;  
	cout << "People:" << endl << "You (P), Fugitive (F)" << endl;
	cout << "Items:" << endl << "Handcuffs (C) give you the ability to capture the fugitive and win." << endl;
	cout << "Flashlight (L) gives you ability to see the spaces around you, even in the dark." << endl;
	cout << "Boobie-Traps (T) hurt you if you run into them. Don't spring too many!" << endl;
	cout << "Body armor (A) protects you from recieving damage. It also freezes time (but not the fugitive)" << endl; 
	cout << "for ten minutes, while you are wearing it." << endl << endl;
        cout << "One last thing - you seemed to have dropped your handcuffs along the way, and you'll need them for this fugitive." << endl << endl;
        cout << "Don't try to make an arrest without them, or you may be in for a long night." << endl << endl;
        cout << "Good Luck, Officer, and hurry - you're running out of time! (each step you make takes 1 minute)" << endl << endl;

	cout << "Press enter to continue." << endl;
	cin.ignore();

	cout << "\033[2J";


	//cout << endl << endl << endl << endl << endl << endl << endl << endl;
	//cout << endl << endl << endl << endl << endl << endl << endl << endl;
	
	cout << endl << "How to move:" << endl << endl;
	
	cout << "In this game, you will move one step at a time." << endl;
	cout << "Each move, you will be able to move in any direction, including diagonally." << endl;
	cout << "The following diagram represents your options:" << endl;

	cout << endl << "7|8|9" << endl;
        cout << "-----" << endl;
        cout << "4| |6" << endl;
        cout << "-----" << endl;
        cout << "1|2|3" << endl << endl;


	cout << "The blank space in the middle (where 5 is missing), represents your current position." << endl;
	cout << "To move in the following directions, press the corresponding #, and press enter." << endl;
	cout << "up-left: 7" << endl << "up: 8" << endl << "up-right: 9" << endl << "left: 4" << endl;
	cout << "right: 6" << endl << "down-right: 3" << endl << "down: 2" << endl << "down-left: 1" << endl;	

        //rand seed for all rand functions
        srand(time(0));

	int playAgain = 0;
	do
	{

        //create game
        FinalGame FG1;
        //play game
        FG1.playGame();
	
 	cout << endl << "Would you like to play again?" << endl;
	cout << "1: Yes, play again" << endl << "2: No, quit" << endl;
	playAgain = minMaxValidation(integerValidation(),1,2);

	} while (playAgain == 1);
	cout << endl << "Thanks for playing!" << endl << endl; 
    }
    else
        //quit statement
        cout << endl << "Program ended." << endl << endl;

}
