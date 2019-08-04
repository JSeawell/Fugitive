/***************************************
 
 Name: Jake Seawell
 Date: 11/20/18
 Description:
 This is the class implementation
 file for a class called Armor.
 The Armor class inherits from Space,
 and represents armor on a
 game board in a game called Fugitive.
 
 **************************************/

#ifndef Armor_hpp
#define Armor_hpp

//inherits from:
#include "Space.hpp"


class Armor : public Space
{

protected:
   
    //holds player
    vector <Player> playerVect;
    
    //space number
    int spaceNum;
    
public:
    
    //constructor
    Armor(int r, int c, int num, Space*** board);

    //member functions:
    void addPlayer(Player &p1);
    Player movePlayer(Player &p1);
    int getSpaceNum();
    
};
#endif
