/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the class implementation
 file for a class called Flashlight.
 The Flashlight class inherits from Space,
 and represents a flashlight on a
 game board in a game called Fugitive.
 
 **************************************/

#ifndef Flashlight_hpp
#define Flashlight_hpp

#include "Space.hpp"


class Flashlight : public Space
{

protected:
   
    //holds player
    vector <Player> playerVect;
    
    //set space number
    int spaceNum;
    
public:
    
    //constructor
    Flashlight(int r, int c, int num, Space*** board);

    //member functions:
    void addPlayer(Player &p1);
    Player movePlayer(Player &p1);
    int getSpaceNum();
};
#endif
