/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the header/class specification
 file for a class called FinalGame. The
 FinalGame class represents a game of
 Fugitive, where you are a cop looking
 for an escaped fugitive.
 
 **************************************/

#ifndef FinalGame_hpp
#define FinalGame_hpp

#include "Space.hpp"
#include "Player.hpp"

class FinalGame
{
protected:

    //member variables
    int rows;
    int cols;
    Space*** board;
	int difficulty;

public:
    
    //construcor
    FinalGame();
    //destructor
    ~FinalGame();

    //member functions
    void placePlayer(Player p1);
    void placeFugitive();
    
    //add spaces
    void addCuffs();
    void addLight();
    void addTraps();
    void addArmor();
    
    //other functions
    void linkSpaces();
    void printBoard();
    void printChosenBoard(char chosen);
    void printHiddenBoard();
    void printFlashBoard();
    void playGame();
    
};
#endif
