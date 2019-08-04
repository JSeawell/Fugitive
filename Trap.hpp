/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the class implementation
 file for a class called Trap.
 The Trap class inherits from Space,
 and represents a trap on a
 game board in a game called Fugitive.
 
 **************************************/

#ifndef Trap_hpp
#define Trap_hpp

#include "Space.hpp"


class Trap : public Space
{

protected:
   
    //holds player
    vector <Player> playerVect;
    
    //space number
    int spaceNum;
    
public:
    
    //constructor
    Trap(int r, int c, int num, Space*** board);

    //member functions:
    void addPlayer(Player &p1);
    Player movePlayer(Player &p1);
    int getSpaceNum();
};
#endif
